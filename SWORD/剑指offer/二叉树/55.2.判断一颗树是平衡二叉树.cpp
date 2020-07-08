/************************************************************************/
/*@File Name         : 55.2.判断一颗树是平衡二叉树.cpp
/*@Created Date      : 2020/6/12 17:04
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

 
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
	bool IsBalanced_Solution(TreeNode* pRoot) {
		//左右子树高度之差不超过1
		if (!pRoot)
			return false;
		bool result = true;
		int left = treeDepth(pRoot->left);
		int right = treeDepth(pRoot->right);
		if (abs(left - right) > 1)
			result = false;
		return result;
	}

	int treeDepth(TreeNode* pRoot) {
		if (!pRoot)
			return 0;
		int left = treeDepth(pRoot->left);
		int right = treeDepth(pRoot->right);
		return 1 + max(left, right);
	}
};