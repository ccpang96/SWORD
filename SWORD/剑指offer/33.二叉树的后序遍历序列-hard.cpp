/************************************************************************/
/*@File Name         : 33.�������ĺ����������.cpp
/*@Created Date      : 2020/6/8 19:17
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : ����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ��������������Yes,�������No���������������������������ֶ�������ͬ��
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

 

//ʹ�õݹ�ķ���
class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		//�ݹ��жϣ����ڵ�λ����������һλ�����ڵ��ֵҪ������������ֵ��С����������ֵ
		int length = sequence.size();
		return verify(sequence, 0, length -1);
	}

	bool verify(vector<int>sequence,int start,int end) {
		if (sequence.empty() || start > end)
			return false;

		//���ڵ�
		int root = sequence[end];

		//���������е�������
		int i = start;
		for (; i < end-1; i++) {
			if (sequence[i] > root)
				break;
		}

		//���������е�������
		int j = i;
		for (; j < end -1; j++) {
			if (sequence[j] < root)
				return false;
		}

		bool left = true;
		if (i > start)
			left = verify(sequence, start,i - 1);

		bool right = true;
		if (i < end - 1)
			right = verify(sequence, i, end - 1);

		return left & right;
	}
};


//ʹ�õ����ķ���
