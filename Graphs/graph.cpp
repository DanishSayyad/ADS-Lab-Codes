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
			
			// Method 1: Adjacency Matrix Reading
			/*for(int i = 0; i < v; i++) {
				arr[i] = new int[v];
				if(!arr[i]) return;
				for(int j = 0; j < v; j++) f1 >> arr[i][j];
			}*/
			
			// Mathod 2: Vertex Pair Reading
			for(int i = 0; i < v; i++) {
				arr[i] = new int[v];
				if(!arr[i]) return;
				for(int j = 0; j < v; j++) arr[i][j] = 0;
			}
			for(int k = 0; k < v; k++) {
				int i, j;
				f1 >> i;
				f1 >> j;
				arr[i][j] = 1;
				arr[j][i] = 1;
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
		
		int countEdges() {
			int x = 0;
			for(int i = 0; i < v; i++)
				for(int j = 0; j < i + 1; j++)
					if(arr[i][j]) x++;
			return x;
		}
		
		void showDegree() {
			int temp;
			for(int i = 0; i < v; i++) {
				temp = 0;
				for(int j = 0; j < v; j++)
					if(arr[i][j]) temp++;
				cout << "Degree of " << i << " : " << temp << endl;
			}
		}
		
		void showAdjacency() {
			for(int i = 0; i < v; i++) {
				cout << i << " --> ";
				for(int j = 0; j < v; j++) {
					if(arr[i][j]) cout << j << ",";
				}
				cout << "\b \n";
			}
		}
};

int main() {
	Graph g1("graph2.txt");
	g1.display();
	cout << "\nNo. of edges: " << g1.countEdges() << endl;
	g1.showDegree();
	cout << "\nAdjacency of the graph:\n";
	g1.showAdjacency();
	return 0;
}








