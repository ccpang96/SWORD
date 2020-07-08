/************************************************************************/
/*@File Name         : ¾ØÐÎ¸²¸Ç.cpp
/*@Created Date      : 2020/6/8 8:48
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
	int rectCover(int number) {
		if (number <= 0)
			return 0;
		if (number == 1)
			return 1;
		if (number == 2)
			return 2;
		int firstNumber = 1;
		int secondNumber = 2;
		int result = 0;
		for (int i = 3; i <= number; i++) {
			result = firstNumber + secondNumber;
			firstNumber = secondNumber;
			secondNumber = result ;
		}
		return result;
	}
};