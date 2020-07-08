/************************************************************************/
/*@File Name         : 58.1.·­×ªµ¥´ÊµÄË³Ðò.cpp
/*@Created Date      : 2020/6/13 9:17
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
	
	void reverse(string &str, int l,int r) {
		if (str.empty())
			return;
		
		while (l < r) {
			char temp = str[l];
			str[l] = str[r];
			str[r] = temp;

			l++;
			r--;
		}
	}

	string ReverseSentence(string str) {
		if (str.empty())
			return str;
		string result = str;
		reverse(result,0, result.size()-1);

		int l = 0;
		
		int i = 0;
		for (; i < result.size(); i++) {
			if (result[i] == ' ') {
				reverse(result, l, i - 1);
				l = i + 1;
			}
		}
		reverse(result, l, i - 1);
		return result;
	}
};