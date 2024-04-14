clc
clear
close all

load("a_filter.mat")

Fs = 41100;
T = 5
t = 0:1/Fs:T;
signal = chirp(t,0,T,Fs/2);


plot(t, signal)
%spectrogram(signal)

x1 = filter(biquad.SOSMatrix(1,1:3), biquad.SOSMatrix(1,4:6), signal);
x2 = filter(biquad.SOSMatrix(2,1:3), biquad.SOSMatrix(2,4:6), x1);
x3 = filter(biquad.SOSMatrix(3,1:3), biquad.SOSMatrix(3,4:6), x2);


figure
semilogx(x3)

loglog(abs(fft(x3)))