/************************************************************************/
/*@File Name         : 33.二叉树的后序遍历序列.cpp
/*@Created Date      : 2020/6/8 19:17
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
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

 

//使用递归的方法
class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		//递归判断，根节点位于数组的最后一位，根节点的值要大于左子树的值，小于右子树的值
		int length = sequence.size();
		return verify(sequence, 0, length -1);
	}

	bool verify(vector<int>sequence,int start,int end) {
		if (sequence.empty() || start > end)
			return false;

		//根节点
		int root = sequence[end];

		//遍历完所有的左子树
		int i = start;
		for (; i < end-1; i++) {
			if (sequence[i] > root)
				break;
		}

		//遍历完所有的右子树
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


//使用迭代的方法
