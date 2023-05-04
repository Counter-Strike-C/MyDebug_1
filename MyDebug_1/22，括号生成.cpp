#include "Common.cpp"

void backTrack(vector<string>& s, int open, int close, int n, string &combination)
{
	if (combination.size() == 2*n)
	{
		s.push_back(combination);
		return;
	}

	if (open > close)
		return;

	if (open > 0)
	{
		combination.push_back('(');
		backTrack(s, open-1, close, n, combination);
		combination.pop_back();
	}

	if (close >0)
	{
		combination.push_back(')');
		backTrack(s, open, close-1, n, combination);
		combination.pop_back();
	}
}

vector<string> generateParenthesis(int n) {

	vector<string> s;
	if (n == 0)return s;
	string combination;
	backTrack(s, n, n, n, combination);
	return s;
}



void main()
{
	for (auto it : generateParenthesis(3))
	{
		cout << it << endl;
	}
}