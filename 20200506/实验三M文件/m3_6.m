A = rand(5,6);
n = input('������');
if n < 1 || n > 5
    disp(A(5,:));
    disp('�������');
else
    disp(A(n,:));
end