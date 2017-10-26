#include <iostream>
#include <map>
#include <string>
using namespace std;
string fibonacci(int n) {
	static map<unsigned long, string> fib = {{0, "0"}, {1, "1"}};
	auto it = fib.find(n);
	if(it != fib.end())
		return it->second;
	string result = to_string((unsigned long)fibonacci(n - 1) + (unsigned long)fibonacci(n - 2));
	fib.insert(std::pair<unsigned long, string>(n, result));
	it = fib.find(n);
	return it->second;

}

 int main() {
   cout<<"fibonacci(1000) = "<<fibonacci(5)<<endl;
   cout<<"fibonacci(1000) = "<<fibonacci(1000)<<endl;
   cout<<"fibonacci(10000) = "<<fibonacci(10000)<<endl;
   return 0;
 }
