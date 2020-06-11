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
		//1.ʹ�ÿ�2���Ŀ���ָ�����ж��������Ƿ��л�
		
		bool hasLoop = false;

		int current = 0;
		if (!pHead)
			return nullptr;

		int loopNodeNumber = 0;		//���нڵ���Ŀ
		ListNode* first = pHead;	
		ListNode* second = pHead;	

		while (first->next != nullptr) {
			first = first->next;			//��ָ�룬ÿ���ƶ�����

			if (current) 
				second = second->next;			//��ָ�룬ÿ���ƶ�һ��
			current = 1 - current;
			if (first == second) { 
				hasLoop = true;
				break;
			}
		}

		//����޻�
		if (!hasLoop)
			return nullptr;

		//�ٿ��»����ж��ٸ�����
		second = second->next;
		loopNodeNumber++;
		while (second != first) {
			second = second->next;
			loopNodeNumber++;
		}


		first = pHead; 
		second = pHead;

		//����loopNodeNumber��
		while (loopNodeNumber > 0) {
			first = first->next;
		}

		while (first != second) {
			second = second->next;
			first = first->next;
		}
		return first;	//���ʱ��Ϊ

	}
};