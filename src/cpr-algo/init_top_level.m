clc;
clear all;
close all;

time = [0:0.001:9.999]';
perfectSignal = ones(10000,1);
perfectSignal(1:1000) = int16(3.45*200);
per = (2*pi)/500;
for i = 1001:10000
    perfectSignal(i) = int16((1.85 + 1.6 * cos(i*per))*200);
end

% load analogRead_A4.mat
% load analogRead_A4_35sec.mat
% load analogRead_A4_LotsVariance.mat
% x = data.Time;
% y = data.Data;
x = time;
y = perfectSignal;
% y = squeeze(y(1,1,:));
plot(x,y)
title("ADC Values")
xlabel("Time (Sec)")
data = timeseries(y, x);
%%
% my_time = out.distance.Time;
% distance = out.distance.data;
% distance = squeeze(distance(1,1,:));
% figure
% plot(my_time, distance)