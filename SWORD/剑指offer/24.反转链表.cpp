/************************************************************************/
/*@File Name         : 24.·´×ªÁ´±í.cpp
/*@Created Date      : 2020/6/8 14:56
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
	ListNode * ReverseList(ListNode* pHead) {
		if (pHead == nullptr)
			return nullptr;

		ListNode* cur = pHead;
		ListNode* pre = nullptr;
		ListNode* next = nullptr;

		while (cur != nullptr) {
			next = cur->next;
			cur->next = pre;
			if (next == nullptr)
				break;
			pre = cur;
			cur = next;
		}
		return cur;
	}
};