/************************************************************************/
/*@File Name         : 32.3.按之字形打印二叉树.cpp
/*@Created Date      : 2020/6/11 8:15
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : 第一行是从左到右，第二行是从右到做打印....依次循环；与之对应的是按照S型打印：第一行是从右往左，第二行是从左往右...依次循环。
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
	vector<vector<int>> printSTree(TreeNode* root) {
		vector<vector<int>>result;

		if (!root)
			return result;
		deque<TreeNode*>q, p;
		q.push_back(root);
		vector<int>tmp;
		while (!q.empty()) {
			while (!q.empty()) {
				TreeNode* node = q.front();
				q.pop_front();
				if (node->left)
					p.push_back(node->left);
				if (node->right)
					p.push_back(node->right);

				tmp.push_back(node->val);
			}
			result.push_back(tmp);
			tmp.clear();
			while (!p.empty()) {
				TreeNode* node = p.back();
				p.pop_back();
				if (node->right)
					q.push_front(node->right);
				if (node->left)
					q.push_front(node->left);

				tmp.push_back(node->val);
			}
			result.push_back(tmp);
			tmp.clear();

		}
		return result;
	}
};

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

//将输入的一行数构建为二叉树
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


int main() {
	string input = "[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]";
	TreeNode* root = stringToTreeNode(input);
	vector<vector<int>>result = Solution().printSTree(root);
	for (auto &m : result) {
		for (auto &n : m)
			cout << n << " ";
		cout << endl;
	}


	system("pause");
	return 0;
}




