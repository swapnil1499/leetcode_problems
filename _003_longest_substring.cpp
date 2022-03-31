//
// Created by spatel on 2022-03-07.
//

#include <iostream>
#include <chrono>
#include <string>
#include <map>
#include <algorithm>

class Solution
{
public:
	int lengthOfLongestSubstring(std::string s)
	{
		// Set to store last position of seen char
		std::map<char, int> seen;
		int maxLen = 0;

		int i = 0;	// init index

		for (int j = 0; j < s.length(); j++)
		{
			// Check the last seen of [j] char
			if(seen.find(s[j]) != seen.end())
			{
				//if character was seen before,
				i = std::max(i, seen[s[j]] + 1);
			}

			seen[s[j]] = j;
			maxLen = std::max(maxLen, (j-i +1));
		}
		return maxLen;
	}
};

int main()
{

	// Start measuring time
	auto begin = std::chrono::high_resolution_clock::now();
	Solution solve;

	std::string s = "abcabcbb";
	int answer = solve.lengthOfLongestSubstring(s);

	std::cout << "String = " << s << "\n";
	std::cout << "\t" << answer << "\n";

	//printf("String = %s\n\t", s);
	//printf("%i\n\r",answer);

	// Stop measuring time and calculate the elapsed time
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
	std::cout << "Time measured " << (elapsed.count() * 1e-6) << " milliseconds.\n";
//	printf("Time measured: %.3f milliseconds.\n", elapsed.count() * 1e-6);
	return 0;
}