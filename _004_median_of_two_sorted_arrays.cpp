//
// Created by spatel on 2022-03-09.
//

/********************************************************************************

Given two sorted arrays nums1 and nums2 of size m and n respectively,
return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

Example 1:
	Input: nums1 = [1,3], nums2 = [2]
	Output: 2.00000
	Explanation: merged array = [1,2,3] and median is 2.

Example 2:
	Input: nums1 = [1,2], nums2 = [3,4]
	Output: 2.50000
	Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

Constraints:
	nums1.length == m
	nums2.length == n
	0 <= m <= 1000
	0 <= n <= 1000
	1 <= m + n <= 2000
	-106 <= nums1[i], nums2[i] <= 106
 ********************************************************************************/

#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
	{

		int m = nums1.size();            // A array
		int n = nums2.size();            // B array
		int mergedLen = m + n;

		// Ensures A is either smaller or equal to B
		if (m > n)
			return findMedianSortedArrays(nums2, nums1);

		int start = 0;
		int end = m;

		while (start <= end) {
			int i = (start + end) / 2;               // A Array
			int j = ((mergedLen + 1) / 2) - i;        // B Array

			int ALeftMax, BLeftMax, ARightMin, BRightMin;

			(i > 0) ? ALeftMax = nums1[i - 1] : ALeftMax = INT_MIN;
			((i + 1) < m) ? ARightMin = nums1[i] : ARightMin = INT_MAX;

			(j > 0) ? BLeftMax = nums2[j - 1] : BLeftMax = INT_MIN;
			((j + 1) < n) ? BRightMin = nums2[j] : BRightMin = INT_MAX;

			// Initial Partition is correct
			if (ALeftMax <= BRightMin && BLeftMax <= ARightMin) {
				// if Merged size is even
				if (mergedLen % 2 == 0) {
					return (max(ALeftMax, BLeftMax) + min(ARightMin, BRightMin)) / 2.0;
				}
				else {
					return max(ARightMin, BRightMin);
				}
			}
			else if (ALeftMax > BRightMin)
				end = i - 1;
			else
				start = i + 1;
		}

		return 0.0;
	}
};

int main()
{
	vector<int> nums1 = {1, 3};
	vector<int> nums2 = {2};

	cout << "Nums 1 = [ ";
	for(size_t i = 0; i < nums1.size(); i++)
		cout << nums1[i] << " ";
	cout << "]\n" << "Nums 2 = [ ";
	for(size_t i = 0; i < nums2.size(); i++)
		cout << nums2[i] << " ";
	cout << "]\n";

	// Start measuring time
	auto begin = chrono::high_resolution_clock::now();

	Solution solve;
	double answer = solve.findMedianSortedArrays(nums1, nums2);

	// Stop measuring time and calculate the elapsed time
	auto end = chrono::high_resolution_clock::now();
	auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);

	cout << "\tMedian = " << answer << "\n";
	cout << "Time measured " << (elapsed.count() * 1e-6) << " milliseconds.\n";
	return 0;
}