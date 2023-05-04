#include "Common.cpp"

vector<vector<int>> threeSum(vector<int>& nums) {
	int n = nums.size();
	vector<vector<int>>result;
	sort(nums.begin(), nums.end());  //��С��������

	for (int first = 0; first < n; first++)
	{
		if (first > 0 && nums[first] == nums[first - 1])
			continue;
		int third = n - 1;
		int target = -nums[first];
		for (int second = first + 1; second < n; ++second)
		{
			if (second > first + 1 && nums[second] == nums[second - 1])
				continue;

			while (second < third && (nums[second] + nums[third--]) > target);  //�ҵ������second��third
			if (second == third)
				break;   //�Ҳ��������second��third

			if ((nums[second] + nums[third]) == target)
				result.push_back({ nums[first],nums[second],nums[third] });
		}
	}
	return result;

}

