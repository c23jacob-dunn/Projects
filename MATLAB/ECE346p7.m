% Jacob Dunn's Code
Vo = 10;
a = .02;
b = .01;
x = 0:.002:a;
y = 0:.001:b;
NN = 100;
V = 0;
[X,Y] = meshgrid(x,y);
for m = 1:NN
    n = 2*m-1;
    A = 4*Vo/(n*pi*sinh(n*pi*b/a))*ones(length(x),length(y));
    V = V + A*sin(n*pi*X/a).*sinh(n*pi*Y/a);
end
contour(X,Y,abs(V)),grid,xlabel('x, meters'),ylabel('V(x,y)'),title('Jacob Dunn')