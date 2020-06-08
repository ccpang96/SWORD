/************************************************************************/
/*@File Name         : 35.��������ĸ���.cpp
/*@Created Date      : 2020/6/8 20:55
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : ����һ����������ÿ���ڵ����нڵ�ֵ���Լ�����ָ�룬һ��ָ����һ���ڵ㣬��һ������ָ��randomָ��һ������ڵ㣩
����Դ������������������ؿ������ͷ��㡣��ע�⣬���������벻Ҫ���ز����еĽڵ����ã�������������ֱ�ӷ��ؿգ�*/
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
		//�����쳣ֵ�ж�
		if (pHead == nullptr)
			return nullptr;
		//1.����ÿ���ڵ㣬������뵽��ǰ�ڵ�ĺ���
		RandomListNode* cur = pHead;
		while (cur != nullptr) {
			RandomListNode* cloneNode = new RandomListNode(cur->label);
			RandomListNode* next = cur->next;
			cur->next = cloneNode;
			cloneNode->next = next;
			cur = next;
		}

		//2.������ڵ����ú�
		cur = pHead;
		while (cur != nullptr) {
			RandomListNode* node = cur->next;
			if (cur->random) {  //�����ǰ�ڵ���random�ڵ�
				node->random = cur->random->next;
			}
			cur = node->next;
		}

		//3.��ֿ����������ԭ����
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
