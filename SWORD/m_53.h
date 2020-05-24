#pragma once
class Solution {
public:
	int InversePairs(vector<int> data) {
		int length = data.size(); //数组长度
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

		//归并的过程

		//i初始化为前半段最后一个数字的下标
		int i = start + length;
		//j初始化为后半段最后一个数字的下标
		int j = end;
		int indexCopy = end;
		long long  count = 0;
		while (i >= start && j >= start + length + 1) {
			if (data[i] > data[j]) {
				copy[indexCopy--] = data[i--];
				count += j - (start + length); //这里是i位置处的值大于j位置处的，则i位置处的值大于j前方的所有的值
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