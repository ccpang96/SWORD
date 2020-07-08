/************************************************************************/
/*@File Name         : 55.二叉树的深度.cpp
/*@Created Date      : 2020/6/12 16:52
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
	int TreeDepth(TreeNode* pRoot)
	{
		if (!pRoot)
			return 0;

		int left = 0;
		int right = 0;
		if(pRoot->left)
			int left = TreeDepth(pRoot->left);
		if (pRoot->right)
			int right = TreeDepth(pRoot->right);
		return left > right ? left + 1 : right + 1;
	}
};