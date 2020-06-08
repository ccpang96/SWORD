/************************************************************************/
/*@File Name         : 32.从上到下打印二叉树.cpp
/*@Created Date      : 2020/6/8 19:11
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


//二叉树的层次遍历
class Solution {
public:
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int>result;
		if (root == nullptr)
			return result;

		queue<TreeNode*>q;
		q.push(root);
		while (!q.empty()) {
			TreeNode* node = q.front();
			q.pop();
			if (node != nullptr) {
				result.push_back(node->val);
				q.push(node->left);
				q.push(node->right);
			}
		}
		return result;
	}
};

