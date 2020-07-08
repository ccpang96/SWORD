/************************************************************************/
/*@File Name         : 11��ת������С������.cpp
/*@Created Date      : 2020/6/2 9:36
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       :
��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
����һ���ǵݼ�����������һ����ת�������ת�������СԪ�ء�
��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1��
NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0��*/
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
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.empty())
			return 0;
		int left = 0;
		int right = rotateArray.size() - 1;

		//�����ҵ���Сֵ
		while (left < right) {
			int mid = (right + left) >> 1;
			if (rotateArray[mid] > rotateArray[right]) {
				//��ʱ��Сֵ��mid���ұ߲���
				left = mid + 1;
			}
			else if (rotateArray[mid] == rotateArray[right])
				right--;
			else
				right = mid;
		}
		return rotateArray[left];
	}
};