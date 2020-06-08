/************************************************************************/
/*@File Name         : 21.调整数组顺序使奇数位于偶数前面.cpp
/*@Created Date      : 2020/6/8 10:47
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。*/
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
	void reOrderArray(vector<int> &array) {
		
		int size = array.size();
		vector<int>oddArray(size,0);
		vector<int>evenArray(size,0);

		//原地调整

		//开辟两个空间调整
		for (int i = 0; i < size; i++) {
			if ((array[i] & 0x1) == 0)   //偶数
				evenArray.push_back(array[i]);
			else
				oddArray.push_back(array[i]);
		}
		
		for (int i = 0; i < oddArray.size(); i++) {
		
			array[i] = oddArray[i];
		}

		int oddArraySize = oddArray.size();
		for (int i = 0; i < evenArray.size(); i++) {
			array[i + oddArraySize] = evenArray[i];
		}
	}
};

class Solution1 {
public:
	void reOrderArray(vector<int> &array) {
		int k = 0; //用来设置已经排好的奇数部分
		for (int i = 0; i < array.size(); i++) {
			if (array[i] % 2 == 1) {
				int current = array[i]; //保存当前值 
				int preIndex = i - 1;
				//开始挪动
				while (preIndex >= k) {
					array[preIndex + 1] = array[preIndex];
					preIndex--;
				}
				array[preIndex + 1] = current;
				k++;
			}
		}
	}
};