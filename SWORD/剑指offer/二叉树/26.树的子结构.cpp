/************************************************************************/
/*@File Name         : 26.树的子结构.cpp
/*@Created Date      : 2020/6/8 16:00
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
	bool HasSubtree(TreeNode* s, TreeNode *t) {
		if (t == nullptr) return false;
		if (s == nullptr) return false;
		return isSameTree(s, t) || HasSubtree(s->left, t) || HasSubtree(s->right, t);
	}
	//判断两个子树相等是：t不一定要全部和s相等，也可以是s中的一部分
	bool isSameTree(TreeNode* s, TreeNode* t) {
		if (t == nullptr)
			return true;
		if (s == nullptr || s->val != t->val)
			return false;
		return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
	}
};
