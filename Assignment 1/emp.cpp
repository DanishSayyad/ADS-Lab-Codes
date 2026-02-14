#include<fstream>
#include<climits>
#include<iostream>
#include"emp.h"

using namespace std;

emp :: emp() : id(INT_MIN), sal(0), name(""), des(""), left(NULL), right(NULL) {}

emp :: emp(int i, int s, string n, string d) : id(i), sal(s), name(n), des(d), left(NULL), right(NULL) {}

Payroll :: Payroll() : root(NULL) {}

Payroll :: ~Payroll() { destroyTree(root); }

void Payroll :: destroyTree(emp *node) {
	if(node) {
		destroyTree(node->left);
		destroyTree(node->right);
		delete node;
	}
}

emp* Payroll :: insert(emp *node, emp *newEmp) {
	if(!node) return newEmp;
	if(newEmp->id < node->id) node->left = insert(node->left, newEmp);
	else if(newEmp->id > node->id) node->right = insert(node->right, newEmp);
	else cout << "Employee ID " << newEmp->id << " already exists!" << endl;
	return node;
}

void Payroll :: addEmployee(int id, string name, string designation, int salary) {
	root = insert(root, new emp(id, salary, name, designation));
	cout << "Employee added successfully!" << endl;
}

emp* Payroll :: search(emp *node, int id) {
	if(!node || node->id == id) return node;
	return (id < node->id) ? search(node->left, id) : search(node->right, id);
}

emp* Payroll :: searchEmployee(int id) {
	emp *result = search(root, id);
	if(result) {
		cout << "\nEmployee Found:\n-------------------------------------------\n";
		cout << "ID\tName\t\tDesignation\tSalary\n-------------------------------------------\n";
		display_emp(result);
		cout << endl;
	} else cout << "Employee ID " << id << " not found!" << endl;
	return result;
}

emp* Payroll :: minNode(emp *node) {
	while(node && node->left) node = node->left;
	return node;
}

emp* Payroll :: remove(emp *node, int id) {
	if(!node) return node;
	if(id < node->id) node->left = remove(node->left, id);
	else if(id > node->id) node->right = remove(node->right, id);
	else {
		if(!node->left) { emp *t = node->right; delete node; return t; }
		if(!node->right) { emp *t = node->left; delete node; return t; }
		emp *t = minNode(node->right);
		node->id = t->id; node->name = t->name; node->des = t->des; node->sal = t->sal;
		node->right = remove(node->right, t->id);
	}
	return node;
}

void Payroll :: removeEmployee(int id) {
	if(!search(root, id)) { cout << "Employee ID " << id << " not found!" << endl; return; }
	root = remove(root, id);
	cout << "Employee removed successfully!" << endl;
}

void Payroll :: updateEmployee(int id) {
	emp *e = search(root, id);
	if(!e) { cout << "Employee ID " << id << " not found!" << endl; return; }
	int choice;
	cout << "\nUpdate: 1.Designation 2.Salary 3.Both\nChoice: ";
	cin >> choice;
	if(choice == 1 || choice == 3) { cout << "New designation: "; cin >> e->des; }
	if(choice == 2 || choice == 3) { cout << "New salary: "; cin >> e->sal; }
	cout << "Employee updated successfully!" << endl;
}

void Payroll :: display_emp(emp *e) {
	if(e) cout << e->id << "\t" << e->name << "\t\t" << e->des << "\t" << e->sal << endl;
}

void Payroll :: inorder(emp *node) {
	if(node) { inorder(node->left); display_emp(node); inorder(node->right); }
}

void Payroll :: displayAll() {
	if(!root) { cout << "No employees!" << endl; return; }
	cout << "\n===========================================\n";
	cout << "ID\tName\t\tDesignation\tSalary\n-------------------------------------------\n";
	inorder(root);
	cout << "===========================================" << endl;
}

emp* Payroll :: findHighestPaid(emp *node) {
	if(!node) return NULL;
	emp *highest = node, *leftH = findHighestPaid(node->left), *rightH = findHighestPaid(node->right);
	if(leftH && leftH->sal > highest->sal) highest = leftH;
	if(rightH && rightH->sal > highest->sal) highest = rightH;
	return highest;
}

emp* Payroll :: findLowestPaid(emp *node) {
	if(!node) return NULL;
	emp *lowest = node, *leftL = findLowestPaid(node->left), *rightL = findLowestPaid(node->right);
	if(leftL && leftL->sal < lowest->sal) lowest = leftL;
	if(rightL && rightL->sal < lowest->sal) lowest = rightL;
	return lowest;
}

void Payroll :: findHighestLowest() {
	if(!root) { cout << "No employees!" << endl; return; }
	emp *h = findHighestPaid(root), *l = findLowestPaid(root);
	cout << "\nHighest Paid:\n-------------------------------------------\n";
	cout << "ID\tName\t\tDesignation\tSalary\n-------------------------------------------\n";
	display_emp(h);
	cout << "\nLowest Paid:\n-------------------------------------------\n";
	cout << "ID\tName\t\tDesignation\tSalary\n-------------------------------------------\n";
	display_emp(l);
	cout << endl;
}

void Payroll :: countDesignation(emp *node, string designation, int &count) {
	if(node) {
		countDesignation(node->left, designation, count);
		if(node->des == designation) count++;
		countDesignation(node->right, designation, count);
	}
}

void Payroll :: countByDesignation(string designation) {
	int count = 0;
	countDesignation(root, designation, count);
	cout << "Employees with designation '" << designation << "': " << count << endl;
}

void Payroll :: displayInRange(emp *node, int minSal, int maxSal) {
	if(node) {
		displayInRange(node->left, minSal, maxSal);
		if(node->sal >= minSal && node->sal <= maxSal) display_emp(node);
		displayInRange(node->right, minSal, maxSal);
	}
}

void Payroll :: displaySalaryRange(int minSal, int maxSal) {
	if(!root) { cout << "No employees!" << endl; return; }
	cout << "\nSalary range " << minSal << " - " << maxSal << ":\n-------------------------------------------\n";
	cout << "ID\tName\t\tDesignation\tSalary\n-------------------------------------------\n";
	displayInRange(root, minSal, maxSal);
	cout << "-------------------------------------------" << endl;
}

emp* Payroll :: copyTree(emp *node) {
	if(!node) return NULL;
	emp *newNode = new emp(node->id, node->sal, node->name, node->des);
	newNode->left = copyTree(node->left);
	newNode->right = copyTree(node->right);
	return newNode;
}

void Payroll :: copyPayroll() {
	if(!root) { cout << "No employees to copy!" << endl; return; }
	emp *copiedRoot = copyTree(root);
	cout << "Tree copied!\n\nCopied Tree:\n-------------------------------------------\n";
	cout << "ID\tName\t\tDesignation\tSalary\n-------------------------------------------\n";
	inorder(copiedRoot);
	cout << "-------------------------------------------" << endl;
	destroyTree(copiedRoot);
}

int Payroll :: height(emp *node) {
	return node ? 1 + max(height(node->left), height(node->right)) : 0;
}

void Payroll :: showHeight() {
	cout << "Height of employee tree: " << height(root) << endl;
}

void Payroll :: loadFromFile() {
	ifstream file("data.txt");
	if(!file) { cout << "Error opening file!" << endl; return; }
	int id, salary; string name, designation;
	while(file >> id >> name >> designation >> salary)
		root = insert(root, new emp(id, salary, name, designation));
	file.close();
	cout << "Data loaded successfully!" << endl;
}

