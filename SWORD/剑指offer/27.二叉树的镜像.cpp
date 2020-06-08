/************************************************************************/
/*@File Name         : 27.�������ľ���.cpp
/*@Created Date      : 2020/6/8 16:11
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
	//�ݹ�汾
	void Mirror(TreeNode *pRoot) {

		if (pRoot == nullptr)
			return;
		TreeNode* tmp = nullptr;
		tmp = pRoot->right;
		pRoot->right = pRoot->left;
		pRoot->left = tmp;

		Mirror(pRoot->left);
		Mirror(pRoot->right);

	}
	//�����汾
	void Mirror_stack(TreeNode *pRoot) {
		if (pRoot == nullptr)
			return;
		queue<TreeNode*> q;
		q.push(pRoot);
		while (!q.empty()) {
			TreeNode* tmp = q.front();
			q.pop();
			if (tmp) {
				swap(tmp->left, tmp->right);
				q.push(tmp->left);
				q.push(tmp->right);
			}
		}
	}
};