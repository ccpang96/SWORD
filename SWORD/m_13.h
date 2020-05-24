#pragma once
#include<iostream>
#include<vector>
using namespace std;



//ִ����ʱ:4 ms, ������ C++ �ύ�л�����81.25% ���û�
//�ڴ����� : 7.7 MB, ������ C++ �ύ�л�����100.00%���û�
class Solution {
public:
	bool caculateSumOfRowColumn(int cur_i, int cur_j, int k) {
		int sum = 0;
		if (cur_i == 100)
			sum += 1;
		else
			sum += cur_i / 10 + cur_i % 10;
		if (cur_j == 100)
			sum += 1;
		else
			sum += cur_j / 10 + cur_j % 10;

		if (sum <= k)
			return true;
		else
			return false;
	}

	int dfs(int cur_i, int cur_j, int k, vector<vector<int>>& visit) {

		int count = 0;
		if (cur_i < 0 || cur_j < 0 || cur_i == visit.size() || cur_j == visit[0].size() || visit[cur_i][cur_j] == 1 || caculateSumOfRowColumn(cur_i, cur_j, k) == false)
			return 0;

		visit[cur_i][cur_j] = 1;
		count += 1;
		int di[4] = { 1,-1,0,0 };
		int dj[4] = { 0,0,1,-1 };

		for (int index = 0; index < 4; index++) {
			int next_i = cur_i + di[index], next_j = cur_j + dj[index];
			count += dfs(next_i, next_j, k, visit);
		}
		return count;
	}

	int movingCount(int m, int n, int k) {

		vector<vector<int>>visit;
		vector<int>temp(n);
		visit.resize(m, temp);

		int ans = dfs(0, 0, k, visit);
		return ans;
	}
};

int main() {

	int m = 1, n = 2, k = 1;
	cout << Solution().movingCount(m, n, k);
	system("pause");
	return 0;
}
