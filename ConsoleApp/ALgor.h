#pragma once
class Algor
{
public:
	void Func1(int n) {};
	// Output all Fibbonachi numbers
	void AllFibbTo(int nTop);
	int AllFibb(int nTop);
	int Factorial(int nTop);
	void quickSort(int arr[], int left, int right);
	void PrintArr(int arr[], int left, int right);

	Algor();
	virtual ~Algor();
private:
	int Fibb(int n1, int n2);

public:

};

