#include <iostream>
#include "todo.hpp"

int main(){

	Todo.init();

	List f("banana");
	std::cout << f.name<<std::endl;

	for (listObj obj : f.getObj()){

		std::cout << obj.isDone << ":" << obj.desc << std::endl;

	}

	return 0;
}
