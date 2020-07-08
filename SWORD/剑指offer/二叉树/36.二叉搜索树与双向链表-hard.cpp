/************************************************************************/
/*@File Name         : 36.������������˫������.cpp
/*@Created Date      : 2020/6/9 7:16
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : ����һ�ö��������������ö���������ת����һ�������˫������Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��
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
	TreeNode * Convert(TreeNode* pRootOfTree)
	{
		TreeNode* pLastList = nullptr;
		convertNode(pRootOfTree, pLastList);

		TreeNode* res = pRootOfTree;
		while (res && res->left)
			res = res->left;
		return res;
	}

	void convertNode(TreeNode* cur, TreeNode* &pLastList) {
		if (!cur)
			return ;
		convertNode(cur->left, pLastList);

		cur->left = pLastList;
		if (pLastList) pLastList->right = cur;
		pLastList = cur;

		convertNode(cur->right, pLastList);
	}
};



class Input {

	void trimLeftTrailingSpaces(string &input) {
		input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
			return !isspace(ch);
		}));
	}

	void trimRightTrailingSpaces(string &input) {
		input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
			return !isspace(ch);
		}).base(), input.end());
	}

	TreeNode* stringToTreeNode(string input) {
		trimLeftTrailingSpaces(input);
		trimRightTrailingSpaces(input);
		input = input.substr(1, input.length() - 2);
		if (!input.size()) {
			return nullptr;
		}

		string item;
		stringstream ss;
		ss.str(input);

		getline(ss, item, ',');
		TreeNode* root = new TreeNode(stoi(item));
		queue<TreeNode*> nodeQueue;
		nodeQueue.push(root);

		while (true) {
			TreeNode* node = nodeQueue.front();
			nodeQueue.pop();

			if (!getline(ss, item, ',')) {
				break;
			}

			trimLeftTrailingSpaces(item);
			if (item != "null") {
				int leftNumber = stoi(item);
				node->left = new TreeNode(leftNumber);
				nodeQueue.push(node->left);
			}

			if (!getline(ss, item, ',')) {
				break;
			}

			trimLeftTrailingSpaces(item);
			if (item != "null") {
				int rightNumber = stoi(item);
				node->right = new TreeNode(rightNumber);
				nodeQueue.push(node->right);
			}
		}
		return root;
	}


};

//��һ����ת��Ϊ˫������
//int main() {
//
//	string input = "[5,3,7,2,4,6,8]";
//	TreeNode* root = stringToTreeNode(input);
//	TreeNode* result = Solution().Convert(root);
//
//	system("pause");
//	return 0;
//}