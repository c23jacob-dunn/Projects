
x = [];   
y = [];
V = [];
A = [];
   s = serialport('COM3', 9600, 'DataBits', 7);
   fopen(s);
   for cnt = 1:100
       data = fscanf(s);
       data = str2num(data);

       x(cnt) = cnt;
       y(cnt) = data;

       if(cnt > 1)
         V(cnt) = y(cnt) - y(cnt-1);
           if(cnt > 2)
             A(cnt) = V(cnt) - V(cnt - 1);          
           else
             A = 0;
           end
       else
         V = 0;
         A = 0;
       end

       subplot(3,1,1)
       plot(x, y)
       title("Distance")
       xlabel("Time (s)")
       ylabel("0 to 255")
       subplot(3,1,2)
       plot(x, V)
       title("Velocity")
       xlabel("Time (s)")
       ylabel("-255 to 255")
       subplot(3,1,3)
       plot(x, A)
       title("Acceleration")
       xlabel("Time (s)")
       ylabel("-255 to 255")

       drawnow;
   end
   
   p = polyfit(x,y,22);
   

   fclose(s);
