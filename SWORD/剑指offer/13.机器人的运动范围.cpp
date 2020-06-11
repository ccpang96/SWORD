/************************************************************************/
/*@File Name         : 13.�����˵��˶���Χ.cpp
/*@Created Date      : 2020/6/9 19:38
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : ������һ��m�к�n�еķ���һ�������˴�����0,0�ĸ��ӿ�ʼ�ƶ���ÿһ��ֻ�������ң��ϣ����ĸ������ƶ�һ��
���ǲ��ܽ�������������������λ֮�ʹ���k�ĸ��ӡ� ���磬��kΪ18ʱ���������ܹ����뷽��35,37������Ϊ3+5+3+7 = 18��
���ǣ������ܽ��뷽��35,38������Ϊ3+5+3+8 = 19�����ʸû������ܹ��ﵽ���ٸ����ӣ�*/
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

