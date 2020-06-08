/************************************************************************/
/*@File Name         : 21.��������˳��ʹ����λ��ż��ǰ��.cpp
/*@Created Date      : 2020/6/8 10:47
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : ����һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ�����е�����λ�������ǰ�벿�֣�
���е�ż��λ������ĺ�벿�֣�����֤������������ż����ż��֮������λ�ò��䡣*/
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
	void reOrderArray(vector<int> &array) {
		
		int size = array.size();
		vector<int>oddArray(size,0);
		vector<int>evenArray(size,0);

		//ԭ�ص���

		//���������ռ����
		for (int i = 0; i < size; i++) {
			if ((array[i] & 0x1) == 0)   //ż��
				evenArray.push_back(array[i]);
			else
				oddArray.push_back(array[i]);
		}
		
		for (int i = 0; i < oddArray.size(); i++) {
		
			array[i] = oddArray[i];
		}

		int oddArraySize = oddArray.size();
		for (int i = 0; i < evenArray.size(); i++) {
			array[i + oddArraySize] = evenArray[i];
		}
	}
};

class Solution1 {
public:
	void reOrderArray(vector<int> &array) {
		int k = 0; //���������Ѿ��źõ���������
		for (int i = 0; i < array.size(); i++) {
			if (array[i] % 2 == 1) {
				int current = array[i]; //���浱ǰֵ 
				int preIndex = i - 1;
				//��ʼŲ��
				while (preIndex >= k) {
					array[preIndex + 1] = array[preIndex];
					preIndex--;
				}
				array[preIndex + 1] = current;
				k++;
			}
		}
	}
};