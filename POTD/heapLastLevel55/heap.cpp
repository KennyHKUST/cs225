#include <cmath>
using namespace std;
#include "MinHeap.h"

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

    return lastLevel;
}