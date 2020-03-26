/*#include <iostream>
using namespace std;

class Base1
{
protected:
	int m_B1;
public:
	void Setm_B1(int x)
	{
		m_B1 = x;
	}
};
class Base2
{
protected:
	int m_B2;
public:
	void Stem_B2(int x)
	{
		m_B2 = x;
	}
};
class MultiDerived :public Base1, public Base2
{
public:
	void GetB1B2(void)
	{
		int Result;
		Result = m_B1 + m_B2;
		cout << "m_B1 + m_B2 =";
		cout << Result << endl;
	}
};
void main()
{
	MultiDerived M;
	M.Setm_B1(15);
	M.Stem_B2(35);
	M.GetB1B2();
	getchar();
}

/*class Class1
{
	int Value;
public:
	Class1(int Val)
	{
		Value = Val;
	}
	int GetValue(void)
	{
		return Value;
	}
};
void main()
{
	Class1 Object1(888), *p;
	p = &Object1;
	cout << "the value of Object1 is:" << p->GetValue();
	cout << endl;
	getchar();
}*/
