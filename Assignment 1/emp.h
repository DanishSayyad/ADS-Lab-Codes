#include<iostream>
#include<string>

using namespace std;

struct emp {
	int id, sal;
	string name, des;
	emp *left, *right;
	
	emp();
	emp(int, int, string, string);
};

class Payroll {
	private:
		emp *root;
		
		emp* insert(emp*, emp*);
		emp* search(emp*, int);
		emp* remove(emp*, int);
		emp* minNode(emp*);
		void inorder(emp*);
		void display_emp(emp*);
		emp* findHighestPaid(emp*);
		emp* findLowestPaid(emp*);
		void countDesignation(emp*, string, int&);
		void displayInRange(emp*, int, int);
		emp* copyTree(emp*);
		int height(emp*);
		void destroyTree(emp*);

	public:
		Payroll();
		~Payroll();
		void addEmployee(int, string, string, int);
		void removeEmployee(int);
		emp* searchEmployee(int);
		void updateEmployee(int);
		void displayAll();
		void findHighestLowest();
		void countByDesignation(string);
		void displaySalaryRange(int, int);
		void copyPayroll();
		void showHeight();
		void loadFromFile();
};


