#pragma once
#include<iostream>
#include<vector>
#include<stack>
#include<sstream>

using namespace std;


//利用前序遍历和中序遍历重建二叉树
//前序遍历的首个节点值是根节点，再中序遍历中找到根节点的位置后，递归调用返回root
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

};

class Input {
public:
	vector<int> stringToIntegerVector(string input) {
		vector<int>output;
		input = input.substr(1, input.length() - 2);
		stringstream ss;
		ss.str(input);
		char delim = ' ';
		string item;
		while (getline(ss, item, delim)) {
			output.push_back(stoi(item));
		}

		return output;
	}
};
//根据前序遍历和中序遍历建一颗二叉树
class Solution {
public:

	TreeNode * ContructTree(vector<int>&preorder, vector<int>&inorder, int startPreorder, int endPreorder, int startInorder, int endInorder) {
		int rootValue = preorder[startPreorder]; //在前序遍历中根节点的值
		TreeNode* root = new TreeNode(rootValue);//构造二叉树的根节点

		int rootInorder = startInorder;
		while (rootInorder <= endInorder && inorder[rootInorder] != rootValue)
			++rootInorder; //根节点在中序遍历中的位置

		int leftLength = rootInorder - startInorder; //左子树在中序遍历中的位置范围
		int rightLength = endInorder - rootInorder;

		if (leftLength > 0)
			root->left = ContructTree(preorder, inorder, startPreorder + 1, startPreorder + leftLength, startInorder, startInorder + leftLength - 1);
		if (rightLength > 0)
			root->right = ContructTree(preorder, inorder, startPreorder + leftLength + 1, endPreorder, startInorder + leftLength + 1, endInorder);

		return root;
	}


	TreeNode * buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.size() <= 0 || inorder.size() <= 0)
			return nullptr;
		return ContructTree(preorder, inorder, 0, preorder.size()
			
			- 1, 0, inorder.size() - 1);
	}
};
/*

int main() {

	string line;
	while (getline(cin, line)) {
		vector<int>preorder = Input().stringToIntegerVector(line);
		getline(cin, line);
		vector<int>inorder = Input().stringToIntegerVector(line);

		TreeNode* root = Solution().buildTree(preorder, inorder);
		cout << root << endl;

	}
	system("pause");
	return 0;
}
*/
