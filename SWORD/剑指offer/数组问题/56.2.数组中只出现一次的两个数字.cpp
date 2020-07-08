/************************************************************************/
/*@File Name         : 56.2.数组中只出现一次的两个数字.cpp
/*@Created Date      : 2020/6/13 7:10
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
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
		if (data.size() < 2)
			return;

		int xorResult = 0;
		for (int i = 0; i < data.size(); i++) {
			xorResult ^= data[i];
		}

		int bitOfis1 = findBitOfIs1(xorResult);

		*num1 = *num2 = 0;

		for (int i = 0; i < data.size(); i++) {
			if (bitIs1(data[i], bitOfis1)) {
				*num1 ^= data[i];
			}
			else
				*num2 ^= data[i];
		}
	}

	//在input中找出从右边起第一位为1的数字位数
	int findBitOfIs1(int input) {
		int i = 0; 
		for (int i = 0; i < sizeof(input) * 8; i++) {
			if (input & 1)
				return i;
			else
				input = input >> 1;
		}
		return i;  //此时return的是32
	}

	//判断某一位是不是1
	bool bitIs1(int input, int number) {
		while (number > 0) {
			input = input >> 1;
			number--;
		}
		if (input & 1)
			return true;
		else
			return false;
	}
};

//
//int main() {
//
//	vector<int>input = { 2,4,3,6,3,2,5,5 };
//	int a = 1; 
//	int b = 2;
//	int *num1 = &a;
//	int *num2 = &b;
//	Solution().FindNumsAppearOnce(input, num1, num2);
//
//	system("pause");
//	return 0;
//}