clc
score = input('score = ');
if score <= 100 && score >= 0
    switch fix(score / 10)
        case {9,10}
            grade = 'A';
        case {8}
            grade = 'B';
        case {7}
            grade = 'C';
        case {6}
            grade = 'D';
        otherwise
            grade = 'E';
    end
else
    disp('错误：输入的成绩不规范');
end