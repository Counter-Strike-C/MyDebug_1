//������ִ�
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

	//��̬�滮����
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
					dp[i][j] = true;   //��ʱ����Ϊ2��1����s[i]=s[j],����Ϊtrue
				else
				{
					dp[i][j] = dp[i + 1][j - 1];  //״̬ת��
				}
			}

			if (dp[i][j] && j - i + 1 > maxlen) {
				maxlen = j - i + 1;
				begin = i;  //��¼Ŀ���Ӵ���ʼλ��
			}
		}

	return s.substr(begin, maxlen);
}

