/************************************************************************/
/*@File Name         : 57.2.和为s的两个数.cpp
/*@Created Date      : 2020/6/13 8:32
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
	vector<int> FindNumbersWithSum(vector<int> array, int target) {
		vector<int>result;
		if (array.size() < 2)
			return result;

		int left = 0;
		int right = array.size() - 1;
		while (left < right) {
			int sum = array[left] + array[right];
			if (target == sum) {
				result.push_back(array[left]);
				result.push_back(array[right]);
				break;
			}
			else if (target > sum) {
				left++;
			}
			else {
				right--;
			}
		}
		return result;
	}
};