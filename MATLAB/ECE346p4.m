%Jacob Dunn's Code
syms x;
u1 = sin(pi * (x - 10*0));
u2 = sin(pi * (x - 10*0.01));
u3 = sin(pi * (x - 10*0.02));
fplot(u1);
hold on;
fplot(u2);
fplot(u3);
axis([0 1 -.6 1]);
hold off;
title('Jacob Dunn');
xlabel('x, meters');
ylabel('u(x,t)');