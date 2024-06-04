clear all
clc
close

% Fs = 48000;
% 
% A_filter = weightingFilter('A-weighting', Fs);
% %fvtool(A_filter)
% A_coeff = (A_filter.coeffs);
% A_coeff = A_coeff.SOSMatrix
% 
% C_filter = weightingFilter('C-weighting', Fs);
% %fvtool(A_filter)
% C_coeff = (C_filter.coeffs);
% C_coeff = C_coeff.SOSMatrix

%A_filter_2 = getFilter(A_filter)

% % Compute the frequency response
% H= fvtool(getFilter(A_filter));
% 
% % Combine magnitude and phase into a matrix
% frequencyResponseMatrix = [abs(H); angle(H)];
% 
% % Write the frequency response to a CSV file
% writematrix(frequencyResponseMatrix, 'sos_filter_frequency_response.csv');

% Define the frequency range
freq = linspace(20, 30000, 1000); % Frequencies from 20 Hz to 20 kHz

% Calculate RA(f)
RA_f = (12194^2.* freq.^4)./ ((freq.^2 + 20.6^2).* sqrt((freq.^2 + 107.7^2).* (freq.^2 + 737.9^2)).* (freq.^2 + 12194^2));

% Normalize RA(f) to 0 dB at 1000 Hz
RA_1000 = RA_f(500); % Assuming 500 samples correspond to 1000 Hz
RA_normalized = 20 * log10(RA_f / RA_1000);

% Calculate A-weighting values
A_weighting = RA_normalized + 2.00;

% Plot the A-weighting curve
figure;
plot(freq, A_weighting);
xlabel('Frequency (Hz)');
ylabel('A-Weighting Value (dB)');
title('A-Weighting Curve');
grid on;