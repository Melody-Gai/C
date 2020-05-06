A = input('输入一个5*6的矩阵A：');
n = input('输入一正整数n = ');
if n < 5 && n > 0
    disp(A(n,:));
else
    disp(A(5,:));
end
lasterr