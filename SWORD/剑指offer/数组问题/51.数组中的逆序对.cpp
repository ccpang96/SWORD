/************************************************************************/
/*@File Name         : 51.数组中的逆序对.cpp
/*@Created Date      : 2020/6/12 7:41
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
	int InversePairs(vector<int> data) {
		int length = data.size();
		if (length < 2)
			return 0;


		vector<int>copy(length, 0);
		for (int i = 0; i < length; i++) {
			copy[i] = data[i];
		}

		//不允许修改数组
		long long result = 0;
		int *temp = new int[length];
		result = merge(copy, 0, length - 1, temp);
		delete[]temp;
		return int(result % 1000000007);
	}

	long long merge(vector<int>&data, int left, int right, int*temp) {
		if (left >= right)
			return 0;
		
		int mid = left + (right - left) / 2;
		long long leftPairs = merge(data, left, mid, temp);
		long long rightPairs = merge(data, mid + 1, right, temp);

		if (data[mid] <= data[mid + 1])
			return leftPairs + rightPairs;
		long long crossPairs = mergeAndCount(data, left, mid, right, temp);  //实现归并
		return leftPairs + rightPairs + crossPairs;
	}

	long long mergeAndCount(vector<int>&data, int left, int mid, int right, int*temp) {
		
		int i = left;
		int j = mid + 1;
		int t = 0;
		long long count = 0;

		while (i <= mid && j <= right) {
			if (data[i] <= data[j])
				temp[t++] = data[i++];
			else {
				temp[t++] = data[j++];
				count += (mid - i + 1);
			}
		}

		while (i <= mid)
			temp[t++] = data[i++];

		while (j <= right)
			temp[t++] = data[j++];

		t = 0;
		while (left <= right)
			data[left++] = temp[t++];
		return count;
	}
};




//int main() {
//	vector<int>input = { 1,2,3,4,5,6,7,0 };
//	int result = Solution().InversePairs(input);
//	cout << result;
//	system("pause");
//	return 0;
//}