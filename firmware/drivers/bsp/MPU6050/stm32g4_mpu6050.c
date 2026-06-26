/**
 *******************************************************************************
 * @file 	stm32g4_mpu6050.c
 * @author 	Tilen Majerle (2014) (cf license ci dessous)
 * @author  Samuel Poiraud (2016) -> portage STM32F1 et modifications pour les activitÃ©s pÃ©dagogiques Ã  l'ESEO.
 * @author	vchav (2024) -> portage sur STM32G4
 * @date 	May 6, 2024
 * @brief	Module pour utiliser le capteur MPU6050.
 *******************************************************************************
 * @verbatim--------------------------------------------------------------
 * | Copyright (C) Tilen Majerle, 2014
 * |
 * | This program is free software: you can redistribute it and/or modify
 * | it under the terms of the GNU General Public License as published by
 * | the Free Software Foundation, either version 3 of the License, or
 * | any later version.
 * |
 * | This program is distributed in the hope that it will be useful,
 * | but WITHOUT ANY WARRANTY; without even the implied warranty of
 * | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * | GNU General Public License for more details.
 * |
 * | You should have received a copy of the GNU General Public License
 * | along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * |-----------------------------------------------------------@endverbatim
 */

/*
 * Driver fourni pour l'accÃ©lÃ©romÃ¨tre-gyroscope MPU6050.
 * Brochage proposÃ© par dÃ©faut :
 *
 *  Par dÃ©faut, les broches utilisÃ©es sont celles de l'I2C1 :
 *  		- SCL : PA15
 *  		- SDA : PB7
 *  		- Vcc : PA0 par exemple (cf MPU6050_Init) !!! (ce qui permet au pilote de couper l'alimentation et provoquer un reset).
 *  		- GND : GND de la carte
 *
 * Le basculement sur l'I2C2 ou l'I2C3 est possible en redÃ©finissant MPU6050_I2C = I2C2 ou I2C3
 * I2C2: PA9 pour SCL et PF0 pour SDA   ----+
 * I2C3: PA8 pour SCL et PB5 pour SDA		|
 * 											|
 *											V
 * +------------------------------------------------------------------------------------------------------------------------------
 * | Pour l'I2C2:
 * | /!\ Le PF0 n'est disponible que si SB8 est soudÃ© et pas SB13 (petits pads sur la carte stm32g431) /!\
 * | Pour mieux comprendre la manipulation Ã  faire pour dÃ©bloquer PF0, je vous renvoie Ã  la documentation page 4: https://www.st.com/content/ccc/resource/technical/layouts_and_diagrams/schematic_pack/group1/f5/e0/9b/fb/40/5f/43/b3/MB1430-G431KBT6-A02_Schematic_Internal/files/MB1430-G431KBT6-A02_Schematic_Internal.pdf/jcr:content/translations/en.MB1430-G431KBT6-A02_Schematic_Internal.pdf
 * +------------------------------------------------------------------------------------------------------------------------------
 *
 */

/* Includes ------------------------------------------------------------------*/
#include "config.h"
#if USE_MPU6050
#include "stm32g4_i2c.h"
#include "stm32g4_mpu6050.h"
#include "stm32g4_gpio.h"
#include <stdio.h>

/**
 * @brief	Initialise le module MPU6050 en activant son alimentation, puis en configurant les registres internes du MPU6050.
 * @param	GPIOx et GPIO_PIN_x : indiquent la broche oÃ¹ l'on a reliÃ© l'alimentation Vcc du MPU6050.
 * 			Indiquer NULL dans GPIOx s'il est alimentÃ© en direct.
 * 			Cette possibilitÃ© d'alimentation par la broche permet le reset du module par le microcontrÃ´leur.
 * @param	DataStruct : fournir le pointeur vers une structure qui sera Ã  conserver pour les autres appels des fonctions de ce module logiciel.
 * @param 	DeviceNumber : 					voir MPU6050_Device_t
 * @param	AccelerometerSensitivity : 		voir MPU6050_Accelerometer_t
 * @param	GyroscopeSensitivity :			voir MPU6050_Gyroscope_t
 */



int16_t accX_data[MPU6050_RECORDING_SIZE];
int16_t accY_data[MPU6050_RECORDING_SIZE];
int16_t accZ_data[MPU6050_RECORDING_SIZE];

