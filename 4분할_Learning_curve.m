Num = 30000;
subplot(2,2,1)
E = load('outputdata_L90.txt'); %data 불러오기
x = 1:Num;
plot(x,E);
grid ON;
xlabel('epochs');
ylabel('energy');
title('HLnum = 12, Learning Gain = 0.9, Bias(X)');

subplot(2,2,2)
E = load('outputdata_M91.txt'); %data 불러오기
x = 1:Num;
plot(x,E);
grid ON;
xlabel('epochs');
ylabel('energy');
title('HLnum = 13, Learning Gain = 0.9, Bias(O)');

subplot(2,2,3)
E = load('outputdata_N10.txt'); %data 불러오기
x = 1:Num;
plot(x,E);
grid ON;
xlabel('epochs');
ylabel('energy');
title('HLnum = 14, Learning Gain = 0.1, Bias(X)');

subplot(2,2,4)
E = load('outputdata_O11.txt'); %data 불러오기
x = 1:Num;
plot(x,E);
grid ON;xlabel('epochs');
ylabel('energy');
title('HLnum = 15, Learning Gain = 0.1, Bias(O)');
