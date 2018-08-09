#include "stdafx.h"
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <array>
#include <boost/lambda/lambda.hpp>
#include <boost/algorithm/cxx11/one_of.hpp>
#include <boost/ptr_container/ptr_set.hpp>
#include <boost/ptr_container/indirect_fun.hpp>
#include <boost/array.hpp>
#include "Entry.h"
#include <fstream>

using namespace std;

bool operator<(const entry &a, const entry &b)
{
	return strcmp(a.name, b.name) < 0;
}

ClassA::ClassA()
{
	int a = 10, b = 20;
}

ClassA::ClassA(ClassA &obj) : a(obj.a), b(obj.b)
{
	cout << "ClassA copy constructor called" << endl;
}

void ClassA::PlayBoost()
{
	using namespace boost::lambda;
	typedef std::istream_iterator<int> in;

	std::for_each(
		in(std::cin), in(), std::cout << (_1 * 3) << "\n");
}

void ClassA::PlayBoost2()
{
	typedef boost::array<std::string, 3> array;
	array a;

	a[0] = "cat";
	a.at(1) = "shark";
	*a.rbegin() = "spider";

	std::sort(a.begin(), a.end());

	for (const std::string &s : a)
		std::cout << s << '\n';

	std::cout << a.size() << '\n';
	std::cout << a.max_size() << '\n';
}

void ClassA::PlayVec()
{
	string s[] = { "one", "two", "three", "three and half" };
	size_t sz = sizeof(*s);
	vector<string> vec(s, &s[sizeof(s) / sizeof(*s)]);
	vec.push_back("four");

	vector<string>::iterator it;
	vector<string>::iterator it_end = vec.end();
	for (it = vec.begin(); it != it_end; ++it)
	{
		cout << *it << endl;

	}

}

void ClassA::PlayMap()
{
	map<int, string> Employees;

	// 1) Assignment using array index notation
	Employees[5234] = "Mike C.";
	Employees[3374] = "Charlie M.";
	Employees[1923] = "David D.";
	Employees[7582] = "John A.";
	Employees[5328] = "Peter Q.";

	cout << "Employees[3374]=" << Employees[3374] << endl << endl;

	cout << "Map size: " << Employees.size() << endl;

	cout << endl << "Natural Order:" << endl;
	for (map<int, string>::iterator ii = Employees.begin(); ii != Employees.end(); ++ii)
	{
		cout << (*ii).first << ": " << (*ii).second << endl;
	}

	cout << endl << "Reverse Order:" << endl;
	for (map<int, string>::reverse_iterator ii = Employees.rbegin(); ii != Employees.rend(); ++ii)
	{
		cout << (*ii).first << ": " << (*ii).second << endl;
	}
}

typedef istream_iterator<int> istream_iter;

void ClassA::PlayBook1()
{

	const int N = 4;
	int a[N] = { 1234, 5432, 8943, 3346 };
	for_each(a, a + N, display());
	for_each(a, a + N, display());
}

void ClassA::PlayReverse()
{
	char str[] = "abcklmxyz";
	reverse(str, str + strlen(str));
	cout << str << endl;  // Output: zyxmlkcba
}

void ClassA::PlayReverse2()
{
	const int N = 4;
	int a[N] = { 1234, 5432, 8943, 3346 };
	int tmp;
	for (int i = 0, j = 3; i < j; i++, j--)
	{
		tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}
	copy(a, a + N, ostream_iterator<int>(cout, ","));
}

void ClassA::PlayReverse3()
{
	int a[4] = { 10, 20, 30, 40 };
	vector<int> v(a, a + 4);
	vector<int>::iterator it;
	vector<int>::reverse_iterator rit;
	int half = v.size() / 2;
	int tmp;
	for (int i = 0, j = 3; i < j; i++, j--)
	{
		tmp = v[i];
		v[i] = v[j];
		v[j] = tmp;
	}

	copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", "));
}

void ClassA::PlayReverse4()
{
	string a("abcdef");
	char tmp;
	for (int i = 0, j = a.length() - 1; i < j; i++, j--)
	{
		tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}
	cout << a << endl;
	//copy(a, a + N, ostream_iterator<int>(cout, ","));
}

void ClassA::PlayErastos()
{
	cout <<
		"To generate all prime numbers < N, enter N: ";
	long N, i, sqrtN, count = 0, j;
	cin >> N;
	sqrtN = int(sqrt(N)) + 1;
	vector<bool> S(N, true);

	// Initially, all S[i] are true.
	// S[i] = false if and when
	// we find i is not a prime number.
	// some prime number.

	for (i = 2; i < sqrtN; i++)
		if (S[i])
			for (int j = i*i; j<N; j += i) 
				S[j] = false;

	for (i = 2; i<N; i++)
		if (S[i]) { j = i; count++; }

	cout << "There are " << count
		<< " prime numbers less than N.\n";
	cout << "Largest prime number less than N is "
		<< j << "." << endl;
}

void ClassA::PlayCopy1()
{
	vector<int> a;
	ifstream file("example.txt");
	ofstream file_out("example_out.txt");
	if (file.fail())
	{
		cout << "Cannot open file example.txt.\n";
	}
	copy(istream_iter(file), istream_iter(), inserter(a, a.begin()));
	copy(a.begin(), a.end(), ostream_iterator<int>(file_out, ","));
	cout << endl;
}
ClassA::~ClassA()
{
}
