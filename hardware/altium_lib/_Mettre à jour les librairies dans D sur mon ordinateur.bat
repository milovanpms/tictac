net use y: \\eseo-etudiants\depots\Altium
xcopy "y:\librairies altium" "D:\librairies altium" /f /i /e /s
net use y: /DELETE /YES
echo "la librairie altium a été mise à jour sur cet ordinateur ! Retrouvez là dans D:\librairie Altium !" 
pause