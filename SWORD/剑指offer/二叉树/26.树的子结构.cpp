/************************************************************************/
/*@File Name         : 26.�����ӽṹ.cpp
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
	//�ж�������������ǣ�t��һ��Ҫȫ����s��ȣ�Ҳ������s�е�һ����
	bool isSameTree(TreeNode* s, TreeNode* t) {
		if (t == nullptr)
			return true;
		if (s == nullptr || s->val != t->val)
			return false;
		return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
	}
};
