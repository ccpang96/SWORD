/************************************************************************/
/*@File Name         : 53.1.数字在排序数组中出现的次数.cpp
/*@Created Date      : 2020/6/12 16:13
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

//排序的数组 二分查找 这种算法思路也不会被通过
//class Solution {
//public:
//	int GetNumberOfK(vector<int> data, int k) {
//		
//		if (data.empty())
//			return 0;
//
//		int result = 0;
//		int index = binarySearch(data, 0, data.size() - 1, k);
//		int index_copy = index-1;
//
//		while (index_copy >= 0) {
//			if (data[index_copy--] == k)
//				result++;
//			else
//				break;
//		}
//		while (index <= data.size()) {
//			if (data[index++] == k)
//				result++;
//			else
//				break;
//		}
//
//		return result;
//		}
//		
//
//	int binarySearch(vector<int>&data, int left, int right,int k) {
//		if (left >= right)
//			return left;
//
//		int mid = left + (right - left) / 2;
//		if (data[mid] > k)
//			return binarySearch(data, left, mid - 1, k);
//		else if (data[mid] < k)
//			return binarySearch(data, mid + 1, right, k);
//		else
//			return mid;
//	}
//};



class Solution {
public:
	int GetNumberOfK(vector<int> data, int k) {

		if (data.empty())
			return 0;
		int result = 0;
		int firstKIndex = getFirstKIndex(data,0,data.size()-1,k);
		int lastKIndex = getLastKIndex(data, 0, data.size() - 1, k);

		if(firstKIndex >-1 && lastKIndex > -1)
			result = lastKIndex - firstKIndex + 1;
		return result;
	}

	int getFirstKIndex(vector<int>&data, int left, int right, int k) {
		if (left > right)
			return -1; //没有找到k

		int mid = left + (right - left) / 2;
		if (data[mid] > k) {
			return getFirstKIndex(data, left, mid - 1, k);
		}
		else if (data[mid] < k)
			return getFirstKIndex(data, mid + 1, right, k);
		else {
			//判断是不是第一个k
			if (data[mid - 1] == k)
				return getFirstKIndex(data, left, mid - 1, k);
			else
				return mid;
		}
	}

	int getLastKIndex(vector<int>&data, int left, int right, int k) {
		if (left > right)
			return -1; //没有找到k

		int mid = left + (right - left) / 2;
		if (data[mid] > k) {
			return getLastKIndex(data, left, mid - 1, k);
		}
		else if (data[mid] < k)
			return getLastKIndex(data, mid + 1, right, k);
		else {
			//判断是不是第一个k
			if (data[mid + 1] == k)
				return getLastKIndex(data, mid+1, right, k);
			else
				return mid;
		}
	}

};

//int main() {
//	vector<int>data = { 1,2,3,3,3,3,4,5 };
//	int k = 3;
//	int result = Solution().GetNumberOfK(data, k);
//	cout << result << endl;
//	system("pause");
//	return 0;
//}
