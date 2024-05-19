clear all
clc
close

Fs = 48000;

A_filter = weightingFilter('A-weighting', Fs);
%fvtool(A_filter)
A_coeff = (A_filter.coeffs);
A_coeff = A_coeff.SOSMatrix

C_filter = weightingFilter('C-weighting', Fs);
%fvtool(A_filter)
C_coeff = (C_filter.coeffs);
C_coeff = C_coeff.SOSMatrix

%A_filter_2 = getFilter(A_filter)

% % Compute the frequency response
% H= fvtool(getFilter(A_filter));
% 
% % Combine magnitude and phase into a matrix
% frequencyResponseMatrix = [abs(H); angle(H)];
% 
% % Write the frequency response to a CSV file
% writematrix(frequencyResponseMatrix, 'sos_filter_frequency_response.csv');