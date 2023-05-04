#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>

using namespace std;


void Merge(vector<int>& R, int low, int mid, int high)
{
	vector<int> R1(high - low + 1);  //因为low,mid,high是索引
	int i = low;
	int j = mid + 1;   //子表2，必须加1
	int k = 0;
	while (i <= mid && j <= high)
	{
		if (R[i] < R[j])
		{
			R1[k] = R[i];
			i++;
			k++;
		}
		else
		{
			R1[k] = R[j];
			j++;
			k++;
		}
	}
	while (i <= mid)
	{
		R1[k] = R[i];
		i++;
		k++;
	}
	while (j <= high)
	{
		R1[k] = R[j];
		j++;
		k++;
	}

	for (k = 0, i = low; i <= high; i++, k++)
		R[i] = R1[k];
	R1.clear();
}


void MergePass(vector<int>& R, int length, int n)
{
	int i = 0;
	for (i = 0; i + 2 * length - 1 < n; i += 2 * length)
		Merge(R, i, i + length - 1, i + 2 * length - 1);
	//此时i为low
	if (i + length - 1 < n)
		Merge(R, i, i + length - 1, n - 1);
}
void MergeSort(vector<int>& R, int n)
{
	int length;
	for (length = 1; length < n; length = 2 * length)
		MergePass(R, length, n);
}

//两个有序列表的中位数，方法1，归并排序后找中位数
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	vector<int> nums3(nums1);
	nums3.reserve(nums1.size() + nums2.size());
	for (int i = 0; i < nums2.size(); i++)
		nums3.push_back(nums2[i]);
	MergeSort(nums3, nums3.size());

	int n = nums3.size();
	if (n % 2 == 0)
		return (double(nums3[n / 2 - 1]) + double(nums3[n / 2])) / 2.0;
	else
		return double(nums3[n / 2]);
}