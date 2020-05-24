#pragma once
#include<iostream>
#include<vector>
#include<stack>
#include<sstream>

using namespace std;


//����ǰ���������������ؽ�������
//ǰ��������׸��ڵ�ֵ�Ǹ��ڵ㣬������������ҵ����ڵ��λ�ú󣬵ݹ���÷���root
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
//����ǰ����������������һ�Ŷ�����
class Solution {
public:

	TreeNode * ContructTree(vector<int>&preorder, vector<int>&inorder, int startPreorder, int endPreorder, int startInorder, int endInorder) {
		int rootValue = preorder[startPreorder]; //��ǰ������и��ڵ��ֵ
		TreeNode* root = new TreeNode(rootValue);//����������ĸ��ڵ�

		int rootInorder = startInorder;
		while (rootInorder <= endInorder && inorder[rootInorder] != rootValue)
			++rootInorder; //���ڵ�����������е�λ��

		int leftLength = rootInorder - startInorder; //����������������е�λ�÷�Χ
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
