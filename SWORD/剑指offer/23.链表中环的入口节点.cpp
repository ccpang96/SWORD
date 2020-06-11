/************************************************************************/
/*@File Name         : 23.链表中环的入口节点.cpp
/*@Created Date      : 2020/6/11 15:10
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : 使用两次快慢指针
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
		//1.使用快2步的块慢指针先判断链表中是否有环
		
		bool hasLoop = false;

		int current = 0;
		if (!pHead)
			return nullptr;

		int loopNodeNumber = 0;		//环中节点数目
		ListNode* first = pHead;	
		ListNode* second = pHead;	

		while (first->next != nullptr) {
			first = first->next;			//快指针，每次移动两步

			if (current) 
				second = second->next;			//慢指针，每次移动一步
			current = 1 - current;
			if (first == second) { 
				hasLoop = true;
				break;
			}
		}

		//如果无环
		if (!hasLoop)
			return nullptr;

		//再看下环中有多少个顶点
		second = second->next;
		loopNodeNumber++;
		while (second != first) {
			second = second->next;
			loopNodeNumber++;
		}


		first = pHead; 
		second = pHead;

		//先走loopNodeNumber步
		while (loopNodeNumber > 0) {
			first = first->next;
		}

		while (first != second) {
			second = second->next;
			first = first->next;
		}
		return first;	//相聚时即为

	}
};