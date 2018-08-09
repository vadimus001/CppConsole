#pragma once
#include <string>

struct entry {
	long nr;
	char name[30];
};	

class display
{
public:
	display() : i(0) {};
	void operator()(int x);
	~display() {};

private:
	int i;
};

