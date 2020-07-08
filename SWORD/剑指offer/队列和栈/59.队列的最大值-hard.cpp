/************************************************************************/
/*@File Name         : 59.���е����ֵ.cpp
/*@Created Date      : 2020/6/9 20:58
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : ����һ������ͻ������ڵĴ�С���ҳ����л�����������ֵ�����ֵ��
���磬�����������{2,3,4,2,6,2,5,1}���������ڵĴ�С3����ôһ������6���������ڣ����ǵ����ֵ�ֱ�Ϊ{4,4,6,6,6,5}��*/
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
		result.push_back(nums[dq.front()]);		//����Ԫ��

		for (int i = k; i < nums.size(); i++) {

			//��ͷԪ���Ѿ����ڻ��������У���ͷ����
			if (i - dq.front() >= k) {
				dq.pop_front();
			}

			//���������Ԫ�رȶ�β��Ԫ�ش󣬾��ö�βԪ�س���
			while (!dq.empty() && nums[dq.back()] < nums[i]) {
				dq.pop_back();
			}

			//�����µ�����Ԫ��
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
