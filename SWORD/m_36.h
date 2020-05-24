#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<queue>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Input {
public:
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

class Solution {
public:
	TreeNode * Convert(TreeNode* pRootOfTree)
	{
		TreeNode * pLast = nullptr;

		convertNode(pRootOfTree, pLast); //此时pLast应该是链表的最后一个值
										 //那么我们从后往前遍历双向链表
		TreeNode * pHead = pLast;
		while (pHead != nullptr && pHead->left != nullptr) {

			pHead = pHead->left;
		}
		return pHead;

	}
	void convertNode(TreeNode *pRoot, TreeNode * &pLast) {
		if (pRoot == nullptr)
			return;

		TreeNode * pCurr = pRoot;


		if (pCurr->left)
			convertNode(pCurr->left, pLast);

		pCurr->left = pLast;
		if (pLast != nullptr)
			pLast->right = pCurr;

		pLast = pCurr; //将已经连接好的链表的最大值赋予pLast
		if (pCurr->right)
			convertNode(pCurr->right, pLast);
	}
};

int main() {

	string line;
	while (getline(cin, line)) {
		TreeNode *root = Input().stringToTreeNode(line);
		TreeNode *result = Solution().Convert(root);

	}

	system("pause");
	return 0;
}