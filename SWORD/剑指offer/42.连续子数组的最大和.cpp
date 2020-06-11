/************************************************************************/
/*@File Name         : 42.连续子数组的最大和.cpp
/*@Created Date      : 2020/6/9 16:18
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
	int FindGreatestSumOfSubArray(vector<int> array) {
		vector<int>result(array.size() + 1, 0);
		int max = INT_MIN;

		for (int i = 1; i <= array.size(); i++) {
			if (result[i - 1] > 0)
				result[i] = array[i-1] + result[i - 1];
			else
				result[i] = array[i-1];

			if (result[i] > max)
				max = result[i];

		}

		return max;
	}
};

//
//int main() {
//
//	vector<int> input = { 6,-3,-2,7,-15,1,2,2 };
//	int result = Solution().FindGreatestSumOfSubArray(input);
//	cout << result << endl;
//	system("pause");
//	return 0;
//}