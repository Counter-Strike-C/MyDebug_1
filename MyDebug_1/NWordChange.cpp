//N���α仯
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;
string convert(string s, int numRows) {
	int n = s.length();
	
	if ( numRows ==0)
		return s;

	vector<string> s1(numRows);
	int flag = 1;
	int idRows=0;
	for (int i = 0; i < n; i++)
	{
		s1[idRows].push_back(s[i]);
		idRows += flag; //��0~n֮������ת��
		if (idRows == numRows - 1 || idRows == 0)   //ת��
		{
			flag = -flag;
		}
	}
	string res;
	for (auto row : s1)
		res += row;
	return res;
}

