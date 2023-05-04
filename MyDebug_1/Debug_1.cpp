#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>

using namespace std;



////调试无重复字符最长子串
//int lengthOfLongestSubstring(string s) {
//	unordered_map <char,int> m1;
//	char c = s.c_str()[0];
//	m1.insert(pair<char, int>(c, 0));
//	int maxlen=0;
//	for (int i = 1; i < s.length(); i++)
//	{
//		char tmp = s.c_str()[i];
//		cout << tmp << endl;
//		unordered_map <char, int>::iterator it;
//		if (m1.count(tmp))
//		{
//			 it = m1.find(tmp);
//			 m1.erase(m1.begin(),++it);
//			 m1.insert(pair<char, int>(tmp, i));
//		}
//		else
//		{
//			m1.insert(pair<char, int>(tmp, i));
//		}
//		
//		maxlen = max(maxlen,int(m1.size()));
//	}
//	return maxlen;
//}

//调试无重复字符最长子串
int lengthOfLongestSubstring(string s) {
	vector<char> m1;
	char c = s.c_str()[0];
	m1.push_back(c);
	int maxlen = 0;
	if (s.length() == 0) return 0;
	if (s.length() == 1) return 1;
	for (int i = 1; i < s.length(); i++)
	{
		char tmp = s.c_str()[i];
		
		vector <char>::iterator it=m1.begin();
		for (; it != m1.end(); ++it)
		{
			if (*it == tmp)
			{
				m1.erase(m1.begin(), it + 1);
				break;
			}
				
		}
		m1.push_back(tmp);
		maxlen = max(maxlen, int(m1.size()));
	}
	return maxlen;
}


