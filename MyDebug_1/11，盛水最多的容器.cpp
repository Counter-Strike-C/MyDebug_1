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
//	auto start1 = std::chrono::high_resolution_clock::now(); //��¼��ǰʱ��
//	//cout << maxArea("aab", "c*a*b") << endl;
//	auto end1 = std::chrono::high_resolution_clock::now(); //��¼����ʱ��
//
//	std::chrono::duration<float> duration1 = end1 - start1; //��¼�����˶೤ʱ��
//
//	std::cout << duration1.count() << "s" << std::endl; //�������ʱ��
//
//	system("pause");
//}