/************************************************************************/
/*@File Name         : 28.对称的二叉树.cpp
/*@Created Date      : 2020/6/11 8:45
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : 请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
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
	bool isSymmetrical(TreeNode* pRoot)
	{
		return isSymmetrical(pRoot, pRoot);
	}
	bool isSymmetrical(TreeNode*pRoot1, TreeNode*pRoot2) {
		if (pRoot1 == nullptr && pRoot2 == nullptr)
			return true;
		if (pRoot1 == nullptr || pRoot2 == nullptr)
			return false;
		if (pRoot1->val != pRoot2->val)
			return false;
		return isSymmetrical(pRoot1->left, pRoot2->right) &&
			isSymmetrical(pRoot1->right, pRoot2->right);
	}
};
 


