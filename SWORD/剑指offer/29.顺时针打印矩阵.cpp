/************************************************************************/
/*@File Name         : 29.顺时针打印矩阵.cpp
/*@Created Date      : 2020/6/8 16:24
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
	vector<int> printMatrix(vector<vector<int> > matrix) {
		int m = matrix.size();
		int n = matrix[0].size();
		vector<int>result;
		if (matrix.empty()) return result;
		
		float k = float(min(m, n)) / 2.0 + 0.5;
		for (int i = 0; i < int(k); i++) {
			printCircle(result, matrix, i, i, n - i-1, m - i-1);
		}
		return result;
	}
	//一圈一圈的打印
	void printCircle(vector<int>&result, vector<vector<int>>matrix,int i, int j,int column,int row) {
		//先打印上边
		for (int k = j; k <= column; k++) {
			result.push_back(matrix[i][k]);
		}
		//打印右边
		for (int k = i + 1; k <= row; k++) {
			result.push_back(matrix[k][column]);
		}
		//打印下边
		for (int k = column - 1; (k >= j)&&(row != i); k--) {
			result.push_back(matrix[row][k]);
		}
		//打印左边
		for (int k = row - 1; (k > i)&&(column != j); k--)
			result.push_back(matrix[k][j]);
		
	}
};

//int main() {
//	
//	vector<int>result;
//	//vector<vector<int>>matrix{ {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
//	vector<vector<int>>matrix{ { 1},{2},{3},{4},{5} };
//
//	result = Solution().printMatrix(matrix);
//	for (auto &m : result)
//		cout << m << endl;
//	system("pause");
//	return 0;
//}
