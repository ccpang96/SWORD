/************************************************************************/
/*@File Name         : 54.二叉搜索树的第k大节点.cpp
/*@Created Date      : 2020/6/10 16:00
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : 给定一棵二叉搜索树，请找出其中的第k小的结点。例如， （5，3，7，2，4，6，8）    中，按结点数值大小顺序第三小结点的值为4。
/*@思路：就是考察二叉树的中序遍历*/
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
	TreeNode * KthNode(TreeNode* pRoot, int k)
	{
		TreeNode* result = nullptr;
		//输入异常值判断
		if (pRoot == nullptr)
			return result;

		stack<TreeNode*> stack1;
		TreeNode* cur = pRoot;
		while (cur != nullptr || !stack1.empty()) {
			while (cur != nullptr) {
				stack1.push(cur);
				cur = cur->left;
			}
			if (!stack1.empty()) {
				cur = stack1.top();
				stack1.pop();

				k--;
				if (k == 0) {
					result = cur;
					break;
				}

				cur = cur->right;
			}
			
		}
		return result;
	}
};
