#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int reverse(int x) {
	int x1 = x;
	int res=0;
	while (x1 != 0)
	{
		int tmp = x1 % 10;
		//判断是否 大于 最大32位整数
		if (res > 214748364 || (res == 214748364 && tmp > 7)) {
			return 0;
		}
		//判断是否 小于 最小32位整数
		if (res < -214748364 || (res == -214748364 && tmp < -8)) {
			return 0;
			
		}
		res = res * 10 + tmp;
		x1 /= 10;
	}
	return res;

}

