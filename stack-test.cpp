#include "stack.h"
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]){
	Stack<int> test;
	test.push(4);
	cout<<"4: " << test.top() << endl;
	test.pop();
	cout<<"0: " << test.size();
}