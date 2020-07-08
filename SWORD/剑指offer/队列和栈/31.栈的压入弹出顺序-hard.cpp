/************************************************************************/
/*@File Name         : 31.栈的压入弹出顺序.cpp
/*@Created Date      : 2020/6/8 18:47
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序
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

 //借用辅助栈模拟压入的过程
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