MPU6050_Result_t MPU6050_Init(MPU6050_t* DataStruct, GPIO_TypeDef * GPIOx, uint16_t GPIO_PIN_x, MPU6050_Device_t DeviceNumber, MPU6050_Accelerometer_t AccelerometerSensitivity, MPU6050_Gyroscope_t GyroscopeSensitivity)
{
	uint8_t temp;

	if(GPIOx != NULL)
	{
		BSP_GPIO_pin_config(GPIOx, GPIO_PIN_x,GPIO_MODE_OUTPUT_PP,GPIO_PULLUP,GPIO_SPEED_FREQ_HIGH, GPIO_NO_AF);
		HAL_GPIO_WritePin(GPIOx,GPIO_PIN_x,GPIO_PIN_SET);
	}
	HAL_Delay(20);

	/* Formate l'addresse de l'I2C */
	DataStruct->Address = MPU6050_I2C_ADDR | (uint8_t)DeviceNumber;

	/* Initialise l'I2C */
	BSP_I2C_Init(MPU6050_I2C, STANDARD_MODE, true);

	/* On vÃ©rifie que le capteur est bien connectÃ© */
	if (!BSP_I2C_IsDeviceConnected(MPU6050_I2C, DataStruct->Address)) {
		/* Return error */
		return MPU6050_Result_DeviceNotConnected;
	}

	/* Check le "who I am" */
	uint8_t i_am;
	BSP_I2C_Read(MPU6050_I2C, DataStruct->Address, MPU6050_WHO_AM_I, &i_am);
	if (i_am != MPU6050_I_AM && i_am != MPU9250_I_AM && i_am != MPU9255_I_AM && i_am != MPU6060_I_AM_STRANGE_MODEL) {
		/* Return error */
		return MPU6050_Result_DeviceInvalid;
	}

	/* On rÃ©veil le MPU6050 */
	BSP_I2C_Write(MPU6050_I2C, DataStruct->Address, MPU6050_PWR_MGMT_1, 0x00);

	/* On config l'accÃ©lÃ©romÃ¨tre */
	BSP_I2C_Read(MPU6050_I2C, DataStruct->Address, MPU6050_ACCEL_CONFIG, &temp);
	temp = (temp & 0xE7) | (uint8_t)AccelerometerSensitivity << 3;
	BSP_I2C_Write(MPU6050_I2C, DataStruct->Address, MPU6050_ACCEL_CONFIG, temp);

	/* On config le gyroscope */
	BSP_I2C_Read(MPU6050_I2C, DataStruct->Address, MPU6050_GYRO_CONFIG, &temp);
	temp = (temp & 0xE7) | (uint8_t)GyroscopeSensitivity << 3;
	BSP_I2C_Write(MPU6050_I2C, DataStruct->Address, MPU6050_GYRO_CONFIG, temp);

	/* On dÃ©finie les sensiblitÃ©s pour multiplier les donnÃ©es du gyroscope et de l'accÃ©lÃ©romÃ¨tre */
	switch (AccelerometerSensitivity) {
		case MPU6050_Accelerometer_2G:
			DataStruct->Acce_Mult = (float)1 / MPU6050_ACCE_SENS_2;
			break;
		case MPU6050_Accelerometer_4G:
			DataStruct->Acce_Mult = (float)1 / MPU6050_ACCE_SENS_4;
			break;
		case MPU6050_Accelerometer_8G:
			DataStruct->Acce_Mult = (float)1 / MPU6050_ACCE_SENS_8;
			break;
		case MPU6050_Accelerometer_16G:
			DataStruct->Acce_Mult = (float)1 / MPU6050_ACCE_SENS_16;
			//no break
		default:
			break;
	}

	switch (GyroscopeSensitivity) {
		case MPU6050_Gyroscope_250s:
			DataStruct->Gyro_Mult = (float)1 / MPU6050_GYRO_SENS_250;
			break;
		case MPU6050_Gyroscope_500s:
			DataStruct->Gyro_Mult = (float)1 / MPU6050_GYRO_SENS_500;
			break;
		case MPU6050_Gyroscope_1000s:
			DataStruct->Gyro_Mult = (float)1 / MPU6050_GYRO_SENS_1000;
			break;
		case MPU6050_Gyroscope_2000s:
			DataStruct->Gyro_Mult = (float)1 / MPU6050_GYRO_SENS_2000;
			// no break
		default:
			break;
	}

	/* Return OK */
	return MPU6050_Result_Ok;
}

