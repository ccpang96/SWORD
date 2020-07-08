/************************************************************************/
/*@File Name         : 61.�˿���˳��.cpp
/*@Created Date      : 2020/6/13 9:38
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
	bool IsContinuous(vector<int> numbers) {
		if (numbers.size() != 5)
			return false;

		sort(numbers.begin(), numbers.end()); //���Ÿ���

		//ͳ��0���ֵ���Ŀ
		int zeroNumber = 0;
		int i = 0;
		for (; i < numbers.size(); i++) {
			if (numbers[i] == 0)
				zeroNumber++;
			else
				break;
		}

		i++;
		//��������֮��Ĳ�����С��0�ĸ�������˵����true��������ֶ��ӣ�����false
		for (; i < numbers.size(); i++) {
			if (numbers[i] == numbers[i - 1])
				return false;
			if (numbers[i] - numbers[i - 1] > 1)
				zeroNumber -= (numbers[i] - numbers[i - 1] - 1);
			if (zeroNumber < 0)
				return false;
		}
		return true;
	}
};