/************************************************************************/
/*@File Name         : 5.替换空格.cpp
/*@Created Date      : 2020/5/24 20:34
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       :
/************************************************************************/




/* Includes ************************************************************ */

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<sstream>
#include<queue>
#include<stack>
using namespace std;



// 该方法不行 [5/24/2020 Administrator]
//1.需要额外开辟数组，；而且浪费空间
//2.没法delete
//3.浪费空间，3倍于原来的字符串
/*
class Solution {
public:
	void replaceSpace(char *str, int length) {
		char *result = new char[3 * length];
		
		char *str1 = result;
		while (*str != '\0') {
			if (*str == ' ') {
				*result = '%';
				result++;
				*result = '2';
				result++;
				*result = '0';
				
			}
			else {
				*result = *str;
			}
			result++;
			str++;
		}	
		str = str1;
		printf("%s\n", str);
		delete[] str1;
	}
};
*/



void replaceSpace(char *str, int length) {
	//先找出str中有多少个空格
	int spaceCount = 0;
	for (int i = 0; i < length; i++) {	//这个length应该是整个字符串的长度，包括\0
		if (str[i] == ' ')
			spaceCount++;
	}

	int newLength = length + 2 * spaceCount;
	char *s2 = str + newLength;		//先将字符串挪动到最尾部
	char *s1 = str + length;

	int j = length;
	while(s1 < s2) {
		if (*s1 != ' ') {	//如果不等于空格
			*s2-- = *s1;
		}
		else {				//如果等于空格
			*s2-- = '0';
			*s2-- = '2';
			*s2-- = '%';
		}
		s1--;
	}
}

//int main() {
//	
//	char *str = const_cast<char*>("we are ccpang");
//	 
//	 
//	
//	//Solution().replaceSpace(str, 15);
//	system("pause");
//	return 0;
//}
//
