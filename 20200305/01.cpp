#include <fstream>
#include  <string>
using namespace std;

int main() {
	ofstream oF("test.txt");
	oF << 3.14 << " " << "hello world\n";
	oF.close();
	ifstream oF("test.txt");
	double d;
	string str;
	return 0;
}


/*#include <iostream>
using namespace std;
void help() {
	cout << "======简单计算器======\n";
	cout << "请输入：左运算数  运算符  有运算符\n";
}

int main() {
	while (1) {
		help();
		double a, b;
		char op;
		cin >> a >> op >> b;
		if (op == '+') {
			cout << a + b << endl;
		}
		else if (op == '-') {
			cout << a - b << endl;
		}
		else if (op == '*') {
			cout << a * b << endl;
		}
		else if (op == '/') {
			cout << a / b << endl;
		}
	}
	return 0;
}
*/

/*#include <iostream>//C++标准输入输出
using namespace std;
//using std::cout;
//using std::endl;

int main() {
	cout << "hello"<<std::endl;
	//std::endl换行符  
	cout << 3 + 4;
	cout << "http://a.com" << endl;

	double radius;
	std::cin >> radius;  //标准输入流对象cin  输入运算符>>
	cout << 3.14 * radius * radius;
	return 0;
}
*/

/*int main() {
	std::cout << "hello world!\n";
	//标准名字空间std：cout是标准控件std的一个名字。必须加上名字空间限定std::    std::cout
	//cout 是一个标准输出流变量（对象），代表控制台窗口
	//<<是一个运算符，假如o是一个输出流对象。x是一个数据      o<<x
	std::cout << 3 + 4;
	return 0;
}*/


/*#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <cstring>
#include <malloc.h>

int main() {
	char *s = (char *)malloc(12 * sizeof(char));
	strcpy(s, "hello world");
	puts(s);
}

#if 0
int main() {

	printf("hello\n");
	double x = 3;
	printf("%lf %lf\n", sqrt(x), sin(x));

	char s[10] = "hello";
	puts(s);
	char s2[26];
	strcpy(s2, "world");
	puts(s2);
	strcat(s2, " is nice.");
	puts(s2);
	printf("%d %d", strlen(s), strlen(s2));

	return 0;
}
#endif
*/