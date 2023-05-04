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

bool isPalindrome(int x) {
	if (x < 0)return false;

	if (x / 10 == 0)return true;

	vector<int>nums;
	while (x != 0)
	{
		nums.push_back(x % 10);
		x /= 10;
	}

	for (auto itb = nums.begin(), ite = nums.end()-1;; ++itb, --ite)
	{
		if (ite - itb == 0 || ite - itb == 1 && *itb == *ite)return true;
		if (*itb != *ite)return false;
	}
}

//方法2
bool isPalindrome_2(int x)
{
	if (x < 0 || (x % 10 == 0 && x != 0))
		return false;

	int num=0;
	while (x > num)
	{
		num += num * 10 + x % 10;
		x /= 10;
	}

	return x == num || x == num / 10;
}

//void main()
//{
//	auto start1 = std::chrono::high_resolution_clock::now(); //记录当前时间
//	cout << isPalindrome(12321) << endl;
//	auto end1 = std::chrono::high_resolution_clock::now(); //记录结束时间
//
//	std::chrono::duration<float> duration1 = end1 - start1; //记录经过了多长时间
//
//	std::cout << duration1.count() << "s" << std::endl; //输出运行时间
//
//	auto start2 = chrono::high_resolution_clock::now(); //记录当前时间
//	cout << isPalindrome_2(12321) << endl;
//	auto end2 = std::chrono::high_resolution_clock::now(); //记录结束时间
//
//	std::chrono::duration<float> duration2 = end2 - end2; //记录经过了多长时间
//
//	std::cout << duration2.count() << "s" << std::endl; //输出运行时间
//	system("pause");
//}