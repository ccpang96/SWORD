#pragma once
//一组数组，有一个数只出现一次，其他都是两次，找出这个数。时间空间复杂度； O(n) O(1)
//一组数组，有两个数只出现一次，其他都是两次，找出这两个个数。时间空间复杂度；

#include<iostream>
#include<vector>
using namespace std;

class Solution_1 {
public:
	//两个数相互异或
	int findOnceValue(vector<int>&v1) {
		int result = v1[0];
		for (size_t i = 1; i < v1.size(); i++) {
			result ^= v1[i];
		}
		return result;
	}
};
// 11 101  010 
class Solution_2 {
public:

	//找到resultXor中最右边一位不为0的情况
	int findResultXorBitIs1(int num) {
		int index = 0;
		while (((num & 1) == 0) && (index < 8 * sizeof(int))) {
			num = num >> 1;
			index++;
		}
		return index;
	}
	bool numIndexBitIs1(int num, int index) {
		num = num >> index;
		return num & 1;
	}

	//先相互异或
	vector<int> findTwoValue(vector<int>&v1) {
		vector<int>result{ 0,0 };
		//先得到a和b相互异或结果
		int resultXor = 0;
		for (int i = 0; i < v1.size(); i++) {
			resultXor ^= v1[i];
		}
		//找到resultXor中值为1的一位，必然代表a的indexof1位是1，或者b的indexOf1位是1
		int indexOf1 = findResultXorBitIs1(resultXor);

		for (int i = 0; i < v1.size(); i++) {
			if (numIndexBitIs1(v1[i], indexOf1)) {
				result[0] ^= v1[i];
			}
			else {
				result[1] ^= v1[i];
			}
		}
		return result;
	}
};


