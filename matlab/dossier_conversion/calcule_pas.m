function pas = calcule_pas(accX,accY,accZ)
fs = 40;  
accNorm = sqrt(accX.^2 + accY.^2 + accZ.^2);
[b, a] = butter(2, [0.5 3]/(fs/2), 'bandpass');
accFiltered = filter(b, a, accNorm);
signal = accFiltered - mean(accFiltered);
N = length(signal);
Y = fft(signal);
f = (0:N-1)*(fs/N);
f_half = f(1:floor(N/2));
Y_half = abs(Y(1:floor(N/2)));
f_min = 0.5; 
f_max = 5;
idx_range = (f_half >= f_min & f_half <= f_max);
[~, idx_local] = max(Y_half(idx_range));
idx_global = find(idx_range); 
idx_global = idx_global(idx_local);
fondamentale_freq = f_half(idx_global);
cadence = fondamentale_freq * 60;
pas = cadence ; 
end

