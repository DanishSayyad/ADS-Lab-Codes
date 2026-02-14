#include<iostream>
#include<climits>
#include<fstream>

using namespace std;

class Heap {
    private:
        int size, *arr, spot;
        int parentIndex(int i) {
            return (i - 1) / 2;
        }
        
        int leftChild(int i) {
            return 2 * i + 1;
        }
        
        int rightChild(int i) {
            return 2 * i + 2;
        }
        
        void heapify(int i) {
            int smallest = i;
            int left = leftChild(i);
            int right = rightChild(i);
            int parent = parentIndex(i);
            
            // Check parent (heapify up)
            if(i > 0 && arr[i] < arr[parent]) {
                smallest = parent;
                int temp = arr[i];
                arr[i] = arr[smallest];
                arr[smallest] = temp;
                heapify(smallest);
                return;
            }
            
            // Check children (heapify down)
            if(left <= spot && arr[left] < arr[smallest]) {
                smallest = left;
            }
            
            if(right <= spot && arr[right] < arr[smallest]) {
                smallest = right;
            }
            
            if(smallest != i) {
                int temp = arr[i];
                arr[i] = arr[smallest];
                arr[smallest] = temp;
                heapify(smallest);
            }
        }
    
    public:
        Heap(int n = 100) {
            size = n;
            arr = new int[size];
            for(int i = 0; i < size; i++) arr[i] = INT_MIN;
            spot = -1;
        }

        void display() {
            for(int i = 0; i < size && arr[i] != INT_MIN; i++) cout << arr[i] << "\t";
            cout << endl;
        }

        void insert(int key) {
            if(++spot > size - 1) return;
            arr[spot] = key;
            heapify(spot);
        }
        int search(int key) {
            for(int i = 0; i < size && arr[i] != INT_MIN; i++) {
                if(arr[i] == key) return i;
            }
            return -1;
        }
        void remove(int key){
            int index = search(key);
            if(index == -1) return;
            
            arr[index] = arr[spot];
            arr[spot] = INT_MIN;
            spot--;
            
            if(index <= spot) heapify(index);
        }
};

int main() {
    ifstream file("data.txt");
    if(!file.is_open()) return 1;
    
    int n;
    file >> n;
    
    Heap h(n + 10);
    cout << "Initial heap:" << endl;
    h.display();
    
    for(int i = 0; i < n; i++) {
        int value;
        file >> value;
        cout << "Inserting: " << value << endl;
        h.insert(value);
        h.display();
    }
    
    file.close();
    
    cout << "\nFinal heap after all insertions:" << endl;
    h.display();
    
    cout << "\nDeleting 7:" << endl;
    h.remove(7);
    h.display();
    
    cout << "\nDeleting 45:" << endl;
    h.remove(45);
    h.display();
    
    return 0;
}
