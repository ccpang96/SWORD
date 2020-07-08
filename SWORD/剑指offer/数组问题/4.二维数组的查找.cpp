#define _CRT_SECURE_NO_WARNINGS

/************************************************************************/
/*@File Name         : 4.二维数组的查找.cpp
/*@Created Date      : 2020/5/24 20:13
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       :
/************************************************************************/

/* Includes *************************************************************/
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<sstream>
#include<queue>
#include<stack>
using namespace std;



/************************************************************************/
/*@ Problem Name         : 4.二维数组的查找
/*@ Description 		 :


*************************************************************************
/*@ Example1-Input	 	 :
/*@ Example1-Output		 :
/*@ Example1-Explanation :
*************************************************************************
/*@ Example1-Input	 	 :
/*@ Example1-Output		 :
/*@ Example1-Explanation :

/*@补充说明：
/************************************************************************/

class Solution {
public:
	bool Find(int target, vector<vector<int>> array) {
		//输入参数有效性判断
		if (array.empty())
			return false;
		bool found = false;
		int m = array.size();
		int n = array[0].size();

		int i = 0;
		int j = n - 1;
		while (i < m && j >= 0) {
			if (array[i][j] > target) {		//往左走
				j--;
			}else if (array[i][j] < target) {
				i++;
			}
			else {
				found = true;
				break;			//找到要退出循环
			}
		}
		return found;
	}
};



/************************************************************************/
/*@FullName:  

函数
/*@Brief:      
/*@Parameter: 无
/*@Returns:   int 0
/*@time:      2020/5/24 20:27
/*@author:    ccpang
/************************************************************************/
//int 
//() {
//	int m, n;
//	char a;			//用于读取换行符
//	while (2 == scanf("%d %d\n", &m, &n)) {
//		vector<vector<int>>grid(m, vector<int>(n, 0));
//		for (int i = 0; i < m; i++) {
//			for (int j = 0; j <= n; j++) {
//				if (j == n)
//					scanf("%c", &a);			//读取换行符
//				else
//					scanf("%d,", &grid[i][j]);
//			}
//		}
//
//		//在这里执行Solution算法
//		int target = 7;
//		bool found = Solution().Find(target, grid);
//		if (found)
//			cout << "找到了" << target << endl;
//		else
//			cout << "没找到" << target << endl;
//	}
//	system("pause");
//	return 0;
//}


