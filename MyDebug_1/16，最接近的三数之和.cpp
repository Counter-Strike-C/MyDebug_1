#include "Common.cpp"

using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
	int n = nums.size();
	sort(nums.begin(), nums.end());  //从小到大排序
	int result = 0;
	int minNum = 1e7;


	// 根据差值的绝对值来更新答案
	auto update = [&](int cur) {
		if (abs(cur - target) < abs(result - target)) {
			result = cur;
		}
	};

	for (int first = 0; first < n; first++)
	{
		if (first > 0 && nums[first] == nums[first - 1])
			continue;
		int third = n - 1;

		int second = first + 1;

		while (second < third)
		{
			int sum = nums[second] + nums[third] + nums[first];
			if (sum == target)
				return sum;
			update(sum);
			if (sum > target)
			{
				int third0 = third - 1;
				while (second < third0 && nums[third0] == nums[third])
					--third0;
				third = third0;
			}
			else
			{
				int second0 = second + 1;
				while (second0 < third && nums[second] == nums[second0])
					++second0;
				second = second0;
			}

		};  //找到满足的second和third

	}
	return result;

}

