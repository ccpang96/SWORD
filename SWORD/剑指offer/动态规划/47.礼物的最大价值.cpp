 /************************************************************************/
 /*@File Name         : 47.礼物的最大价值.cpp
 /*@Created Date      : 2020/6/13 20:01
 /*@Author            : ccpang(ccpang96@163.com)
 /*@blog              : www.cnblogs.com/ccpang
 /*@Description       :
 /************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<sstream>
#include<queue>
#include<stack>
using namespace std;

 

class Solution {
public:
	int maxValue(vector<vector<int>>& grid) {
		if (grid.empty())
			return 0;
		int m = grid.size();
		int n = grid[0].size();
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (i == 0 && j == 0)
					continue;
				else if (i == 0)
					grid[i][j] += grid[i][j - 1];
				else if (j == 0)
					grid[i][j] += grid[i - 1][j];
				else grid[i][j] += max(grid[i][j - 1], grid[i - 1][j]);
			}
		}
		return grid[m-1][n-1];
	}
};
