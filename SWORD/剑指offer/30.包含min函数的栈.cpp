/************************************************************************/
/*@File Name         : 30.包含min函数的栈.cpp
/*@Created Date      : 2020/6/8 18:36
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
	void push(int value) {
		s1.push(value);
		if (value < minValue) {
			minValue = value;
		}
		s2.push(minValue);
	}

	void pop() {
		int min_value = s2.top();
		s1.pop();
		s2.pop();
		if (min_value < s2.top())
			minValue = s2.top();
	}
	int top() {
		return s1.top();
	}

	int min() {
		return s2.top();
	}
private:
	stack<int>s1;	//存数据
	stack<int>s2;	//存最小值
	int minValue = INT_MAX;
};


