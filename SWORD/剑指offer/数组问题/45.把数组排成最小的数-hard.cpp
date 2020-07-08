/************************************************************************/
/*@File Name         : 45.把数组排成最小的数.cpp
/*@Created Date      : 2020/6/9 19:01
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : 输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。*/
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

//自定义仿函数cmp用于比价m和n哪小，

class Solution {
public:
	string PrintMinNumber(vector<int> numbers) {
		if (numbers.empty())
			return "";
		sort(numbers.begin(), numbers.end(), cmp);
		string result;
		for (int i = 0; i < numbers.size(); i++) {
			result += to_string(numbers[i]);
		}
		return result;
	}

	//如何比较两个数谁更小
	bool static cmp(int a, int b) {
		string A = to_string(a) + to_string(b);
		string B = to_string(b) + to_string(a);
		return A < B;
	}
};