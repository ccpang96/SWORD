/************************************************************************/
/*@File Name         : 22.链表的倒数第k个节点.cpp
/*@Created Date      : 2020/6/8 14:43
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
	ListNode * FindKthToTail(ListNode* pListHead, unsigned int k) {
		//异常值判断
		if (pListHead == nullptr || k == 0)
			return nullptr;

		//双指针法
		ListNode* dummy = new ListNode(0);
		dummy->next = pListHead;

		ListNode* p1 = dummy;
		ListNode* p2 = dummy;
		while (k > 0 ) {
			if (p1->next != nullptr)
				p1 = p1->next;
			else
				return nullptr;
			k--;
		}

		while (p1 != nullptr) {
			p1 = p1->next;
			p2 = p2->next;
		}

		delete dummy;
		return p2;
	}
};