/**
 * @brief Tout est dans le nom de la fonction
 * @param DataStruct: pointeur vers la structure oÃ¹ vont Ãªtre stockÃ©es les donnÃ©es
 * @return Message de rÃ©ussite de l'opÃ©ration
 */
MPU6050_Result_t MPU6050_ReadAccelerometer(MPU6050_t* DataStruct) {
	uint8_t data[6];
	BSP_I2C_ReadMulti(MPU6050_I2C, DataStruct->Address, MPU6050_ACCEL_XOUT_H, data, 6);

	/* On met au bon format */
	DataStruct->Accelerometer_X = (int16_t)(data[0] << 8 | data[1]);
	DataStruct->Accelerometer_Y = (int16_t)(data[2] << 8 | data[3]);
	DataStruct->Accelerometer_Z = (int16_t)(data[4] << 8 | data[5]);

	return MPU6050_Result_Ok;
}

/**
 * @brief Tout est dans le nom de la fonction
 * @param DataStruct: pointeur vers la structure oÃ¹ vont Ãªtre stockÃ©es les donnÃ©es
 * @return Message de rÃ©ussite de l'opÃ©ration
 */
MPU6050_Result_t MPU6050_ReadGyroscope(MPU6050_t* DataStruct) {
	uint8_t data[6];
	BSP_I2C_ReadMulti(MPU6050_I2C, DataStruct->Address, MPU6050_GYRO_XOUT_H, data, 6);

	/* On met au bon format */
	DataStruct->Gyroscope_X = (int16_t)(data[0] << 8 | data[1]);
	DataStruct->Gyroscope_Y = (int16_t)(data[2] << 8 | data[3]);
	DataStruct->Gyroscope_Z = (int16_t)(data[4] << 8 | data[5]);

	return MPU6050_Result_Ok;
}

/**
 * @brief Tout est dans le nom de la fonction
 * @param DataStruct: pointeur vers la structure oÃ¹ vont Ãªtre stockÃ©es les donnÃ©es
 * @return Message de rÃ©ussite de l'opÃ©ration
 */
MPU6050_Result_t MPU6050_ReadTemperature(MPU6050_t* DataStruct) {
	uint8_t data[2];
	int16_t temp;
	BSP_I2C_ReadMulti(MPU6050_I2C, DataStruct->Address, MPU6050_TEMP_OUT_H, data, 2);

	/* On met au bon format */
	temp = (int16_t)(data[0] << 8 | data[1]);
	DataStruct->Temperature = (float)((int16_t)temp / (float)340.0 + (float)36.53);

	return MPU6050_Result_Ok;
}

/**
 * @brief Tout est dans le nom de la fonction
 * @param DataStruct: pointeur vers la structure oÃ¹ vont Ãªtre stockÃ©es les donnÃ©es
 * @return Message de rÃ©ussite de l'opÃ©ration
 */
MPU6050_Result_t MPU6050_ReadAll(MPU6050_t* DataStruct) {
	uint8_t data[14];
	int16_t temp;

	/* On lit toute la ligne de donnÃ©es, 14bytes */
	BSP_I2C_ReadMulti(MPU6050_I2C, DataStruct->Address, MPU6050_ACCEL_XOUT_H, data, 14);

	/* On met au bon format et on remplie la structure*/
	DataStruct->Accelerometer_X = (int16_t)(data[0] << 8 | data[1]);
	DataStruct->Accelerometer_Y = (int16_t)(data[2] << 8 | data[3]);
	DataStruct->Accelerometer_Z = (int16_t)(data[4] << 8 | data[5]);

	temp = (int16_t)(data[6] << 8 | data[7]);
	DataStruct->Temperature = (float)((float)((int16_t)temp) / (float)340.0 + (float)36.53);

	DataStruct->Gyroscope_X = (int16_t)(data[8] << 8 | data[9]);
	DataStruct->Gyroscope_Y = (int16_t)(data[10] << 8 | data[11]);
	DataStruct->Gyroscope_Z = (int16_t)(data[12] << 8 | data[13]);

	return MPU6050_Result_Ok;
}

