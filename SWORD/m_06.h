#pragma once
//执行用时 :4 ms, 在所有 C++ 提交中击败了93.49% 的用户
//内存消耗:9 MB, 在所有 C++ 提交中击败了100.00%的用户
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

//往链表中添加一个节点
void AddToTail(ListNode**pHead, int value) {
	//判断是链表是否为空

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

//删除链表中的一个节点
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
