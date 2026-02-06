#include<climits>
#include"bst.h"

BST :: BST(int n = 50) {
	s = n;
	arr = new int[s];
	for(int i = 0; i < s; i++) {
		arr[i] = INT_MIN;
	}
}
