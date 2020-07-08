/************************************************************************/
/*@File Name         : 37.���л�������.cpp
/*@Created Date      : 2020/6/13 15:05
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       :
/************************************************************************/


//ʹ��BFS����deque
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



class Codec {
public:
	//���л�
	string serialize(TreeNode* root) {
		string result;
		if (root == nullptr)
			return result;
		queue<TreeNode*>q1;
		q1.push(root);
		while (!q1.empty()) {
			TreeNode* node = q1.front();
			q1.pop();

			//����ǿսڵ�
			if (node == nullptr) {
				result += "null,";
				continue;
			}

			result += to_string(node->val) + ",";
			q1.push(node->left);
			q1.push(node->right);

		}

		return result;
	}

	//�����л�
	TreeNode* deserialize(string input) {
		//ȥ���������������

		if (input.empty())
			return nullptr;

		string item;
		stringstream ss;
		ss.str(input);
		getline(ss, item, ',');

		TreeNode* root = new TreeNode(stoi(item));
		queue<TreeNode*>q1;
		q1.push(root);
		while (true) {
			TreeNode* node = q1.front();
			q1.pop();

			if (!getline(ss, item, ','))
				break;

			if (item != "null") {
				node->left = new TreeNode(stoi(item));
				q1.push(node->left);
			}

			if (!getline(ss, item, ','))
				break;

			if (item != "null") {
				node->right = new TreeNode(stoi(item));
				q1.push(node->right);
			}
		}
		return root;
	}
};