/************************************************************************/
/*@File Name         : 58.2.×óÐý×ª×Ö·û´®.cpp
/*@Created Date      : 2020/6/13 9:03
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
	string LeftRotateString(string str, int n) {
		if (str.empty())
			return str;

		int length = str.size();
		if (n >= length)
			n = n % length;

		string str1 = str.substr(0, n);
		string str2 = str.substr(n, str.size() - n);
		return  str2 +str1;
	}
};


