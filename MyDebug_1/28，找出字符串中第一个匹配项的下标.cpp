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
//				next[j] = k;  //��t[i]��s[i]��ƥ�� ������j=next[i]=>t[next[i]]
//			else
//				next[j] = next[k];
//		}
//		else
//			k = next[k];   //����һ����ͬ�ַ�λ��
//	}
//}
//
//int strStr(string haystack, string needle) {
//	vector<int> next(needle.length());  //��ʼ��next����
//	GetNext(needle, next);
//	int i = 0; int j = 0;
//	while (i < (int)haystack.length() && j < (int)needle.length())     //ע���ʱҪ��ǿ��ת��
//	{
//		if (j == -1 || haystack[i] == needle[j])
//		{
//			i++;
//			j++;
//		}
//		else j = next[j];   //i���䣬j���˵�next[j]
//	}
//
//	if (j >= needle.size())
//		return i - needle.size();  //����ƥ��ģʽ���е����ַ�����
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