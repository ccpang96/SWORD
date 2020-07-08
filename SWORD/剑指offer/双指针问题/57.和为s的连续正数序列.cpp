/************************************************************************/
/*@File Name         : 57.和为s的连续正数序列.cpp
/*@Created Date      : 2020/6/13 7:51
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
	vector<vector<int> > FindContinuousSequence(int target) {
		int i = 1;	
		int j = 2;
		int limit = (target - 1) / 2; //左指针不能越过这个边界，否则就找不到了
		vector<int>res;
		vector<vector<int>>vec;
		while (i < limit) {
			int sum = (j + i)*(j - i + 1) / 2;
			if (sum == target) {
				res.clear();
				for (int k = i; k <= j; k++)
					res.push_back(k);
				vec.push_back(res);
				i++;
			}
			else if (sum < target)
				j++;
			else //太大了就让l++
				i++;
		}
		return vec;
	}
};