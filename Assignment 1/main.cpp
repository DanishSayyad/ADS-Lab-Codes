#include<iostream>
#include"emp.h"

using namespace std;

void displayMenu() {
	cout << "\n=========================================" << endl;
	cout << "     EMPLOYEE PAYROLL SYSTEM" << endl;
	cout << "=========================================" << endl;
	cout << "1.  Add Employee" << endl;
	cout << "2.  Remove Employee" << endl;
	cout << "3.  Search Employee" << endl;
	cout << "4.  Update Employee Salary/Designation" << endl;
	cout << "5.  Display All Employees (Ascending ID)" << endl;
	cout << "6.  Find Highest & Lowest Paid Employee" << endl;
	cout << "7.  Count Employees by Designation" << endl;
	cout << "8.  Display Employees within Salary Range" << endl;
	cout << "9.  Copy Payroll Tree" << endl;
	cout << "10. Show Height of Employee Tree" << endl;
	cout << "11. Load Data from File" << endl;
	cout << "0.  Exit" << endl;
	cout << "=========================================" << endl;
	cout << "Enter your choice: ";
}

int main() {
	Payroll pay;
	int choice, id, salary, minSal, maxSal;
	string name, designation;
	
	do {
		displayMenu();
		cin >> choice;
		
		switch(choice) {
			case 1:
				cout << "\n--- Add Employee ---" << endl;
				cout << "Enter Employee ID: ";
				cin >> id;
				cout << "Enter Name: ";
				cin >> name;
				cout << "Enter Designation: ";
				cin >> designation;
				cout << "Enter Salary: ";
				cin >> salary;
				pay.addEmployee(id, name, designation, salary);
				break;
				
			case 2:
				cout << "\n--- Remove Employee ---" << endl;
				cout << "Enter Employee ID to remove: ";
				cin >> id;
				pay.removeEmployee(id);
				break;
				
			case 3:
				cout << "\n--- Search Employee ---" << endl;
				cout << "Enter Employee ID to search: ";
				cin >> id;
				pay.searchEmployee(id);
				break;
				
			case 4:
				cout << "\n--- Update Employee ---" << endl;
				cout << "Enter Employee ID to update: ";
				cin >> id;
				pay.updateEmployee(id);
				break;
				
			case 5:
				cout << "\n--- Display All Employees ---" << endl;
				pay.displayAll();
				break;
				
			case 6:
				cout << "\n--- Highest & Lowest Paid ---" << endl;
				pay.findHighestLowest();
				break;
				
			case 7:
				cout << "\n--- Count by Designation ---" << endl;
				cout << "Enter Designation: ";
				cin >> designation;
				pay.countByDesignation(designation);
				break;
				
			case 8:
				cout << "\n--- Salary Range Display ---" << endl;
				cout << "Enter minimum salary: ";
				cin >> minSal;
				cout << "Enter maximum salary: ";
				cin >> maxSal;
				pay.displaySalaryRange(minSal, maxSal);
				break;
				
			case 9:
				cout << "\n--- Copy Payroll Tree ---" << endl;
				pay.copyPayroll();
				break;
				
			case 10:
				cout << "\n--- Tree Height ---" << endl;
				pay.showHeight();
				break;
				
			case 11:
				cout << "\n--- Load from File ---" << endl;
				pay.loadFromFile();
				break;
				
			case 0:
				cout << "\nThank you for using Employee Payroll System!" << endl;
				break;
				
			default:
				cout << "\nInvalid choice! Please try again." << endl;
		}
		
	} while(choice != 0);
	
	return 0;
}
