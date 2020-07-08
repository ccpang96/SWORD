/************************************************************************/
/*@File Name         : 52.两个链表的第一个公共节点.cpp
/*@Created Date      : 2020/6/12 15:25
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

//空间复杂度O(n+m)：这种方法不好
//class Solution {
//public:
//	ListNode * FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
//		if (pHead1 == nullptr || pHead2 == nullptr)
//			return nullptr;
//		ListNode*result = nullptr;
//		stack<ListNode*>stack1;
//		stack<ListNode*>stack2;
//
//		stack1.push(pHead1);
//		while (pHead1->next) {
//			pHead1 = pHead1->next;
//			stack1.push(pHead1);
//		}
//
//		stack2.push(pHead2);
//		while (pHead2->next) {
//			pHead2 = pHead2->next;
//			stack2.push(pHead2);
//		}
//
//		
//		while (!stack1.empty() && !stack2.empty()) {
//			
//			if (stack2.top() == stack1.top()) {
//				result = stack1.top();
//				stack1.pop();
//				stack2.pop();
//			}
//			else
//			{
//				break;
//			}
//		}
//		return result;
//	}
//};


class Solution {
public:
	ListNode * FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		if (pHead1 == nullptr || pHead2 == nullptr)
			return nullptr;

		int pHead1Length = 1;
		int pHead2Length = 1;
		ListNode* cur1 = pHead1;
		ListNode* cur2 = pHead2;
		while (cur1->next) {
			cur1 = cur1->next;
			pHead1Length++;
		}

		while (cur2->next) {
			cur2 = cur2->next;
			pHead2Length++;
		}

		ListNode* pHeadLong = pHead1;
		ListNode* pHeadShort = pHead2;
		if (pHead2Length > pHead1Length) {
			pHeadLong = pHead2;
			pHeadShort = pHead1;
		}

		int diff = abs(pHead2Length - pHead1Length);
		for (int i = 0; i < diff; i++) {
			pHeadLong = pHeadLong->next;
		}

		while (pHeadLong != nullptr && pHeadShort != nullptr && pHeadLong != pHeadShort) {
			pHeadLong = pHeadLong->next;
			pHeadShort = pHeadShort->next;
		}
		return pHeadLong;
	}
};