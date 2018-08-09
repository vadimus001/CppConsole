#include "stdafx.h"
#include "ALgor.h"

using namespace std;

void Algor::AllFibbTo(int nTop)
{
	if (nTop == 1 || nTop == 2)
	{
		cout << 1 << endl;
		return;
	}
	int nAux = 0;
	cout << "1 1 2 ";
	for (size_t i = 2; i < nTop - 1; i++)
	{
		nAux = Fibb(i - 1, i);
		cout << nAux << " ";
	}
	cout << endl;
}

int Algor::AllFibb(int nTop)
{
	if (nTop == 1 || nTop == 2)
	{
		cout << 1 << endl;
		return 1;
	}
	int n1 = 1, n2 = 1, n3 = 0;
	for (int i = 0; i < nTop - 2; i++)
	{
		n3 = n1 + n2;
		n1 = n2;
		n2 = n3;
	}
	return n3;
}

int Algor::Factorial(int nTop)
{
	if (nTop < 0)
	{
		//cout << "Bad parameter" << endl;
		throw exception("Bad parameter");
		//return 0;
	}
	if (nTop == 0 || nTop == 1)
	{
		//cout << 1 << endl;
		return 1;
	}
	//int nAux = nTop * Factorial(nTop - 1);
	int nAux = 1;
	for (int i = 1; i <= nTop; i++)
	{
		nAux *= i;
	}
			
	return nAux;


	//for (size_t i = 2; i < nTop; i++)
	//{
	//	nAux = Factorial(i) * (i + 1);
	//	cout << nAux << " ";
	//}



}
//{ 23, 12, 6, 22, 34, 14, 25, 9, 19, 20, 3 }
void Algor::quickSort(int arr[], int left, int right)
{
	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];

	/* partition */
	while (i <= j) {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	};
	PrintArr(arr, left, right + 1);

	/* recursion */
	if (left < j)
		quickSort(arr, left, j);
	if (i < right)
		quickSort(arr, i, right);
}

void Algor::PrintArr(int arr[], int left, int right)
{

	for (size_t i = left; i < right; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

Algor::Algor()
{
}


Algor::~Algor()
{
}

int Algor::Fibb(int n1, int n2)
{
	int n = 0;
	return n1 + n2;
}