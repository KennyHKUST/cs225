#include <iostream>
using namespace std;


int main(int argc, char** argv) {
  if (argc >= 2) {
    string s(argv[1]);
    switch(s.length()){
    	case 2:
    		cout << "Bye Bye" << endl;
    		break;
    	case 3:
    		cout << "No No No" << endl;
    		break;
    	case 4:
    		cout << "Wa Wa Wa" << endl;
    		break;
    	case 5:
    		cout << "Wo Wo Wo" << endl;
    		break;
    	default:
    		cout << "LoL" << endl;

    }
    // Your code here

    return 0;
  } else {
    cout<<"Usage: "<<argv[0]<<" <word>"<<endl;
    return 1;
  }
}
