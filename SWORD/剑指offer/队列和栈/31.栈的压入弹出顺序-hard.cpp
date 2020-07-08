/************************************************************************/
/*@File Name         : 31.ջ��ѹ�뵯��˳��.cpp
/*@Created Date      : 2020/6/8 18:47
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : ���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ����Ϊ��ջ�ĵ���˳��
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

 //���ø���ջģ��ѹ��Ĺ���
class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		if (pushV.empty()) return false;
		vector<int>stack;
		for (int i = 0 , j = 0; i < pushV.size(); i++) {
			stack.push_back(pushV[i]);
			while (j < popV.size() && stack.back() == popV[j]) {
				stack.pop_back();
				j++;
			}
		}
		return stack.empty();
	}
};

//int main() {
//	vector<int>pushV{ 1,2,3,4,5 }, popV{ 4,5,3,2,1 };
//	bool result = Solution().IsPopOrder(pushV, popV);
//	cout << result << endl;
//	system("pause");
//	return 0;
//}