/**
 * @brief Fonction de dÃ©mo pour prendre en main le capteur rapidement.
 * @pre /!\ Cette fonction est blocante /!\
 */
void MPU6050_demo(void){

	MPU6050_t MPU6050_Data;
	int32_t gyro_x = 0;
	int32_t gyro_y = 0;
	int32_t gyro_z = 0;

	/* Initialise le MPU6050 */
	if (MPU6050_Init(&MPU6050_Data, GPIOA, GPIO_PIN_0, MPU6050_Device_0, MPU6050_Accelerometer_8G, MPU6050_Gyroscope_2000s) != MPU6050_Result_Ok) {
		/*
		// Affiche error avec le debug_printf
		debug_printf("MPU6050 Error\n");
		*/

		// Affiche error avec l'UART
		printf("MPU6050 Error\n");

		// Boucle infinie
		while (1);
	}
	while (1) {
		// On
		MPU6050_ReadAll(&MPU6050_Data);

		gyro_x += MPU6050_Data.Gyroscope_X;
		gyro_y += MPU6050_Data.Gyroscope_Y;
		gyro_z += MPU6050_Data.Gyroscope_Z;
		/*
		// Affiche avec le debug_printf
		debug_printf("AX%4d\tAY%4d\tAZ%4d\tGX%4d\tGY%4d\tGZ%4d\tgx%4ld\tgy%4ld\tgz%4ld\tT%3.1f\n",
						MPU6050_Data.Accelerometer_X/410,	//environ en %
						MPU6050_Data.Accelerometer_Y/410,	//environ en %
						MPU6050_Data.Accelerometer_Z/410,	//environ en %
						MPU6050_Data.Gyroscope_X,
						MPU6050_Data.Gyroscope_Y,
						MPU6050_Data.Gyroscope_Z,
						gyro_x/16400,						//environ en Â°
						gyro_y/16400,						//environ en Â°
						gyro_z/16400,						//environ en Â°
						MPU6050_Data.Temperature);

		*/
		 // Affiche avec l'UART
		//printf("AX%4d\t AY%4d\t AZ%4d\tGX%4d\tGY%4d\tGZ%4d\tgx%4ld\tgy%4ld\tgz%4ld\tT%3d\n",
			            //(uint16_t)MPU6050_Data.Accelerometer_X/410,	//environ en %
				        //(uint16_t)MPU6050_Data.Accelerometer_Y/410,	//environ en %
					    //(uint16_t)MPU6050_Data.Accelerometer_Z/410,	//environ en %
					    //(uint16_t)MPU6050_Data.Gyroscope_X,
					    //(uint16_t)MPU6050_Data.Gyroscope_Y,
					    //(uint16_t)MPU6050_Data.Gyroscope_Z,
						//(uint32_t)gyro_x/16400,						//environ en Â°
						//(uint32_t)gyro_y/16400,						//environ en Â°
						//(uint32_t)gyro_z/16400,						//environ en Â°
						//(uint16_t)MPU6050_Data.Temperature);

		 printf("AX %4d \t AY %4d \t AZ %4d \n",
				 	 	(uint16_t)MPU6050_Data.Accelerometer_X / 16384,
						(uint16_t)MPU6050_Data.Accelerometer_Y / 16384,
						(uint16_t)MPU6050_Data.Accelerometer_Z / 16384 );


		// Un petit dÃ©lai pour Ã©viter d'avoir un raz-de-marÃ©e d'information
		HAL_Delay(100);
	}
}


/**
 * @brief Enregistre une séquence de 1200 échantillons d'accélération et les affiche au format MATLAB
 * @param DataStruct Pointeur vers la structure MPU6050_t contenant les données du capteur
 * @pre Le capteur MPU6050 doit être initialisé et fonctionnel
 * @pre DataStruct ne doit pas être NULL
 * @post Les données d'accélération sont acquises et affichées au format MATLAB
 * @return Aucun retour (fonction void)
 *
 * Cette fonction effectue l'acquisition de 1200 échantillons d'accélération sur les trois axes
 * et les affiche dans un format compatible MATLAB. En mode test, elle affiche également
 * une barre de progression et des messages informatifs.
 */
