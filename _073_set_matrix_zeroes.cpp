//
// Created by spatel on 2022-04-22.
//

/********************************************************************************

Given an m x n integer matrix matrix, if an element is 0,
set its entire row and column to 0's.

You must do it in place.


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
********************************************************************************/

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		bool col0 = true;
		int rows = matrix.size();
		int cols = matrix[0].size();

		// Check if 0 is present in first row or column

		for (int i = 0; i < rows; i++)
		{
			if (matrix[i][0] == 0)
				col0 = false;

			for (int j = 1; j < cols; j++)
			{
				if(matrix[i][j] == 0)
				{
					matrix[0][j] = 0;
					matrix[i][0] = 0;
				}
			}
		}

		for (int i = rows -1; i >=0; i--)
		{
			for (int j = cols -1; j >= 1; j--)
			{
				if(matrix[i][0] == 0 || matrix[0][j] == 0)
					matrix[i][j] = 0;

			}
			if(col0 == false)
				matrix[i][0] = 0;
		}

	}
};

int main()
{
	//using namespace std;
	vector<vector<int>> matrix =
		{
			{0, 1, 2, 0},
			{3, 4, 5, 2},
			{1, 3, 1, 5}
		};

	cout <<"Input:\n";

	for (int i = 0; i < matrix.size(); i++)
	{
		cout <<"\t";
		for (int j = 0; j < matrix[i].size(); j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout <<"\n";
	}

	// Start measuring time
	auto begin = std::chrono::high_resolution_clock::now();
	Solution solve;

	solve.setZeroes(matrix);

	// Stop measuring time and calculate the elapsed time
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

	cout <<"Solution:\n";

	for (int i = 0; i < matrix.size(); i++)
	{
		cout <<"\t";
		for (int j = 0; j < matrix[i].size(); j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout <<"\n";
	}

	std::cout << "Time measured " << (elapsed.count() * 1e-6) << " milliseconds.\n";
	return 0;
}