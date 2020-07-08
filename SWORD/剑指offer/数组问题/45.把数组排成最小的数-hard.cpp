/************************************************************************/
/*@File Name         : 45.�������ų���С����.cpp
/*@Created Date      : 2020/6/9 19:01
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : ����һ�����������飬����������������ƴ�������ų�һ��������ӡ��ƴ�ӳ���������������С��һ����
������������{3��32��321}�����ӡ���������������ųɵ���С����Ϊ321323��*/
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

//�Զ���º���cmp���ڱȼ�m��n��С��

class Solution {
public:
	string PrintMinNumber(vector<int> numbers) {
		if (numbers.empty())
			return "";
		sort(numbers.begin(), numbers.end(), cmp);
		string result;
		for (int i = 0; i < numbers.size(); i++) {
			result += to_string(numbers[i]);
		}
		return result;
	}

	//��αȽ�������˭��С
	bool static cmp(int a, int b) {
		string A = to_string(a) + to_string(b);
		string B = to_string(b) + to_string(a);
		return A < B;
	}
};