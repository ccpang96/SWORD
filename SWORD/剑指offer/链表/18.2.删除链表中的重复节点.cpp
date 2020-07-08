/************************************************************************/
/*@File Name         : 18.2.ɾ�������е��ظ��ڵ�.cpp
/*@Created Date      : 2020/6/11 10:57
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : ��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ�롣 ���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5
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
			if (cur->val == cur->next->val) {	//�����ֵ�һ����ȵ�
				while (cur->next && cur->val == cur->next->val) {	//�ж��Ƿ����������ȵ�
					cur = cur->next;
				}
				pre->next = cur->next;	//��preָ����һ����Ϊ�ظ���ֵ
				cur = cur->next;		//��cur = cur->next��ֵ
			}
			else {
				pre = cur; 
				cur = cur->next;
			}
		}
		return dummy->next;
	}
};