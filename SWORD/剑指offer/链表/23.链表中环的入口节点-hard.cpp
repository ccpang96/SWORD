/************************************************************************/
/*@File Name         : 23.�����л�����ڽڵ�.cpp
/*@Created Date      : 2020/6/11 15:10
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : ʹ�����ο���ָ��
/************************************************************************/


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}

};


class Solution {
public:
	ListNode * EntryNodeOfLoop(ListNode* pHead)
	{
		if (!pHead)
			return nullptr;

		bool hasLoop = false;
		ListNode* fast = pHead, *slow = pHead;
		while (fast && fast->next) {
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow) {
				hasLoop = true;
				break;
			}
		}

		if (!hasLoop)
			return nullptr;

		slow = pHead; 
		while (fast != slow) {
			fast = fast->next;
			slow = slow->next;
		}
		return fast;
	}
};


