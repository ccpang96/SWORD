/************************************************************************/
/*@File Name         : 50.�ַ����е�һ�����ظ����ַ�.cpp
/*@Created Date      : 2020/6/11 18:53
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
#include<set>
using namespace std;

 
class Solution
{
	int hash[256] = { 0 };
	deque<char>deque1;  //������ŵ�һ��ֻ��һ�ε��ַ�
public:
	//Insert one char from stringstream
	void Insert(char ch)
	{
		hash[ch]++;
		if(hash[ch] == 1) //�������һ�Σ��������deque1��
			deque1.push_back(ch);	
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		while (!deque1.empty()) {
			if (hash[deque1.front()] != 1)	//������
				deque1.pop_front();
			else
				break;
		}
		if (deque1.empty())
			return '#';
		else 
			return deque1.front();
	}
};