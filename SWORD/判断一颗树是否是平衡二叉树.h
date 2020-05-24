#pragma once
#include<algorithm>
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
public:
	bool IsBalanced_Solution(TreeNode* pRoot) {
		//�������ϱ���
		return getDepth(pRoot) != -1; //��ȡ���������߶�֮��
	}
	int getDepth(TreeNode * root) {
		if (root == nullptr)
			return 0;
		int left = getDepth(root->left);
		if (left == -1) return -1; //��ƽ��
		int right = getDepth(root->right);
		if (right == -1) return -1;
		return abs(left - right) > 1 ? -1 : 1 + std::max(left, right);
	}
};