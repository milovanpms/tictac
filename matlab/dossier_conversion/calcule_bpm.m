function [nb_battements,bpm_moy] = calcule_bpm(periode,bat)
fs = 1/periode;
N  = length(bat);
t  = (0:N-1)/fs;
f_low  = 0.5;                     
f_high = 5;
ordre  = 3;
Wn     = [f_low f_high]/(fs/2);
[b,a]  = butter(ordre, Wn, 'bandpass');
ppg_filt = filter(b, a, bat);
seuil     = mean(ppg_filt) + 0.5*std(ppg_filt);
minDist   = 0.4;
[peaks, locs] = findpeaks(ppg_filt, t, ...
    'MinPeakHeight', seuil, ...
    'MinPeakDistance', minDist);
IBI      = diff(locs);
HR_inst  = 60 ./ IBI;
bpm_moy = mean(HR_inst);
nb_battements = numel(peaks);
end