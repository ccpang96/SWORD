     /************************************************************************/
/*@File Name         : 66.构建乘积数组.cpp
/*@Created Date      : 2020/6/11 19:32
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
	vector<int> multiply(const vector<int>& A) {
		vector<int>B(A.size(),1);
		if (A.empty())
			return B;

		//计算坐下三角部分
 
		for (int i = 1; i < A.size(); i++) {
			B[i] = B[i - 1] * A[i - 1];
		}

		//计算右上三角部分
		int temp = 1;	//B[n-1]也是1
		for (int i = A.size() - 2; i >= 0; i--) {
			temp *= A[i+1];
			B[i] *= temp;
		}
		return B;
	}
};


 