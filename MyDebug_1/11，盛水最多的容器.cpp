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

int maxArea(vector<int>& height) {
	int i = 0;
	int j = height.size() - 1;
	int res=0;
	while (j > i)
		res = height[i] < height[j] ? max(res, (j - i) * height[i++]) : max(res, (j - i) * height[j--]);
	
	return res;
}

//void main()
//{
//	auto start1 = std::chrono::high_resolution_clock::now(); //记录当前时间
//	//cout << maxArea("aab", "c*a*b") << endl;
//	auto end1 = std::chrono::high_resolution_clock::now(); //记录结束时间
//
//	std::chrono::duration<float> duration1 = end1 - start1; //记录经过了多长时间
//
//	std::cout << duration1.count() << "s" << std::endl; //输出运行时间
//
//	system("pause");
//}