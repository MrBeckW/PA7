#include <iostream>
#include "Stack.hpp"


int main()
{
	Stack stack;
	std::string s1 = "Monday", s2 = "Tuesday", s3 = "Wednesday", s4;
	
	bool isEmpty = stack.isEmpty();
	std::cout << isEmpty << std::endl;
	
	stack.push(s1);
	s4 = stack.peek();
	std::cout << "Expected s4: Monday  :" << s4 << std::endl;

	stack.push(s2);
	s4 = stack.peek();
	std::cout << "Expected s4: Tuesday  :" << s4 << std::endl;

	s4 = stack.pop();
	std::cout << "Expected s4: Tuesday  :" << s4 << std::endl;

	s4 = stack.peek();
	std::cout << "Expected s4: Monday  :" << s4 << std::endl;

	return 0;
}