/************************************************************************/
/*@File Name         : 61.扑克牌顺子.cpp
/*@Created Date      : 2020/6/13 9:38
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
	bool IsContinuous(vector<int> numbers) {
		if (numbers.size() != 5)
			return false;

		sort(numbers.begin(), numbers.end()); //先排个序

		//统计0出现的数目
		int zeroNumber = 0;
		int i = 0;
		for (; i < numbers.size(); i++) {
			if (numbers[i] == 0)
				zeroNumber++;
			else
				break;
		}

		i++;
		//计算数据之间的差，如果差小于0的个数，就说明是true，如果出现对子，就是false
		for (; i < numbers.size(); i++) {
			if (numbers[i] == numbers[i - 1])
				return false;
			if (numbers[i] - numbers[i - 1] > 1)
				zeroNumber -= (numbers[i] - numbers[i - 1] - 1);
			if (zeroNumber < 0)
				return false;
		}
		return true;
	}
};