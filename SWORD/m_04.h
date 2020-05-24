#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;



//1.����������������ķ���
//ִ����ʱ :88 ms, ������ C++ �ύ�л�����5.08% ���û�
//�ڴ�����:13 MB, ������ C++ �ύ�л�����100.00%���û�
class Solution {
public:
	bool dfs(vector<vector<int>>&matrix, int cur_i, int cur_j, int target) {
		if (matrix[cur_i][cur_j] == target)
			return true;
		else
			return false;
		//������������,���£������½�
		int di[3] = { 1,0,1 };
		int dj[3] = { 0,1,1 };
		for (int index = 0; index != 3; ++index) {
			int next_i = cur_i + di[index], next_j = cur_j + dj[index];
			if (dfs(matrix, next_i, next_j, target))
				return true;
		}
	}

	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
		bool find = false;
		for (int i = 0; i < matrix.size(); ++i)
			for (int j = 0; j < matrix[0].size(); ++j)
				if (dfs(matrix, i, j, target))
					find = true;
		return find;
	}
};

//2.���ý�ָoffer�ϵķ�����ѡȡ���½ǻ������Ͻǣ��ų�һ�л���һ�е����ݡ�
//ִ����ʱ :60 ms, ������ C++ �ύ�л�����11.82% ���û�
//�ڴ�����:13.2 MB, ������ C++ �ύ�л�����100.00%���û�
class Solution {
public:
	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
		bool found = false;

		if (matrix.size() == 0)
			return false;

		int column = 0, row = matrix.size() - 1; //�����½ǿ�ʼ����
		while (column < matrix[0].size() && row >= 0) {
			if (matrix[row][column] == target) {
				found = true;
				break;
			}
			else if (matrix[row][column] < target) {
				column++; //��ǰֵ��Ŀ��ֵС��˵����ǰֵ���ڵ���һ�ж����У������ߣ�����+1
			}
			else {
				//��ǰֵ�ȵ�Ŀ��ֵ�󣬴�ʱֻ����������
				row--;
			}
		}
		return found;
	}
};

 
