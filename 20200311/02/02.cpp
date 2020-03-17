
void swap(int x, int y) {
	int t = x;
	x = y;
	y = t;
}

#include <iostream>
using namespace std;

int main() {

	int a = 3, b = 4;
	cout << a << '\t ' << b << endl;
	swap(a, b);
	cout << a << '\t ' << b << endl;

	/*int a = 3, &r = a;
	cout << a << '\t' << r << endl;
	r = 5;
	cout << a << '\t' << r << endl;
	return 0;*/
	
}