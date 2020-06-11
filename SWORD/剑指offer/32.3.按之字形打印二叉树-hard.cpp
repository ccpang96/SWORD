
/************************************************************************/
/*@File Name         : 32.3.按之字形打印二叉树.cpp
/*@Created Date      : 2020/6/11 8:15
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


//用两个栈来解决
class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int> >result;
		if (!pRoot)
			return result;
		stack<TreeNode*>levels[2];
		int current = 0;	//偶数层
		int next = 1;
		vector<int>rows;	//存储一行的值
		levels[current].push(pRoot);
		while (!levels[0].empty() || !levels[1].empty()) {
			TreeNode* node = levels[current].top();
			levels[current].pop();

			rows.push_back(node->val);

			if (current == 0) {
				if (node->left)
					levels[next].push(node->left);
				if (node->right)
					levels[next].push(node->right);
			}
			else {
				if (node->right)
					levels[next].push(node->right);
				if (node->left)
					levels[next].push(node->left);
			}

			//双方交互
			if (levels[current].empty()) {
				result.push_back(rows);
				rows.clear();
				current = 1 - current;
				next = 1 - next;
			}
		}

		return result;
	}
};