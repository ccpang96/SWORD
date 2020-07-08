/************************************************************************/
/*@File Name         : 13.机器人的运动范围.cpp
/*@Created Date      : 2020/6/9 19:38
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : 地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，
但是不能进入行坐标和列坐标的数位之和大于k的格子。 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。
但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？*/
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

	int dfs(int cur_i, int cur_j,vector<vector<int>>& visit, int threshold) {
		
		if (cur_i < 0 || cur_i >= visit.size() || cur_j < 0 || cur_j >= visit[0].size() || visit[cur_i][cur_j] == 1 )
			return 0;
		
		visit[cur_i][cur_j] = 1;

		int sumWithij = 0;
		string sum = to_string(cur_i) + to_string(cur_j);
		for (int i = 0; i < sum.size(); i++) {
			sumWithij += sum[i] - '0';
		}
		if (sumWithij > threshold)
			return 0;

		

		int dx[4] = { 1,-1,0,0 };
		int dy[4] = { 0,0,1,-1 };

		int result = 1;
		for (int index = 0; index < 4; index++) {
			int next_i = cur_i + dx[index], next_j = cur_j + dy[index];
			result+= dfs(next_i, next_j,visit,threshold);
		}
		return result;
	}

	int movingCount(int threshold, int rows, int cols) {
		if (rows <= 0 && cols <= 0)
			return 0;

		int result = 0;
		vector<vector<int>>visit(rows, vector<int>(cols, 0));
		result += dfs(0, 0, visit, threshold);
		return result;
	}


};

//int main() {
//	int result = Solution().movingCount(10, 1, 100);
//	cout << result << endl;
//	system("pause");
//	return 0;
//}

