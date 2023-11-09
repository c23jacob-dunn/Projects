% Jacob Dunn 333 Final Project

% Approach 1
num_pts_omega = 1000;
fla = 600;
fha = 3000;

[lpza3, lppa3, lpka3] = buttap(3)

[lpnum3, lpden3] = zp2tf(lpza3, lppa3, lpka3);

omega_0 = 2*pi*(fla * fha)^(0.5)

BW = 2*pi*(fha-fla)

[bpnum6, bpden6] = lp2bp(lpnum3, lpden3, omega_0, BW)

[bpz6, bpp6, bpk6] = tf2zp(bpnum6, bpden6)

figure

pzplot(tf(bpnum6, bpden6))
axis([-32000 8000 -20000 20000])
[Hbpa6, omega] = freqs(bpnum6, bpden6, num_pts_omega);

figure

plot(omega/(2*pi), abs(Hbpa6))

% Approach 2

[lpza6, lppa6, lpka6] = buttap(6)

[lpnum6, lpden6] = zp2tf(lpza6, lppa6, lpka6)
[lpnum6dn, lpden6dn] = lp2lp(lpnum6, lpden6, fha*2*pi)

figure
pzplot(tf(lpnum6dn, lpden6dn))
axis([-40e3 0 -20e3 20e3]); grid
[hlp6dna, omega] = freqs(lpnum6dn, lpden6dn, num_pts_omega);


