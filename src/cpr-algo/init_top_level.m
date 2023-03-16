clc;
clear all;
close all;

run Cals.m

% load analogRead_A4.mat
% load analogRead_A4_35sec.mat % good one
% load analogRead_A4_LotsVariance.mat
load('data\feb16_stm32_clean_adc_various_speed.mat') % 3 speeds stm32 adc

x = data.Time;
y = data.Data;
y = squeeze(y(1,1,:));
plot(x,y)%,marker = 'o')
title("ADC Values")
xlabel("Time (Sec)")
% close all;

%{
length(x)/(max(x)-min(x)) = 18.3410
1/18.34 = 0.0545
%}

%%
% my_time = out.distance.Time;
% distance = out.distance.data;
% distance = squeeze(distance(1,1,:));
% figure
% plot(my_time, distance)