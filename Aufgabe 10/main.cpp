#include "LinkedList.h"

int main() {

	LinkedList<int> newList;
	
	newList.append(5);
	newList.append(7);
	std::cout << "Last Element of newList: " << newList.getLastElement() << std::endl;

	newList.append(12);
	std::cout << "Last Element of newList: " << newList.getLastElement() << std::endl;

	LinkedList<float> anotherList;
	
	anotherList.append(12.21f);
	std::cout << "Last Element of anotherList: " << anotherList.getLastElement() << std::endl;

	anotherList.append(342.99f);
	anotherList.append(420.0234f);
	std::cout << "Last Element of anotherList: " << anotherList.getLastElement() << std::endl;
	
	return 0;
}