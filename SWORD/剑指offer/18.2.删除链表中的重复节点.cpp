/************************************************************************/
/*@File Name         : 18.2.删除链表中的重复节点.cpp
/*@Created Date      : 2020/6/11 10:57
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : 在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
/************************************************************************/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}

};


class Solution {
public:
	ListNode * deleteDuplication(ListNode* head)
	{
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode* pre = dummy;
		ListNode* cur = dummy->next;

		while (cur && cur->next) {
			if (cur->val == cur->next->val) {	//当发现第一个相等的
				while (cur->next && cur->val == cur->next->val) {	//判断是否出现连续相等的
					cur = cur->next;
				}
				pre->next = cur->next;	//让pre指向下一个不为重复的值
				cur = cur->next;		//让cur = cur->next的值
			}
			else {
				pre = cur; 
				cur = cur->next;
			}
		}
		return dummy->next;
	}
};