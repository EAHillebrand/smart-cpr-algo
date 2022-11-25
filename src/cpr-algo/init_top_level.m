clc;
clear all;
close all;

% load analogRead_A4.mat
load analogRead_A4_35sec.mat
% load analogRead_A4_LotsVariance.mat
x = data.Time;
y = data.Data;
y = squeeze(y(1,1,:));
plot(x,y)
title("ADC Values")
xlabel("Time (Sec)")

%%
% my_time = out.distance.Time;
% distance = out.distance.data;
% distance = squeeze(distance(1,1,:));
% figure
% plot(my_time, distance)