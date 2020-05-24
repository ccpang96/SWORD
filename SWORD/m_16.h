#pragma once
#include<algorithm>
#include<numeric>
#include<iostream>
using namespace std;

//ִ����ʱ :0 ms, ������ C++ �ύ�л�����100.00% ���û�
//�ڴ�����:5.8 MB, ������ C++ �ύ�л�����100.00%���û�
class Solution {
public:
	bool equal(double num1, double num2) {
		if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
			return true;
		else
			return false;
	}

	double PowerWithUnsignedExponent(double x, unsigned int absN) {
		if (absN == 0)
			return 1;
		if (absN == 1)
			return x;

		double result = PowerWithUnsignedExponent(x, absN >> 1);
		result *= result;
		if (absN & 0x1 == 1)
			result *= x;
		return result;
	}

	double myPow(double x, int n) {
		if (equal(x, 0.0) && n < 0)
			return 0.0;

		unsigned int absN = (unsigned int)n;
		if (n < 0)
			absN = (unsigned int)(-1 * (long)n);
		double result = PowerWithUnsignedExponent(x, absN);
		if (n < 0)
			result = 1.0 / result;
		return result;
	}
};

/*
int main() {

	cout << Solution().myPow(2.00000, int(10)) << endl;
	system("pause");
	return 0;
}
*/
