/************************************************************************/
/*@File Name         : 8.����������һ���ڵ�.cpp
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
		//��Ϊ�����������
		//1.�ýڵ���һ��������
		if (pNode->right != nullptr) {
			TreeLinkNode* right = pNode->right;
			while (right->left != nullptr) {	//����������������
				right = right->left;
			}
			pNext = right;
		}

		//2.�ýڵ�û�����������������������ڵ�������� ,ֱ�Ӿ����丸�ڵ�
		else {
			if (pNode->next != nullptr) {
				TreeLinkNode * parent = pNode->next; 
				while (parent != nullptr && pNode == parent->right) {
					pNode = parent;
					parent = parent->next;
				}

				//3.�ýڵ�û�����������������Ǹ��ڵ����������һֱ����
				pNext = parent;
			}
		}
		return pNext;
		
	}
};