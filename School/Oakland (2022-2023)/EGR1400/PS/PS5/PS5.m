A = imread("hallnoise.bmp");
B = [1 0 -1; 1 0 -1; 1 0 -1];
C = imfilter(A, B);
imshow(C)