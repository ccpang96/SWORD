/************************************************************************/
/*@File Name         : 62.圆圈中最后剩下的数.cpp
/*@Created Date      : 2020/6/13 14:32
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
#include<list>
using namespace std;

 

class Solution {
public:
	int LastRemaining_Solution(int n, int m)
	{
		if (n <= 0 || m <= 0)
			return -1;

		list<int>numbers;
		for (int i = 0; i < n; i++) {
			numbers.push_back(i);
		}

		auto cur = numbers.begin();
		while (numbers.size() > 1) {
			for (int i = 1; i < m; i++) {	//特别要注意这个地方是从1开始的
				++cur;
				if (cur == numbers.end())
					cur = numbers.begin();
			}

			auto next = ++cur;
			if (next == numbers.end())
				next = numbers.begin();
			
			--cur;
			numbers.erase(cur);
			cur = next;
		}
		return *cur;
	}
};