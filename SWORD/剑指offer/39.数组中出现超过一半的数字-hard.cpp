/************************************************************************/
/*@File Name         : 39.数组中出现超过一半的数字.cpp
/*@Created Date      : 2020/6/9 9:30
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。*/
/************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<sstream>
#include<queue>
#include<stack>
#include<set>
using namespace std;


class Solution {
public:
	//超过一半的数字，其出现的次数一定要比其他数字出现的总和还要多
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		if (numbers.empty())
			return 0;
		int result = numbers[0];
		int times = 1;

		for (int i = 1; i < numbers.size(); ++i) {
			if (times == 0) {
				result = numbers[i];
				times = 1;
			}
			else if (numbers[i] == result)
				times++;
			else
				times--;
		}
		if (!checkMoreThanHalf(numbers, result))
			result = 0;
		return result;
	}

	bool checkMoreThanHalf(vector<int>numbers, int number) {
		int times = 0;
		for (int i = 0; i < numbers.size(); i++) {
			if (numbers[i] == number)
				times++;
		}
		if (times > numbers.size() / 2)
			return true;
		else
			return false;
	}
};