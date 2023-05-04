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
						dp[i][j] = dp[i][j - 2] || dp[i - 1][j - 2] || dp[i - 1][j];   //*ǰ���ظ�0�Σ�1�Σ�n�ε������ת����С����
					}
					else
						dp[i][j] = dp[i][j - 2];    //����s[i-1]��p[j-3]
				}
			}
		}

	return dp[s.length()][p.length()];
}

//void main()
//{
//	auto start1 = std::chrono::high_resolution_clock::now(); //��¼��ǰʱ��
//	cout << isMatch("aab", "c*a*b") << endl;
//	auto end1 = std::chrono::high_resolution_clock::now(); //��¼����ʱ��
//
//	std::chrono::duration<float> duration1 = end1 - start1; //��¼�����˶೤ʱ��
//
//	std::cout << duration1.count() << "s" << std::endl; //�������ʱ��
//
//	system("pause");
//}