void MPU6050_recording(MPU6050_t* DataStruct){
	// Tableaux pour stocker les 1200 échantillons de chaque axe
	int16_t accX_data[MPU6050_RECORDING_SIZE];
	int16_t accY_data[MPU6050_RECORDING_SIZE];
	int16_t accZ_data[MPU6050_RECORDING_SIZE];
	int n = 1 ;
	if(MPU6050_TEST_MODE)
	{
		printf("recording operation working \n");
		printf("[");

		for (int i = 0; i < MPU6050_RECORDING_SIZE; i++) {
		    MPU6050_ReadAll(DataStruct);
		    accX_data[i] = DataStruct->Accelerometer_X;
		    accY_data[i] = DataStruct->Accelerometer_Y;
		    accZ_data[i] = DataStruct->Accelerometer_Z;
		    // Affichage de la barre de progression
		    while(n > (MPU6050_RECORDING_SIZE/MPU6050_CHARGING_BARE_SIZE) ){
		    	printf("#");
		    	n = 0;
		    }
		    n++;
		    HAL_Delay(MPU6050_RECORDING_SIZE);
		}
		printf("]");
		printf("recording finish \n");
		debug_printf("AccX;AccY;AccZ\n");

	}
	// Affichage des données au format MATLAB
	printf("acc = [\n");
	for (int i = 0; i < MPU6050_RECORDING_SIZE; i++) {
		printf("%d\t%d\t%d;\n", accX_data[i], accY_data[i], accZ_data[i]);
	}
	printf("];\n");
}

/**
 * @brief Calcule la norme euclidienne des vecteurs d'accélération
 * @param accX Tableau des valeurs d'accélération sur l'axe X
 * @param accY Tableau des valeurs d'accélération sur l'axe Y
 * @param accZ Tableau des valeurs d'accélération sur l'axe Z
 * @param accNorm Tableau de sortie contenant les normes calculées
 * @param len Nombre d'échantillons à traiter
 * @pre Les tableaux d'entrée et de sortie doivent être alloués avec au moins 'len' éléments
 * @pre len doit être supérieur à 0
 * @post Le tableau accNorm contient les normes euclidiennes calculées
 * @return Aucun retour (fonction void)
 *
 * Cette fonction calcule la norme euclidienne de chaque vecteur d'accélération 3D
 * selon la formule : norm = sqrt(x² + y² + z²)
 */
void compute_acc_norm(const int16_t *accX, const int16_t *accY, const int16_t *accZ, float *accNorm, uint16_t len) {
    for (uint16_t i = 0; i < len; i++) {
        float x = (float)accX[i];
        float y = (float)accY[i];
        float z = (float)accZ[i];
        // Calcul de la norme euclidienne
        accNorm[i] = sqrtf(x * x + y * y + z * z);
    }
}

/**
 * @brief Applique un filtre passe-bande sur le signal d'entrée
 * @param signal Tableau du signal d'entrée à filtrer
 * @param filtered Tableau de sortie contenant le signal filtré
 * @param len Nombre d'échantillons à traiter
 * @pre Les tableaux signal et filtered doivent être alloués avec au moins 'len' éléments
 * @pre len doit être supérieur à 0
 * @post Le tableau filtered contient le signal après application du filtre passe-bande
 * @return Aucun retour (fonction void)
 *
 * Cette fonction implémente un filtre passe-bande IIR du second ordre
 * avec les coefficients prédéfinis pour isoler les fréquences caractéristiques
 * de la marche humaine (typiquement entre 0.5 et 3 Hz).
 */
void bandpass_filter(const float *signal, float *filtered, uint16_t len) {
    // Coefficients du filtre IIR du second ordre
    const float a1 = -1.7786f, a2 = 0.8008f;
    const float b0 = 0.0675f, b1 = 0.0f, b2 = -0.0675f;
    // Variables d'état du filtre
    float x1 = 0.0f, x2 = 0.0f, y1 = 0.0f, y2 = 0.0f;

    for (uint16_t i = 0; i < len; i++) {
        float x0 = signal[i];
        // Équation aux différences du filtre IIR
        float y0 = b0 * x0 + b1 * x1 + b2 * x2 - a1 * y1 - a2 * y2;
        filtered[i] = y0;
        // Mise à jour des variables d'état
        x2 = x1; x1 = x0;
        y2 = y1; y1 = y0;
    }
}

