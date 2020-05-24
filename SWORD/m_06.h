#pragma once
//ִ����ʱ :4 ms, ������ C++ �ύ�л�����93.49% ���û�
//�ڴ�����:9 MB, ������ C++ �ύ�л�����100.00%���û�
#include<vector>
#include<stack>
using std::vector;
using std::stack;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}

};

class Solution {
public:
	vector<int> reversePrint(ListNode* head) {
		stack<int>s1;
		vector<int>v1;
		ListNode *pNode = head;
		while (pNode != nullptr) {
			s1.push(pNode->val);
			pNode = pNode->next;
		}
		while (!s1.empty()) {
			v1.push_back(s1.top());
			s1.pop();
		}
		return v1;
	}
};

/*
struct ListNode {
	int m_nValue;
	ListNode* m_pNext;
};

//�����������һ���ڵ�
void AddToTail(ListNode**pHead, int value) {
	//�ж��������Ƿ�Ϊ��

	ListNode*pNew = new ListNode();
	pNew->m_nValue = value;
	pNew->m_pNext = nullptr;
	if (*pHead == nullptr) {
		*pHead = pNew;
	}
	else {
		ListNode* pNode = *pHead;
		while (pNode->m_nValue != nullptr)
			pNode = pNode->m_pNext;

		pNode->m_pNext = pNew;
	}
}

//ɾ�������е�һ���ڵ�
void RemoveNode(ListNode** pHead, int value) {
	if (pHead == nullptr || *pHead == nullptr)
		return;
	ListNode* pToBeDeleted = nullptr;
	if ((*pHead)->m_nValue == value) {
		pToBeDeleted = *pHead;
		*pHead = (*pHead)->m_pNext;
	}
	else {
		ListNode* pNode = *pHead;
		while (pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue != value)
			pNode = pNode->m_pNext;
		if (pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue == value) {
			pToBeDeleted = pNode->m_pNext;
			pNode->m_pNext = pNode->m_pNext->m_pNext;
		}
	}
	if (pToBeDeleted != nullptr) {
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
	}
}



*/
