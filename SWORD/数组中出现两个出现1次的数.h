#pragma once
//һ�����飬��һ����ֻ����һ�Σ������������Σ��ҳ��������ʱ��ռ临�Ӷȣ� O(n) O(1)
//һ�����飬��������ֻ����һ�Σ������������Σ��ҳ�������������ʱ��ռ临�Ӷȣ�

#include<iostream>
#include<vector>
using namespace std;

class Solution_1 {
public:
	//�������໥���
	int findOnceValue(vector<int>&v1) {
		int result = v1[0];
		for (size_t i = 1; i < v1.size(); i++) {
			result ^= v1[i];
		}
		return result;
	}
};
// 11 101  010 
class Solution_2 {
public:

	//�ҵ�resultXor�����ұ�һλ��Ϊ0�����
	int findResultXorBitIs1(int num) {
		int index = 0;
		while (((num & 1) == 0) && (index < 8 * sizeof(int))) {
			num = num >> 1;
			index++;
		}
		return index;
	}
	bool numIndexBitIs1(int num, int index) {
		num = num >> index;
		return num & 1;
	}

	//���໥���
	vector<int> findTwoValue(vector<int>&v1) {
		vector<int>result{ 0,0 };
		//�ȵõ�a��b�໥�����
		int resultXor = 0;
		for (int i = 0; i < v1.size(); i++) {
			resultXor ^= v1[i];
		}
		//�ҵ�resultXor��ֵΪ1��һλ����Ȼ����a��indexof1λ��1������b��indexOf1λ��1
		int indexOf1 = findResultXorBitIs1(resultXor);

		for (int i = 0; i < v1.size(); i++) {
			if (numIndexBitIs1(v1[i], indexOf1)) {
				result[0] ^= v1[i];
			}
			else {
				result[1] ^= v1[i];
			}
		}
		return result;
	}
};


