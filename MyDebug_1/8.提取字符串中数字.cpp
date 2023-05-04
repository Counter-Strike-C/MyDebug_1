#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int myAtoi(string s)
{
	while (s != "" && s[0] == ' ')s.erase(0, 1);     //去除空格号
	if (s == "")return 0;
	bool negative = s[0] == '-' ? true : false;  //获取符号
	if (negative || s[0] == '+')s.erase(0, 1);   //去除+和-号、
	if (s == "")return 0;      //如果去除符号后，此时字符串为空
	long long nums=0;
	auto it = s.begin();
	for (; it != s.end() && (*it) - '0' >= 0 && (*it) - '9' <= 0; ++it)
	{
		nums *= 10;
		nums += (*it) - '0';   //转化为数字
		if (nums > (long long)INT_MAX || nums < (long long)INT_MIN)
			return negative ? INT_MIN : INT_MAX;
	}
	return negative ? -nums : nums;
}
