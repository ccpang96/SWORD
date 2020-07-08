/************************************************************************/
/*@File Name         : 20.表示数值的字符串.cpp
/*@Created Date      : 2020/6/11 19:18
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。*/
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
	bool isNumeric(char* string)
	{
		if (string == nullptr)
			return false;
		//先消除前面的符号
		if (*string == '+' || *string == '-')
			string++;
		if (*string == '\0')		//只有一个符号位
			return false;
		int dot = 0, num = 0, nume = 0; //用于代表小数点、数、和e指数的是否存在
		while (*string != '\0') {
			if (*string >= '0' && *string <= '9') {
				string++;
				num = 1;
			}
			else if (*string == '.') {
				if (dot != 0 || nume != 0) {
					return false;
				}
				dot = 1;
				string++;
			}
			else if (*string == 'e' || *string == 'E') {
				if (nume != 0 || num == 0) {
					return false;
				}
				string++;
				nume++;
				if (*string == '+' || *string == '-') {
					string++;
				}
				if (*string == '\0')
					return false;
			}
			else
				return false;
		}
		return false;
	}

};