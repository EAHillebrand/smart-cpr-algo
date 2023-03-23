clc;
clear all;
close all;

run Cals.m


freq = 1;

% my_time = (0:0.001:20)';
% my_data = uint16(zeros(20001,1));
% my_data(1:2000) = 4000;
% 
% my_data(2001:end) = 2000*(cos(2*pi*(0:0.001:18)/freq)+1);

% load analogRead_A4.mat
% load analogRead_A4_35sec.mat % good one
load analogRead_A4_LotsVariance.mat
% load('data\feb16_stm32_clean_adc_various_speed.mat') % 3 speeds stm32 adc


% x = my_time;
% y = my_data;
% data.Time(1:20001) = my_time;
% data.Data(1:20001) = my_data;
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