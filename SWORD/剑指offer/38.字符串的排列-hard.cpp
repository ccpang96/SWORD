/************************************************************************/
/*@File Name         : 38.字符串的排列.cpp
/*@Created Date      : 2020/6/9 8:53
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
	vector<string> Permutation(string str) {
		vector<string>result;
		if (str.empty()) return result;

		Permutation(str, result, 0);

		//result还不是按照字典序来排序的
		sort(result.begin(), result.end());

		return result;
	}

	void Permutation(string str, vector<string>&result, int begin) {
		
		//递归基：索引指向str的最后一个元素
		if (begin == str.size() - 1) {
			if (find(result.begin(), result.end(), str) == result.end()) //避免出现aa和aa的重复添加情况
				result.push_back(str);	
		}
	
		for (int i = begin; i < str.size(); ++i) {
			swap(str[i], str[begin]);
			Permutation(str, result, begin + 1);
			swap(str[i], str[begin]);
		}
	}
	void swap(char &first, char &second) {
		char temp = first;
		first = second;
		second = temp;
	}
};
 
//int main() {
//
//	string input = "aabc";
//	vector<string>result = Solution().Permutation(input);
//	for (auto &m : result)
//		cout << m << endl;
//	system("pause");
//	return 0;
//}
