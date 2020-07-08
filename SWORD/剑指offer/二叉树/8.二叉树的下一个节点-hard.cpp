/************************************************************************/
/*@File Name         : 8.二叉树的下一个节点.cpp
/*@Created Date      : 2020/6/11 9:10
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

struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

	}
};


class Solution {
public:
	TreeLinkNode * GetNext(TreeLinkNode* pNode)
	{

		if (!pNode)
			return nullptr;
		TreeLinkNode * pNext = nullptr;
		//分为三种情况讨论
		//1.该节点有一颗右子树
		if (pNode->right != nullptr) {
			TreeLinkNode* right = pNode->right;
			while (right->left != nullptr) {	//沿左子树不断深入
				right = right->left;
			}
			pNext = right;
		}

		//2.该节点没有右子树，但是它是它父节点的左子树 ,直接就是其父节点
		else {
			if (pNode->next != nullptr) {
				TreeLinkNode * parent = pNode->next; 
				while (parent != nullptr && pNode == parent->right) {
					pNode = parent;
					parent = parent->next;
				}

				//3.该节点没有右子树，但是它是父节点的右子树，一直朝上
				pNext = parent;
			}
		}
		return pNext;
		
	}
};