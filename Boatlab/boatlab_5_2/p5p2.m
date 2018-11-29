clear;
close all;
load wave.mat;
%Assignment 5.2 - Identification of wave spectrum model

%Estimation of Power spectral Density 
%5.2 a)
Fs = 10;
window = 4096;
noverlap=[];
nfft=[];

%FInding estimated Power Spectrum Density
[pxx,f] = pwelch(psi_w(2,:).*(pi/180),window,noverlap,nfft,Fs);

% PSD(Power/pr.HZ) to PSD(Power s/rad] and f[HZ] to w[rad/s]
pxx=pxx./(2*pi);
omega=2*pi.*f;

%Find 0mega_0 and corresponding intensity sigma^2 form 
%5.2 c)
[peak_value, peak_index]=max(pxx);
w_0 = omega(peak_index);
sigma = sqrt(peak_value);

%5.2 d)
%Curve-fitting to find damping factor lambda
fun = @(x,omega)(2*x*w_0*sigma)^2.*omega.^2./(omega.^4+w_0^2.*omega.^2*(4*x^2-2)+w_0^4); % Creating the model
lambda0 = 0.5; %Defining a starting point
lambda = lsqcurvefit(fun, lambda0, omega, pxx); %Finding the local minimum possible

Kw = 2 * lambda * w_0 * sigma;

% Compute Analytical Power Spectral Density
sxx = fun(lambda, omega);

% Plot the analytical and measured spectrums
figure
plot(omega, pxx);
hold on;
plot(omega, sxx);
axis([0.2 1.5 10^-7 10.5^-3]);
title('Analytical and measured Prower Spectrum Density');
xlabel('\omega[Rad/s]');
ylabel('PSD [power s/rad]');
grid
