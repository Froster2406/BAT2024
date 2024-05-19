clear
close all
clc

% fig = openfig('BAT_A-Gewichtungsfilter_Matlab_Zeitdiskret.fig');
% axObjs = fig.Children
% dataObjs = axObjs.Children
% x = dataObjs(1).XData
% y = dataObjs(1).YData

% Replace 'YourFigureName' with the actual name of your figure variable
hFig = openfig('BAT_A-Gewichtungsfilter_Matlab_Zeitdiskret.fig');

% Find axes objects in the figure
hAxes = findobj(hFig, '-property', 'Type', 'axes');

if ~isempty(hAxes)
    % Assuming the first axes contains the data you want
    xData = get(hAxes(1), 'XData');
    yData = get(hAxes(1), 'YData');
    
    % Combine xData and yData into a matrix
    dataMatrix = [xData(:), yData(:)];
    
    % Write the data to a CSV file
    writematrix(dataMatrix, 'output.csv'); % Use csvwrite('output.csv', dataMatrix); for older MATLAB versions
else
    disp('No axes found in the figure.');
end