/**
 * @brief Détecte les pics dans le signal filtré pour compter les pas
 * @param signal Tableau du signal filtré à analyser
 * @param len Nombre d'échantillons dans le signal
 * @param threshold Seuil de détection des pics
 * @pre Le tableau signal doit contenir au moins 'len' éléments
 * @pre len doit être supérieur à 2
 * @pre threshold doit être une valeur positive
 * @post Aucune modification des données d'entrée
 * @return Nombre de pas détectés
 *
 * Cette fonction détecte les pics locaux dans le signal qui dépassent
 * le seuil défini. Un mécanisme anti-rebond évite les détections multiples
 * en ignorant les 5 échantillons suivant chaque détection.
 */
uint16_t detect_steps(const float *signal, uint16_t len, float threshold) {
    uint16_t count = 0;
    for (uint16_t i = 1; i < len - 1; i++) {
        // Détection d'un pic : valeur supérieure au seuil et aux voisins
        if (signal[i] > threshold && signal[i] > signal[i - 1] && signal[i] > signal[i + 1]) {
            count++;
            i += 5; // Évite les doubles détections (mécanisme anti-rebond)
        }
    }
    return count;
}

/**
 * @brief Calcule le nombre de pas effectués à partir des données d'accélération
 * @param DataStruct Pointeur vers la structure MPU6050_t pour l'acquisition des données
 * @pre Le capteur MPU6050 doit être initialisé et fonctionnel
 * @pre DataStruct ne doit pas être NULL
 * @post Les données d'accélération sont acquises et traitées
 * @return Nombre de pas détectés
 *
 * Cette fonction effectue une chaîne de traitement complète pour la détection de pas :
 * 1. Acquisition de 1200 échantillons d'accélération (30 secondes à 40Hz)
 * 2. Calcul de la norme euclidienne des vecteurs d'accélération
 * 3. Filtrage passe-bande pour isoler les fréquences de marche
 * 4. Suppression de la composante continue (moyenne)
 * 5. Détection des pics pour compter les pas
 */
uint16_t calcule_pas(MPU6050_t* DataStruct) {
    // Tableaux pour stocker les données d'accélération
    int16_t accX_data[MPU6050_RECORDING_SIZE];
    int16_t accY_data[MPU6050_RECORDING_SIZE];
    int16_t accZ_data[MPU6050_RECORDING_SIZE];
    float accNorm[MPU6050_RECORDING_SIZE];
    float filtered[MPU6050_RECORDING_SIZE];

    // Phase d'acquisition des données
    for (uint16_t i = 0; i < MPU6050_RECORDING_SIZE; i++) {
        MPU6050_ReadAll(DataStruct);
        accX_data[i] = DataStruct->Accelerometer_X;
        accY_data[i] = DataStruct->Accelerometer_Y;
        accZ_data[i] = DataStruct->Accelerometer_Z;
        HAL_Delay(MPU6050_SAMPLE_TIME);

        // Affichage du progrès (un point tous les 300 échantillons)
        if ((i % 300) == 0) {
            printf(".");
        }
    }
    printf(" Acquisition terminée\r\n");

    // Calcul de la norme euclidienne des vecteurs d'accélération
    compute_acc_norm(accX_data, accY_data, accZ_data, accNorm, MPU6050_RECORDING_SIZE);

    // Application du filtre passe-bande
    bandpass_filter(accNorm, filtered, MPU6050_RECORDING_SIZE);

    // Calcul et suppression de la moyenne (composante continue)
    float mean = 0.0f;
    for (uint16_t i = 0; i < MPU6050_RECORDING_SIZE; i++) {
        mean += filtered[i];
    }
    mean /= (float)MPU6050_RECORDING_SIZE;

    // Centrage du signal autour de zéro
    for (uint16_t i = 0; i < MPU6050_RECORDING_SIZE; i++) {
        filtered[i] -= mean;
    }

    // Détection des pas par analyse des pics
    uint16_t steps = detect_steps(filtered, MPU6050_RECORDING_SIZE, MPU6050_THRESHOLD);
    return steps;
}
#endif


