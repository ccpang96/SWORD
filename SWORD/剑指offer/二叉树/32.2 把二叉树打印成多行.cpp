/************************************************************************/
/*@File Name         : 32.从上到下打印二叉树.cpp
/*@Created Date      : 2020/6/11 7:33
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
	vector<vector<int>> Print(TreeNode* pRoot) {
		vector<vector<int>>result;
		if (pRoot == nullptr)
			return result;
		queue<TreeNode*>q1;
		q1.push(pRoot);
		int nextLevel = 0;
		int toPrinted = 1;
		vector<int>rows;
		while (!q1.empty()) {
			TreeNode* node = q1.front();
			q1.pop();

			//在这里进行打印
			rows.push_back(node->val);
			--toPrinted;
			
			if (node->left) {
				nextLevel++;
				q1.push(node->left);
			}
				
			if (node->right) {
				q1.push(node->right);
				nextLevel++;
			}
			if (toPrinted == 0) {
				result.push_back(rows);
				rows.clear();
				toPrinted = nextLevel;
				nextLevel = 0;
			}
		}
		return result;
	}

	//反序列化
	TreeNode* stringToTreeNode(string input) {

		if (input.empty())
			return nullptr;

		string item;
		stringstream ss;
		ss.str(input);
		getline(ss, item, ',');

		queue<TreeNode*>q1;
		TreeNode* root = new TreeNode(stoi(item));
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




//int main() {
//	string input = "8,6,10,5,7,9,11";
//	TreeNode * root = Solution().stringToTreeNode(input);
//	vector<vector<int>>result = Solution().Print(root);
//	system("pause");
//	return 0;
//}