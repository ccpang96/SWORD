/************************************************************************/
/*@File Name         : 20.��ʾ��ֵ���ַ���.cpp
/*@Created Date      : 2020/6/11 19:18
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : ��ʵ��һ�����������ж��ַ����Ƿ��ʾ��ֵ������������С������
���磬�ַ���"+100","5e2","-123","3.1416"��"-1E-16"����ʾ��ֵ�� ����"12e","1a3.14","1.2.3","+-5"��"12e+4.3"�����ǡ�*/
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
	bool isNumeric(char* string)
	{
		if (string == nullptr)
			return false;
		//������ǰ��ķ���
		if (*string == '+' || *string == '-')
			string++;
		if (*string == '\0')		//ֻ��һ������λ
			return false;
		int dot = 0, num = 0, nume = 0; //���ڴ���С���㡢������eָ�����Ƿ����
		while (*string != '\0') {
			if (*string >= '0' && *string <= '9') {
				string++;
				num = 1;
			}
			else if (*string == '.') {
				if (dot != 0 || nume != 0) {
					return false;
				}
				dot = 1;
				string++;
			}
			else if (*string == 'e' || *string == 'E') {
				if (nume != 0 || num == 0) {
					return false;
				}
				string++;
				nume++;
				if (*string == '+' || *string == '-') {
					string++;
				}
				if (*string == '\0')
					return false;
			}
			else
				return false;
		}
		return false;
	}

};