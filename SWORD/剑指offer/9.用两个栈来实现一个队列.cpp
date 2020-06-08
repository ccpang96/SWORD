/************************************************************************/
/*@File Name         : 9.用两个栈来实现一个队列.cpp
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
	//将push栈中的所有元素全部放入pop栈中
	void pushToPop() {
		if (stack2.empty()) {	//Pop栈必须为空
			while (!stack1.empty()) { //将Push栈中的所有元素一次性全部推入Pop栈中
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