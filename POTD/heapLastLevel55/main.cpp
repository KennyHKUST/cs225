#include <algorithm>
#include <iostream>
#include <vector>
#include "MaxHeap.h"
#include "MinHeap.h"

using namespace std;

//#include "heap.cpp"

// Use this main() function to test your code. You may change things as you
// wish here, this is for your own use. Please note: This code will not be used
// for grading.
vector<int> lastLevel(MinHeap heap)
{
    // Your code here
    int size = heap.elements.size();
    int numOfNodes = 1;
    int mul = 1;
    while(numOfNodes <= size){
        numOfNodes += 2 * mul;
        mul *= 2;
    }

    vector<int> lastLevel;
    int start = numOfNodes - 2 * (mul / 2) + 1;
    for(int i = start; i < size; i ++)
        lastLevel.push_back(heap.elements[i]);
    //lastLevel.push_back(500);
    return lastLevel;
}
int main()
{
    // Creating a heap
    vector<int> elems = {4, 10, 30, 90, 110, 150, 300, 500};
    MinHeap myHeap(elems);

    // Printing a heap
    cout << "myHeap: " << endl;
    myHeap.print();

    // Testing your answer
    vector<int> leafNodes = lastLevel(myHeap);
    cout << "The leaf nodes are" << endl;
    for (size_t i = 0; i < leafNodes.size(); i ++)
        cout << leafNodes[i] << ' ';
    cout << endl;

    // Checking correctness
    vector<int> expected = {500};
    if (expected == leafNodes)
        cout << "Your output is correct" << endl;
    else
        cout << "Your output is incorrect" << endl;

    return 0;
}
