function y = m3_2(x)

if x > 100 || x < 0
    disp('�ɼ�Ӧ��0-100��');
elseif x >= 90 && x <= 100
    y = 'A';
elseif x >= 80 && x <= 89
    y = 'B';
elseif x >= 70 && x <= 79
    y = 'C';
elseif x >= 60 && x <= 69
    y = 'D';
else
    y = 'E';
end
end