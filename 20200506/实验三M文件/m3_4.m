a = input('input a number:');
b = input('input another number:');
c = input('input a method number:','s');

if c == '+'
    res = a + b;
elseif c == '-'
    res = a - b;
elseif c == '*'
    res = a * b;
elseif c == '/'
    res = a / b;
else
    res = 'error input';
end
res