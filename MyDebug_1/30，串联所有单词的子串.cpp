#include "Common.cpp"
//方法1，超出内存限制


void GetNext(string t, vector<int>& next)
{
	int j, k;
	j = 0; k = -1;
	next[0] = -1;
	while (j < t.length() - 1)
	{
		if (k == -1 || t[j] == t[k])
		{
			j++;
			k++;
			if (t[j] != t[k])
				next[j] = k;  //若t[i]和s[i]不匹配 索引到j=next[i]=>t[next[i]]
			else
				next[j] = next[k];
		}
		else
			k = next[k];   //最上一个相同字符位置
	}
}

vector<int> strStr(string haystack, string needle) {
	vector<int> next(needle.length());  //初始化next数组
	vector<int> result;
	GetNext(needle, next);
	int i = 0; int j = 0;
	while (i < (int)haystack.length())
	{
		while (i < (int)haystack.length() && j < (int)needle.length())     //注意此时要用强制转换
		{
			if (j == -1 || haystack[i] == needle[j])
			{
				i++;
				j++;
			}
			else j = next[j];   //i不变，j后退到next[j]
		}
		if (j == needle.size())
		{
			result.push_back(i - (int)needle.size());
		}
	}
	return result;

}

void swap(string& s1, string& s2)
{
	string tmp = s1;
	s1 = s2;
	s2 = tmp;
}

void getAllString(set<string>& result,vector<string>& words,int n,int index)
{
	if (index >= n)
	{
		string combination;
		for (auto it : words)
		{
			combination.append(it);
		}
		result.insert(combination);
	}
	else
	{
		for (int j = index; j < n; j++)
		{
			swap(words[index], words[j]);
			getAllString(result, words, n, index+ 1);
			swap(words[index], words[j]);	
		}
	}
	
}

vector<int> findSubstring(string s, vector<string>& words) {
	set<string> result;
	vector<int> out;
	getAllString(result, words, words.size(), 0);


	for (auto it : result)
	{
		vector<int> result = strStr(s, it);
		out.insert(out.end(), result.begin(), result.end());
	}

	return out;
}

void main()
{
	string s = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
		
	vector<string> words;
	words.push_back("fooo");
	words.push_back("barr");
	words.push_back("wing");
	words.push_back("ding");
	words.push_back("wing");

	for (auto it : findSubstring(s, words))
	{
		cout << it << endl;
	}
	system("pause");
}