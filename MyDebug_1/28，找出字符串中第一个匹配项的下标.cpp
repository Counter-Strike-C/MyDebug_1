//#include "Common.cpp"
//
//void GetNext(string t,vector<int>& next)
//{
//	int j, k;
//	j = 0; k = -1;
//	next[0] = -1;
//	while (j < t.length() - 1)
//	{
//		if (k == -1 || t[j] == t[k])
//		{
//			j++;
//			k++;
//			if (t[j] != t[k])
//				next[j] = k;  //若t[i]和s[i]不匹配 索引到j=next[i]=>t[next[i]]
//			else
//				next[j] = next[k];
//		}
//		else
//			k = next[k];   //最上一个相同字符位置
//	}
//}
//
//int strStr(string haystack, string needle) {
//	vector<int> next(needle.length());  //初始化next数组
//	GetNext(needle, next);
//	int i = 0; int j = 0;
//	while (i < (int)haystack.length() && j < (int)needle.length())     //注意此时要用强制转换
//	{
//		if (j == -1 || haystack[i] == needle[j])
//		{
//			i++;
//			j++;
//		}
//		else j = next[j];   //i不变，j后退到next[j]
//	}
//
//	if (j >= needle.size())
//		return i - needle.size();  //返回匹配模式串中的首字符索引
//	else
//		return -1;
//}
//
////void main()
////{
////	string s = "hello";
////	string t = "ll";
////	cout << strStr(s, t);
////	system("pause");
////}