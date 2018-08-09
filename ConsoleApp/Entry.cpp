#include "Entry.h"
#include <iostream>

void display::operator()(int x)
{
	std::cout << "a[" << i++ << "] = " << x << std::endl;
}