//最长回文字串
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>

using namespace std;
string longestPalindrome(string s) {
	int length = s.length();
	if (length < 2)
		return s;

	int maxlen = 1;
	int begin = 0;

	//动态规划数组
	vector<vector<bool>> dp(length, vector<bool>(length));
	for (int i = 0; i < length; i++)
		dp[i][i] = true;

	for (int L = 2; L < length; L	++)
		for (int i = 0; i <length; i++)
		{
			int j = L + i - 1;

			if (j >= length)
				break;
			if (s[i] != s[j])
			{
				dp[i][j] = false;
			}
			else
			{
				if (j - i < 3)
					dp[i][j] = true;   //此时长度为2或1，而s[i]=s[j],所以为true
				else
				{
					dp[i][j] = dp[i + 1][j - 1];  //状态转移
				}
			}

			if (dp[i][j] && j - i + 1 > maxlen) {
				maxlen = j - i + 1;
				begin = i;  //记录目标子串起始位置
			}
		}

	return s.substr(begin, maxlen);
}

