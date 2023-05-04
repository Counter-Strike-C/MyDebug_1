#include "Common.cpp"

void backTrack(vector<string>& result, const unordered_map<char, string>& maps, const string& digits, int index, string& combination)
{
	if (index == digits.length())
	{
		result.push_back(combination);
	}
	else
	{
		char c = digits[index];
		string letters = maps.at(c);
		for (auto it : letters)
		{
			combination.push_back(it);
			backTrack(result, maps, digits, index + 1, combination);
			combination.pop_back();
		}
	}
}

vector<string> letterCombinations(string digits) {
	unordered_map<char, string> maps =
	{
		{'2',"abc"},
		{'3',"def"},
		{'4',"ghi"},
		{'5',"jkl"},
		{'6',"mno"},
		{'7',"pqrs"},
		{'8',"tuv"},
		{'9',"wxyz"},
	};
	vector<string> result;
	if (digits.empty())
		return result;
	string combination;
	backTrack(result, maps, digits, 0, combination);
	return result;
}



//void main()
//{
//	letterCombinations("232");
//}