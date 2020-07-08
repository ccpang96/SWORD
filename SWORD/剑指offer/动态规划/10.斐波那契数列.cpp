/************************************************************************/
/*@File Name         : 10.쳲���������.cpp
/*@Created Date      : 2020/6/8 8:28
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       :��Ҷ�֪��쳲��������У�����Ҫ������һ������n���������쳲��������еĵ�n���0��ʼ����0��Ϊ0����1����1����
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

//�ݹ�ⷨ��ʱ�临�ӶȲ���
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

 