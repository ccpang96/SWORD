/************************************************************************/
/*@File Name         : 12.�����е�·��.cpp
/*@Created Date      : 2020/6/9 20:22
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
	bool dfs(char* matrix, int cur_i , int cur_j,int rows, int cols, char* str, vector<vector<int>>&visit) {

		if (cur_i < 0 || cur_i >= rows || cur_j < 0 || cur_j >= cols || visit[cur_i][cur_j] == 1)
			return false;

		

		if (matrix[cur_i * cols + cur_j] != *str)
			return false;

		if(*(str+1) == 0)	//�ַ��������һ���ַ�
			return true;

		//�ɹ�ƥ�����Ϊ���ʹ�
		visit[cur_i][cur_j] = 1;
		str++;

		int dx[4] = { 1,-1,0,0 };
		int dy[4] = { 0,0,1,-1 };
		for (int index = 0; index < 4; index++) {
			int next_i = cur_i + dx[index], next_j = cur_j + dy[index];
			if (dfs(matrix, next_i, next_j, rows, cols, str, visit))
				return true;
			
		}

		//������ط�Ҫ����
		visit[cur_i][cur_j] = 0;	//���½����ʹ���Ԫ������Ϊδ���ʵ�
		return false;
	}

	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		if (matrix == nullptr || str == nullptr)
			return false;

		bool result = false;
		vector<vector<int>>visit(rows, vector<int>(cols, 0));
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (dfs(matrix, i,j,rows,cols,str,visit))
					result = true;
			}
		}
	
		return result;
	}
};

