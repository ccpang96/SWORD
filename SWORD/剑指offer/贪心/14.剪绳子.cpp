/************************************************************************/
/*@File Name         : 14.МєЩўзг.cpp
/*@Created Date      : 2020/6/9 19:30
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
	int cutRope(int number) {
		if (number == 2)
			return 1;
		if (number == 3)
			return 2;

		int result;
		int threeNumber = number / 3;
		if (number % 3 == 0)
			result = pow(3, threeNumber);
		else if (number % 3 == 1)
			result = pow(3, threeNumber - 1) * 4;
		else {
			result = pow(3, threeNumber) * 2;
		}
		
		return result;
	}
};