/************************************************************************/
/*@File Name         : 54.�����������ĵ�k��ڵ�.cpp
/*@Created Date      : 2020/6/10 16:00
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : ����һ�ö��������������ҳ����еĵ�kС�Ľ�㡣���磬 ��5��3��7��2��4��6��8��    �У��������ֵ��С˳�����С����ֵΪ4��
/*@˼·�����ǿ�����������������*/
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
		//�����쳣ֵ�ж�
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
