#include<iostream>
#include<fstream>

using namespace std;

class Graph {
	private:
		int v, **arr;
		
	public:
		Graph(string fname) {
			ifstream f1(fname, ios::in);
			f1 >> v;
			arr = new int*[v];
			if(!arr) return;
			
			for(int i = 0; i < v; i++) {
				arr[i] = new int[v];
				if(!arr[i]) return;
				for(int j = 0; j < v; j++) f1 >> arr[i][j];
			}
		}
		
		void display() {
			cout << v << endl;
			for(int i = 0; i < v; i++) {
				for(int j = 0; j < v; j++) {
					cout << *(*(arr + i) + j) << " ";
				}
				cout << endl;
			}
		}
};

int main() {
	Graph g1("graph1.txt");
	g1.display();
	return 0;
}

