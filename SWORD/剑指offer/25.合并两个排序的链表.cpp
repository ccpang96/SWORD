/************************************************************************/
/*@File Name         : 25.合并两个排序的链表.cpp
/*@Created Date      : 2020/6/8 15:18
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


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}

};


class Solution {
public:
	ListNode * Merge(ListNode* pHead1, ListNode* pHead2) {
		if (pHead1 == nullptr && pHead2 == nullptr)
			return nullptr;
		if (pHead1 == nullptr)
			return pHead2;
		if (pHead2 == nullptr)
			return pHead1;
		ListNode* dummy = new ListNode(0);
		ListNode *cur = dummy;

		while (pHead1 != nullptr && pHead2 != nullptr) {
			if (pHead1->val < pHead2->val) {
				cur->next = pHead1;
				pHead1 = pHead1->next;
			}
			else {
				cur->next = pHead2;
				pHead2 = pHead2->next;
			}
			cur = cur->next;
		}
		while (pHead1 != nullptr) {
			cur->next = pHead1;
			pHead1 = pHead1->next;
			cur = cur->next;
		}
		while (pHead2 != nullptr) {
			cur->next = pHead2;
			pHead2 = pHead2->next;
			cur = cur->next;
		}
	
		cur = dummy->next;
		delete dummy;
		return cur;
	}
};