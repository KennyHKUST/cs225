#include <iostream>
#include <vector>
using namespace std;


int find(int x, vector<int>& parents) {
	// Your codes here.
	if(parents[x] == x)
		return x;
	return (parents[x] = find(parents[x], parents));
}
void setUnion(int x, int y, std::vector<int>& parents){
	int root1 = find(x, parents);
	int root2 = find(y, parents);
	parents[root1] = root2;
}
int findCircleNum(vector<vector<int>>& M) {
        if (M.empty()) return 0;
        int n = M.size();

        vector<int> parents(n);
        for (int i = 0; i < n; i++) { parents[i] = i; }   // initialize: every student belongs to one group.

        int groups = n;
        // Your codes here.
    	for(int i = 0; i < n; i++){
    		for(int j = 0; j < n; j++){
    			if(M[i][j] == 1 && i != j){
    				setUnion(i, j, parents);
    			}
    		}
    	}
    	for(int i = 0; i < n; i++){
    		if(find(i, parents) != i)
    			groups--;
    	}
        return groups;
}





int main() {
	vector<vector<int>> M1 = {{1,0,1,0,0}, {0,1,0,1,1}, {1,0,1,0,1}, {0,1,0,1,0}, {0,1,1,0,1}};
	int count1 = findCircleNum(M1);
	cout << "Number of friend circle for class 1 is (correct: 1)"<< count1 << endl;

	vector<vector<int>> M2 = {{1,1,0},{1,1,0},{0,0,1}};
	int count2 = findCircleNum(M2);
	cout << "Number of friend circle for class 2 is (correct: 2)"<< count2 << endl;


	vector<vector<int>> M3 = {{1,1,0,0,0,0}, 
				{1,1,0,1,0,0}, 
				{0,0,1,0,1,0},
				{0,1,0,1,0,0},
				{0,0,1,0,1,0},
				{0,0,0,0,0,1}};
	int count3 = findCircleNum(M3);
	cout << "Number of friend circle for class 3 is (correct: 3)"<< count3 << endl;

	return 0;
}
