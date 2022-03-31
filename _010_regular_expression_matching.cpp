//
// Created by spatel on 2022-03-08.
//

/********************************************************************************

Given an input string s and a pattern p, implement regular expression
matching with support for '.' and '*' where:

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

Example 1:
	Input: s = "aa", p = "a"
	Output: false
	Explanation: "a" does not match the entire string "aa".

Example 2:
	Input: s = "aa", p = "a*"
	Output: true
	Explanation: '*' means zero or more of the preceding element, 'a'.
		Therefore, by repeating 'a' once, it becomes "aa".

Example 3:
	Input: s = "ab", p = ".*"
	Output: true
	Explanation: ".*" means "zero or more (*) of any character (.)".

Constraints:
	1 <= s.length <= 20
	1 <= p.length <= 30
	s contains only lowercase English letters.
	p contains only lowercase English letters, '.', and '*'.
	It is guaranteed for each appearance of the character '*',
		there will be a previous valid character to match.
********************************************************************************/

#include <iostream>
#include <chrono>

class Solution {
public:
	bool isMatch(string s, string p) {

	}
};

int main()
{

	// Start measuring time
	auto begin = std::chrono::high_resolution_clock::now();
	Solution solve;


	// Stop measuring time and calculate the elapsed time
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
	std::cout << "Time measured " << (elapsed.count() * 1e-6) << " milliseconds.\n";
	return 0;
}