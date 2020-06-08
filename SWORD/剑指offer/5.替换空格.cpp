/************************************************************************/
/*@File Name         : 5.�滻�ո�.cpp
/*@Created Date      : 2020/5/24 20:34
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       :
/************************************************************************/




/* Includes ************************************************************ */

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<sstream>
#include<queue>
#include<stack>
using namespace std;



// �÷������� [5/24/2020 Administrator]
//1.��Ҫ���⿪�����飬�������˷ѿռ�
//2.û��delete
//3.�˷ѿռ䣬3����ԭ�����ַ���
/*
class Solution {
public:
	void replaceSpace(char *str, int length) {
		char *result = new char[3 * length];
		
		char *str1 = result;
		while (*str != '\0') {
			if (*str == ' ') {
				*result = '%';
				result++;
				*result = '2';
				result++;
				*result = '0';
				
			}
			else {
				*result = *str;
			}
			result++;
			str++;
		}	
		str = str1;
		printf("%s\n", str);
		delete[] str1;
	}
};
*/



void replaceSpace(char *str, int length) {
	//���ҳ�str���ж��ٸ��ո�
	int spaceCount = 0;
	for (int i = 0; i < length; i++) {	//���lengthӦ���������ַ����ĳ��ȣ�����\0
		if (str[i] == ' ')
			spaceCount++;
	}

	int newLength = length + 2 * spaceCount;
	char *s2 = str + newLength;		//�Ƚ��ַ���Ų������β��
	char *s1 = str + length;

	int j = length;
	while(s1 < s2) {
		if (*s1 != ' ') {	//��������ڿո�
			*s2-- = *s1;
		}
		else {				//������ڿո�
			*s2-- = '0';
			*s2-- = '2';
			*s2-- = '%';
		}
		s1--;
	}
}

//int main() {
//	
//	char *str = const_cast<char*>("we are ccpang");
//	 
//	 
//	
//	//Solution().replaceSpace(str, 15);
//	system("pause");
//	return 0;
//}
//
