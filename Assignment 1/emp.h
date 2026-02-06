#include<iostream>

using namespace std;

enum Designation {};

struct emp {
	int id, sal;
	string name, des;
	emp();
	emp(int, int, string, string);
};

class Payroll {
	private:
		int n;
		emp *arr;
		void display_emp(emp);

	public:
		Payroll(int);
		void newEmployee(emp);
		void Display_rec(int);
		void Display();
};

void readFile(Payroll);

