#pragma once
#include <string>
#include <vector>

using namespace std;

class ScriptGen
{
public:
	ScriptGen(string fileName = "tableData.txt") : _fName(fileName)
	{
	}

	int GenerateScript();
	virtual ~ScriptGen();
private:
	void PrintStmt(const string& table, const vector<string>& cols, const vector<vector<string> >& data);
	string FormatData(const string&);
	vector<string> ParseLine(const string& line);
	vector<string> SplitTabs(const string& line);
	//static void ParseCallBack(char ch);
	string _fName;
	string _tableStart = "@@t ";
	string _colStart = "@@c ";
	vector<string> wordDelim = {" "};
};

