#define _CRT_SECURE_NO_WARNINGS

/************************************************************************/
/*@File Name         : 4.��ά����Ĳ���.cpp
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
/*@ Problem Name         : 4.��ά����Ĳ���
/*@ Description 		 :


*************************************************************************
/*@ Example1-Input	 	 :
/*@ Example1-Output		 :
/*@ Example1-Explanation :
*************************************************************************
/*@ Example1-Input	 	 :
/*@ Example1-Output		 :
/*@ Example1-Explanation :

/*@����˵����
/************************************************************************/

class Solution {
public:
	bool Find(int target, vector<vector<int>> array) {
		//���������Ч���ж�
		if (array.empty())
			return false;
		bool found = false;
		int m = array.size();
		int n = array[0].size();

		int i = 0;
		int j = n - 1;
		while (i < m && j >= 0) {
			if (array[i][j] > target) {		//������
				j--;
			}else if (array[i][j] < target) {
				i++;
			}
			else {
				found = true;
				break;			//�ҵ�Ҫ�˳�ѭ��
			}
		}
		return found;
	}
};



/************************************************************************/
/*@FullName:  

����
/*@Brief:      
/*@Parameter: ��
/*@Returns:   int 0
/*@time:      2020/5/24 20:27
/*@author:    ccpang
/************************************************************************/
//int 
//() {
//	int m, n;
//	char a;			//���ڶ�ȡ���з�
//	while (2 == scanf("%d %d\n", &m, &n)) {
//		vector<vector<int>>grid(m, vector<int>(n, 0));
//		for (int i = 0; i < m; i++) {
//			for (int j = 0; j <= n; j++) {
//				if (j == n)
//					scanf("%c", &a);			//��ȡ���з�
//				else
//					scanf("%d,", &grid[i][j]);
//			}
//		}
//
//		//������ִ��Solution�㷨
//		int target = 7;
//		bool found = Solution().Find(target, grid);
//		if (found)
//			cout << "�ҵ���" << target << endl;
//		else
//			cout << "û�ҵ�" << target << endl;
//	}
//	system("pause");
//	return 0;
//}


