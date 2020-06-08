/************************************************************************/
/*@File Name         : 16.数值的整数次方.cpp
/*@Created Date      : 2020/6/8 9:52
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : 给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
保证base和exponent不同时为0
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
	bool g_valid = true;

	double Power(double base, int exponent) {	
		
		//判断底数为0.0，指数为负数的情况
		if (equal(base, 0.0) && exponent < 0) {
			g_valid = false;
			return 0.0;
		}
		//指数为负数的情况
		double UnsignedExponent = exponent;
		if (exponent < 0)
			UnsignedExponent *= -1;
		double result = powerWithUnsignedExponent(base, UnsignedExponent);
		if (exponent < 0)
			result = 1.0 / result;
		
		return result;
	}


	//指数为非负数时
	double powerWithUnsignedExponent(double base, int exponent) {
		if (exponent == 0)
			return 1.0;
		if (exponent == 1)
			return base;
		double result = powerWithUnsignedExponent(base, exponent >> 1);
		result *= result;
		if (exponent & 1 == 1)
			result *= base;
		return result;
	}

	//判断两个浮点数相等
	bool equal(double a, double b) {
		if (abs(a - b) <= 1e-6)
			return true;
		else
			return false;
	}
};
 


//int main() {
//
//	double result = Solution().Power(0.0, -3);
//	cout << result << endl;
//	system("pause");
//	return 0;
//}