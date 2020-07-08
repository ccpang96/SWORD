/************************************************************************/
/*@File Name         : 43.整数中1出现的次数.cpp
/*@Created Date      : 2020/6/9 16:26
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
#include<cmath>
using namespace std;

 
class Solution {
public:
	int NumberOf1Between1AndN_Solution(int n) {

		return f(n);
	}

	int f(int n) {
		if (n <= 0)
			return 0;
		string number = std::to_string(n);
		int high = number[0] - '0';
		int pow1 = (int)pow(10, number.size() - 1);
		int last = n - high * pow1;
		if (high == 1) //最高位是1
			return f(pow1 - 1) + (last + 1) + f(last);   //1~999范围内1的个数f(pow1-1) +  千分位是1的个数 + 其他位是1的个数f(last)
		else //最高位不是1
			return pow1 + high * f(pow1 - 1) + f(last);  //1~999范围内是1的个数是f(pow1-1) + 千分位是1的个数pow1 + f(pow1-1) + f(last)
	}
};
 