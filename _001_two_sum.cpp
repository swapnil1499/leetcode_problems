//
// Created by spatel on 2022-03-07.
//


/*
1. Two Sum
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:
  Input: nums = [2,7,11,15], target = 9
  Output: [0,1]
  Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
  Input: nums = [3,2,4], target = 6
  Output: [1,2]

Example 3:
  Input: nums = [3,3], target = 6
  Output: [0,1]

Constraints:
  2 <= nums.length <= 104
  -109 <= nums[i] <= 109
  -109 <= target <= 109
  Only one valid answer exists.
  */


#include <stdio.h>
#include <chrono>
#include <vector>
#include <unordered_map>

class Solution {
 public:
  std::vector<int> twoSum (std::vector<int>& nums, int target)
  {
	std::unordered_map<int, int> hashMap;

	for (size_t i = 0; i < nums.size (); i++)
	  {
		auto it = hashMap.find (target - nums[i]);

		if (it == hashMap.end ())
		  hashMap[nums[i]] = i;
		else
		  return std::vector<int>{ (int)i, it->second };
	  }
	return std::vector<int>{ 0, 0 };
  }
};

int main ()
{
  // Start measuring time
  auto begin = std::chrono::high_resolution_clock::now ();

  std::vector<int> nums = { 2, 7, 11, 15 };
  int target = 9;

  Solution solve;
  std::vector<int> answer;
  answer = solve.twoSum (nums, target);

  printf ("Answer is \n\t");
  for (size_t i = 0; i < answer.size (); i++)
	{
	  printf ("%i ", answer[i]);
	}

  printf ("\n\r");

  // Stop measuring time and calculate the elapsed time
  auto end = std::chrono::high_resolution_clock::now ();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin);
  printf ("Time measured: %.3f milliseconds.\n", elapsed.count () * 1e-6);
  return 0;
}