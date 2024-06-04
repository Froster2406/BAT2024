clear;
clc;

% Create an A-weighting filter
AWeighting = weightingFilter('A-weighting', 48000);

% Extract the filter design
aSOSFilter = getFilter(AWeighting);

% Save the filter design to a file
% save('a_filter_48000_DD2-T.mat', 'aSOSFilter');

% Create an A-weighting filter
CWeighting = weightingFilter('C-weighting', 48000);

% Extract the filter design
cSOSFilter = getFilter(CWeighting);

% Save the filter design to a file
% save('c_filter_48000_DD2-T.mat', 'cSOSFilter');