/************************************************************************/
/*@File Name         : 39.�����г��ֳ���һ�������.cpp
/*@Created Date      : 2020/6/9 9:30
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : ��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡���������һ������Ϊ9������{1,2,3,2,2,2,5,4,2}��
��������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2����������������0��*/
/************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<sstream>
#include<queue>
#include<stack>
#include<set>
using namespace std;


class Solution {
public:
	//����һ������֣�����ֵĴ���һ��Ҫ���������ֳ��ֵ��ܺͻ�Ҫ��
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		if (numbers.empty())
			return 0;
		int result = numbers[0];
		int times = 1;

		for (int i = 1; i < numbers.size(); ++i) {
			if (times == 0) {
				result = numbers[i];
				times = 1;
			}
			else if (numbers[i] == result)
				times++;
			else
				times--;
		}
		if (!checkMoreThanHalf(numbers, result))
			result = 0;
		return result;
	}

	bool checkMoreThanHalf(vector<int>numbers, int number) {
		int times = 0;
		for (int i = 0; i < numbers.size(); i++) {
			if (numbers[i] == number)
				times++;
		}
		if (times > numbers.size() / 2)
			return true;
		else
			return false;
	}
};