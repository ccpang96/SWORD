/************************************************************************/
/*@File Name         : 46.把数字翻译成字符串.cpp
/*@Created Date      : 2020/6/13 16:19
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
	int translateNum(int num) {
		if (num < 0)
			return 0;	

		const string s = to_string(num);
		int len = s.size();

		if (len <= 1)
			return len;

		vector<int>result(len, 0);
		//代表num只有1位时，能翻译成的方法数
		result[0] = 1;
		result[1] = compare(s[0], s[1]) ? 2 : 1;
		 
		for (int i = 2; i < len; i++) {
			 
			if (compare(s[i-1],s[i])) {
				result[i] = result[i - 1] + result[i-2];
			}
			else
				result[i] = result[i - 1];
		}

		return result[len - 1];
	}

	bool compare(const char &a, const char & b) {
		return !(a == '0' || a > '2' || a == '2' && b > '5');
	}
};

//int main() {
//
//	int result = Solution().translateNum(506);
//	cout << result << endl;
//	system("pause");
//	return 0;
//}