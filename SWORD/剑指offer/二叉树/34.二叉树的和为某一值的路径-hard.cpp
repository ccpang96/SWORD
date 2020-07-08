/************************************************************************/
/*@File Name         : 34.二叉树的和为某一值的路径-hard.cpp
/*@Created Date      : 2020/6/8 20:05
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


//在本题中，有多条路径
class Solution {
public:
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		vector<vector<int>>result;
		vector<int>path;
		if (find(root, expectNumber, result,path))
			return result;
	}

	bool find(TreeNode* root, int number, vector<vector<int>>&result,vector<int>path) {
		if (root == nullptr)
			return false;

		path.push_back(root->val);

		if (root->left == nullptr && root->right == nullptr && root->val == number) {
			result.push_back(path);
			return true;
		}
		
		bool left = find(root->left, number - root->val, result,path);
		bool right = find(root->right, number - root->val, result,path);

		path.pop_back();

		if (left || right)
			return true;

		
	}
};