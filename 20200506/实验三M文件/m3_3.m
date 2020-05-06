id = input('input number:');
time = input('input work time:');
if time > 120
    salary = 84 * 120 + (time - 120) * 84 * (1 + 0.15);
elseif time < 60
    salary = 84 * time - 700;
else
    salary = 84 * time;
end
salary