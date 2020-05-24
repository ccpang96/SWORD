/************************************************************************/
/*@File Name         : 6..cpp
/*@Created Date      : 2020/5/24 22:18
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       :
/************************************************************************/

/* Includes *************************************************************/

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
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int>result;
		stack<ListNode*>s1;
		while (head != nullptr) {
			s1.push(head);
			head = head->next;
		}
		while(!s1.empty()) {
			result.push_back(s1.top()->val);
			s1.pop();

		}
		return result;
	}
};