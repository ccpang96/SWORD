/************************************************************************/
/*@File Name         : 44.����������ĳһλ������.cpp
/*@Created Date      : 2020/6/13 15:08
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : ������0123456789101112131415���ĸ�ʽ���л���һ���ַ������С�����������У���5λ�����±�0��ʼ��������5����13λ��1����19λ��4���ȵȡ�
��дһ���������������nλ��Ӧ�����֡�
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
	int findNthDigit(int n) {
		//1λ�� ��ʼ���� 1
		//2λ�� ��ʼ���� 10   90����    90*2��λ
		//3λ�� ��ʼ���� 100  900����   900*3��λ��
		//4λ�� ��ʼ���� 1000 9000����  9000*4��λ

		int start = 1; //��ʼ����
		int digit = 1; //λ��
		int count = 9;//���ٸ���
		
		while (n - count*digit > 0) {
			n = n - count * digit;
			start *= 10;
			digit += 1;
			count *= 10;
		}

		//n�ǵڼ�����
		int num = start + (n - 1) /digit;
		string s = to_string(num);

		return  to_string(num)[(n - 1) % digit] - '0'; // 3.
		
	}
};
