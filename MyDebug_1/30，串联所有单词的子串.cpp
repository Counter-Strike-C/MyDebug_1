#include "Common.cpp"
//����1�������ڴ�����


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
				next[j] = k;  //��t[i]��s[i]��ƥ�� ������j=next[i]=>t[next[i]]
			else
				next[j] = next[k];
		}
		else
			k = next[k];   //����һ����ͬ�ַ�λ��
	}
}

vector<int> strStr(string haystack, string needle) {
	vector<int> next(needle.length());  //��ʼ��next����
	vector<int> result;
	GetNext(needle, next);
	int i = 0; int j = 0;
	while (i < (int)haystack.length())
	{
		while (i < (int)haystack.length() && j < (int)needle.length())     //ע���ʱҪ��ǿ��ת��
		{
			if (j == -1 || haystack[i] == needle[j])
			{
				i++;
				j++;
			}
			else j = next[j];   //i���䣬j���˵�next[j]
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