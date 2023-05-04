#include "Common.cpp"

//ÓÐÐ§À¨ºÅ
bool isValid(string s) {
	stack<char> stack;
	if (s.length() % 2 != 0)return false;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(' || s[i] == '{' || s[i] == '[')
		{
			stack.push(s[i]);
		}
		else
		{
			if (stack.empty())return false;

			if (s[i] == ')' && stack.top() == '(')
				stack.pop();
			else if (s[i] == '}' && stack.top() == '{')
				stack.pop();
			else if (s[i] == ']' && stack.top() == '[')
				stack.pop();
			else
				return false;
				
		}
	}
	if (stack.empty())return true;
	else return false;
}

