#pragma once
class Solution {
public:
	int InversePairs(vector<int> data) {
		int length = data.size(); //���鳤��
		if (length <= 0)
			return 0;
		vector<int>copy;
		for (int i = 0; i < length; i++) {
			copy.push_back(data[i]);
		}

		long long count = InversePairsCore(data, copy, 0, length - 1);
		return count % 1000000007;
	}
	long long InversePairsCore(vector<int>&data, vector<int>&copy, int start, int end) {
		if (start == end) {
			copy[start] = data[start];
			return 0;
		}
		int length = (end - start) / 2;
		long long  left = InversePairsCore(copy, data, start, start + length);
		long long  right = InversePairsCore(copy, data, start + length + 1, end);

		//�鲢�Ĺ���

		//i��ʼ��Ϊǰ������һ�����ֵ��±�
		int i = start + length;
		//j��ʼ��Ϊ�������һ�����ֵ��±�
		int j = end;
		int indexCopy = end;
		long long  count = 0;
		while (i >= start && j >= start + length + 1) {
			if (data[i] > data[j]) {
				copy[indexCopy--] = data[i--];
				count += j - (start + length); //������iλ�ô���ֵ����jλ�ô��ģ���iλ�ô���ֵ����jǰ�������е�ֵ
			}
			else {
				copy[indexCopy--] = data[j--];
			}
		}
		for (; i >= start; i--)
			copy[indexCopy--] = data[i];
		for (; j >= start + length + 1; j--)
			copy[indexCopy--] = data[j];
		return left + right + count;

	}
};