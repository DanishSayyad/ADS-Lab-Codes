#include<fstream>
#include<climits>
#include"emp.h"

emp :: emp() {
	id = INT_MIN;
}

emp :: emp(int i, int s, string n, string d) {
	id = i;
	sal = s;
	name = n;
	des = d;
}

void Payroll :: display_emp(emp e) {
	cout << e.id << "\t";
	cout << e.name << "\t";
	cout << e.des << "\t";
	cout << e.sal << endl;
	cout << "-------------------------------------------";
}

Payroll :: Payroll(int s) {
	n = s;
	arr = new emp[n];
	if(!arr) return;
	for(int i = 0; i < n; i++) {
		arr[i].id = INT_MIN;
	}
}

void Payroll :: newEmployee(emp e) {}

void readFile() {
	return;
}

