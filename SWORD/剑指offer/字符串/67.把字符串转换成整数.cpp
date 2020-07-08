/************************************************************************/
/*@File Name         : 67.���ַ���ת��������.cpp
/*@Created Date      : 2020/6/11 20:36
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
	bool g_Vaild = false;		//���������Ч��ֵ
	 
public:
	int StrToInt(string str) {
		int i = 0, flag = 1;
		if (str.empty())
			return 0;

		//����������ǿո�
		while (str[i] == ' ')
			i++;
		if (str[i] == '-')
			flag = -1;
		if (str[i] == '-' || str[i] == '+')
			i++;

		long long res = 0;	//��ʼ���
		for (; i < str.size() && isdigit(str[i]); i++) {
			res = res * 10 + (str[i] - '0');
			
			if (res > INT_MAX && flag == 1) {
				g_Vaild = true;
				break;
			}

			if (flag == -1 && res*flag < INT_MIN) {
				g_Vaild = true;
				break;
			}
		}
		if (i + 1 < str.size()) {
			g_Vaild = true;
		}
		
		if (g_Vaild)
			return 0;

		return (int)(flag * res);		//�쳣���ص�Ҳ��0
	}
};

//int main() {
//
//	string input = "-2147483649";
//	int result = Solution().StrToInt(input);
//	cout << result << endl;
//	system("pause");
//	return 0;
//}
