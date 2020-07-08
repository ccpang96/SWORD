/************************************************************************/
/*@File Name         : 59.队列的最大值.cpp
/*@Created Date      : 2020/6/9 20:58
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : 给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}；*/
/************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<sstream>
#include<queue>
#include<stack>
#include<deque>


using namespace std;

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		
		vector<int> result;

		if (nums.size() == 0 || k <= 0 || k > nums.size())
			return result;
		deque<int> dq;
		int i = 0;

		for (; i < k; ++i) {
			while (!dq.empty() && nums[dq.back()] < nums[i])
				dq.pop_back();
			dq.push_back(i);
		}
		result.push_back(nums[dq.front()]);		//最大的元素

		for (int i = k; i < nums.size(); i++) {

			//队头元素已经不在滑动窗口中，队头出队
			if (i - dq.front() >= k) {
				dq.pop_front();
			}

			//如果新来的元素比队尾的元素大，就让队尾元素出队
			while (!dq.empty() && nums[dq.back()] < nums[i]) {
				dq.pop_back();
			}

			//插入新的来的元素
			dq.push_back(i);
			result.push_back(nums[dq.front()]);
		}
		return result;
	}
};

//int main() {
//	vector<int>input{6,13,7,4,25,6,37,9,12};
//	vector<int>result = Solution().maxSlidingWindow(input, 3);
//	for (auto &m : result)
//		cout << m << endl;
//	system("pause");
//	return 0;
//}
