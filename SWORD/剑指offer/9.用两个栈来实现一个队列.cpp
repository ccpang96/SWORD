/************************************************************************/
/*@File Name         : 9.������ջ��ʵ��һ������.cpp
/*@Created Date      : 2020/6/2 9:29
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

 
class Solution {
public:
	//��pushջ�е�����Ԫ��ȫ������popջ��
	void pushToPop() {
		if (stack2.empty()) {	//Popջ����Ϊ��
			while (!stack1.empty()) { //��Pushջ�е�����Ԫ��һ����ȫ������Popջ��
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
	}

	void push(int node) {
		stack1.push(node);
	}
	int pop() {

		pushToPop();

		int node = stack2.top();
		stack2.pop();
		return node;
	}
private:
	stack<int>stack1;
	stack<int>stack2;
};