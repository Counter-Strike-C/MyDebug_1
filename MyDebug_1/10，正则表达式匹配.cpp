#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <string>
#include <chrono>
using namespace std;

bool isMatch(string s, string p) {

	vector<vector<bool>> dp(s.length()+1, vector<bool>(p.length()+1,false));

	if (s.length() == 0 && p.length() == 0)return true;

	dp[0][0] = true;
	for (int j = 1;j < p.length()+1; j++)
		if (p[j - 1] == '*')dp[0][j] = dp[0][j - 2];

	for(int i=1;i<s.length() + 1; i++)
		for (int j = 1; j < p.length() + 1; j++)
		{
			if (s[i - 1] == p[j - 1] || p[j - 1] == '.')
				dp[i][j] = dp[i - 1][j - 1];
			else
			{
				if (p[j - 1] == '*')
				{
					if (s[i - 1] == p[j - 2] || p[j - 2] == '.')
					{
						dp[i][j] = dp[i][j - 2] || dp[i - 1][j - 2] || dp[i - 1][j];   //*前面重复0次，1次，n次的情况，转化成小问题
					}
					else
						dp[i][j] = dp[i][j - 2];    //考察s[i-1]和p[j-3]
				}
			}
		}

	return dp[s.length()][p.length()];
}

//void main()
//{
//	auto start1 = std::chrono::high_resolution_clock::now(); //记录当前时间
//	cout << isMatch("aab", "c*a*b") << endl;
//	auto end1 = std::chrono::high_resolution_clock::now(); //记录结束时间
//
//	std::chrono::duration<float> duration1 = end1 - start1; //记录经过了多长时间
//
//	std::cout << duration1.count() << "s" << std::endl; //输出运行时间
//
//	system("pause");
//}