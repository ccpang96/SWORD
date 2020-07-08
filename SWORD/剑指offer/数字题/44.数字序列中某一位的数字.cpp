/************************************************************************/
/*@File Name         : 44.数字序列中某一位的数字.cpp
/*@Created Date      : 2020/6/13 15:08
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : 数字以0123456789101112131415…的格式序列化到一个字符序列中。在这个序列中，第5位（从下标0开始计数）是5，第13位是1，第19位是4，等等。
请写一个函数，求任意第n位对应的数字。
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
	int findNthDigit(int n) {
		//1位数 起始数字 1
		//2位数 起始数字 10   90个数    90*2个位
		//3位数 起始数字 100  900个数   900*3个位。
		//4位数 起始数字 1000 9000个数  9000*4个位

		int start = 1; //起始数字
		int digit = 1; //位数
		int count = 9;//多少个数
		
		while (n - count*digit > 0) {
			n = n - count * digit;
			start *= 10;
			digit += 1;
			count *= 10;
		}

		//n是第几个数
		int num = start + (n - 1) /digit;
		string s = to_string(num);

		return  to_string(num)[(n - 1) % digit] - '0'; // 3.
		
	}
};
