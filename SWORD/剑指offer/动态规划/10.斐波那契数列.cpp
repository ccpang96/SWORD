/************************************************************************/
/*@File Name         : 10.斐波那契数列.cpp
/*@Created Date      : 2020/6/8 8:28
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       :大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0，第1项是1）。
n<=39
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

//递归解法：时间复杂度不行
//class Solution {
//public:
//	int Fibonacci(int n) {
//		if(n == 0)
//			return 0;
//		if (n == 1)
//			return 1;
//		return Fibonacci(n - 1) + Fibonacci(n - 2);
//	}
//};

class Solution {
public:
	int Fibonacci(int n) {
		if (n == 0)
			return 0;
		if (n == 1)
			return 1;

		int firstNumber = 0;
		int secondNumber = 1;
		int result = 0;
		for (unsigned int i = 2; i <= n; i++) {
			result = firstNumber + secondNumber;
			firstNumber = secondNumber;
			secondNumber = result;
		}
		return result;
	}
};

 