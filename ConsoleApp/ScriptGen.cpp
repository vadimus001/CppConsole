#include <sstream>
#include <fstream>
#include <cstddef>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include "ScriptGen.h"

using namespace std;
using namespace boost;

void ParseDataLine(char ch)
{
	int n = 0;
}

int ScriptGen::GenerateScript()
{
	int ret = 0;
	string line;
	string table;
	vector<string> cols;
	vector<vector<string> > data;

	ifstream infile(_fName);

	while (getline(infile, line))
	{
		trim(line);
		if (line.empty())
		{
			continue;
		}
		if (line.compare(0, _tableStart.length(), _tableStart) == 0)
		{
			PrintStmt(table, cols, data);
			table.clear();
			cols.clear();
			data.clear();
			size_t pos = line.find_first_not_of(" ", 3);
			table = line.substr(pos);
			continue;
		}
		if (line.compare(0, _colStart.length(), _colStart) == 0)
		{
			split(cols, line, is_any_of("\t "));
			cols.erase(cols.begin());
			//remove from cols empty strings
			cols.erase(remove(cols.begin(), cols.end(), ""), cols.end());
			continue;
		}
		data.push_back(ParseLine(line));
	}
	PrintStmt(table, cols, data);
	perror("stream eofbit error state");

	return ret;
}

ScriptGen::~ScriptGen()
{
}

void ScriptGen::PrintStmt(const string & table, const vector<string>& cols, const vector<vector<string> >& data)
{
	if (table.empty() && cols.empty() && data.empty())
		return;
	ofstream quFile("insert_stmt.sql", ios::out | ios::app);
	stringstream ss, finalSt;
	string s, sCols;
	ss << "INSERT [" << table << "] (";
	for (vector<string>::const_iterator it = cols.begin(); it != cols.end(); ++it)
	{
		it != cols.end() - 1 ? ss << "[" << *it << "], " : ss << "[" << *it << "])";
	}
	ss << " VALUES (";
	sCols = ss.str();

	for (vector<vector<string> >::const_iterator itD = data.begin(); itD != data.end(); ++itD)
	{
		for (vector<string>::const_iterator it = (*itD).begin(); it != (*itD).end(); ++it)
		{
			it != (*itD).end() - 1 ? ss << FormatData(*it) << ", " : ss << FormatData(*it) << ")";
		}
		ss << endl;
		ss << "GO" << endl;
		if (itD != data.end() - 1)
			ss << sCols;
	}
	if (quFile.is_open())
	{
		quFile << ss.str();
		quFile.close();
	}
}

string ScriptGen::FormatData(const string& str)
{
	string res;
	try 
	{
		int x = lexical_cast<int>(str);
	}
	catch (bad_lexical_cast const&) 
	{
		return "'" + str + "'";
	}
	return str;
}

//one or more tabs, two or more spaces, mix of tabs and spaces separate column data
vector<string> ScriptGen::ParseLine(const string & line)
{
	bool tab = false, still_blank = false, one_space = false, eol = false;
	int space_cnt = 0;
	vector<string> result, aux;
	std::string delimiter = " ";
	string str_buf;
	size_t last = 0, last2 = 0, next = 0;
	string::iterator it;
	while (!eol)
	{
		next = line.find_first_of(" \t", last == 0 ? last : last + 1);
		if (last == 0)
		{
			last = -1;
		}
		if (next == string::npos)
		{
			eol = true;
			next = line.length();
		}
		if (line[next] == '\t')
			tab = true;
		if (next - last == 1)// && last != 0)
		{
			still_blank = true;
			space_cnt++;
		}
		else
		{
			still_blank = false;
			if (space_cnt > 1)
				last2 = last;
			space_cnt = 1;
		}
		if (!still_blank && space_cnt == 1)
		{
			str_buf = last2 == 0 ? line.substr(last2, next - last2) : line.substr(last2 + 1, next - last2 - 1);
		}
		if (!str_buf.empty() && (space_cnt > 1 || eol))
		{
			aux = SplitTabs(str_buf);
			result.insert(result.end(), aux.begin(), aux.end());
			str_buf.clear();
		}
		last = next;
	}

	return result;
}

vector<string> ScriptGen::SplitTabs(const string & str)
{
	vector<string> res;
	split(res, str, is_any_of("\t"), token_compress_on);
	return res;
}

//void ParseCallBack(char ch)
//{
//}
