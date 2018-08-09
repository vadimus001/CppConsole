// ConsoleApp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


using namespace std;

int main()
{
	ClassA cA;
	//cA.PlayErastos();
	ClassB* b = dynamic_cast<ClassB*> (new ClassA);
	ClassA* a = new ClassB;


	//cA.PlayBook1();
	//Algor alg;
	//int arr[] = { 23, 12, 6, 22, 34, 14, 25, 9, 19, 20, 3 };
	//for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	//{
	//	cout << arr[i] << " ";
	//}
	//cout << endl;
	//alg.quickSort(arr, 0, 10);
	//for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	//{
	//	cout << arr[i] << " ";
	//}
	//cout << endl;

	///////////////////////////////////////////////////////////////////////////////////
	ScriptGen sg;
	sg.GenerateScript();
	///////////////////////////////////////////////////////////////////////////////////


	try
	{
		//cout << alg.Factorial(10) << endl;
		//cout << alg.AllFibb(10) << endl;

	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;// "Bad parameter";
	}    
	return 0;
}



