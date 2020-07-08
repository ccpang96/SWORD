/************************************************************************/
/*@File Name         : 35.复杂链表的复制.cpp
/*@Created Date      : 2020/6/8 20:55
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : 输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针random指向一个随机节点）
，请对此链表进行深拷贝，并返回拷贝后的头结点。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）*/
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

struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
		label(x), next(NULL), random(NULL) {
	}
};


class Solution {
public:
	RandomListNode * Clone(RandomListNode* pHead)
	{
		//输入异常值判断
		if (pHead == nullptr)
			return nullptr;
		//1.复制每个节点，将其加入到当前节点的后面
		RandomListNode* cur = pHead;
		while (cur != nullptr) {
			RandomListNode* cloneNode = new RandomListNode(cur->label);
			RandomListNode* next = cur->next;
			cur->next = cloneNode;
			cloneNode->next = next;
			cur = next;
		}

		//2.将随机节点设置好
		cur = pHead;
		while (cur != nullptr) {
			RandomListNode* node = cur->next;
			if (cur->random) {  //如果当前节点有random节点
				node->random = cur->random->next;
			}
			cur = node->next;
		}

		//3.拆分拷贝的链表和原链表
		RandomListNode* pClonedList = pHead->next;
		cur = pHead;
		
		while (cur) {
			RandomListNode* tmp = cur->next;
			cur->next = tmp->next;
			cur = cur->next;
			if (cur)
				tmp->next = cur->next;
		}
		return pClonedList;
	}
};
