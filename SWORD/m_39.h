#pragma once
class Solution {
public:
	//check vector is vaild
	bool checkVectorIsVaild(const vector<int> &numbers) {
		if (numbers.empty())
			return true;
		else
			return false;
	}
	bool checkMoreThanHalf(vector<int>&v1, int number) {
		size_t times = 0;
		for (auto it = v1.begin(); it != v1.end(); it++) {
			if (*it == number) {
				times++;
			}
		}
		if (times > (v1.size() >> 1))
			return true;
		else
			return false;
	}
	//函数二:找到数组的轴点
	int partition(vector<int>&v1, int start, int end) {
		int small = start - 1;
		for (int i = 1; i < v1.size(); i++) {
			if (v1[i] < v1[end]) {
				small++;
				if (i != small) {
					swap(v1[i], v1[small]);
				}
			}
		}
		small++;
		swap(v1[small], v1[end]);
		return  small;
	}

	int MoreThanHalfNum_Solution(vector<int> numbers) {
		if (checkVectorIsVaild(numbers))
			return 0;
		int index = partition(numbers, 0, numbers.size() - 1);
		int middle = numbers.size() >> 2;
		while (index != middle) {
			if (index > middle)
				index = partition(numbers, 0, index - 1);
			else
				index = partition(numbers, index + 1, numbers.size() - 1);

		}
		int number = numbers[middle];
		if (checkMoreThanHalf(numbers, number))
			return number;
		else
			return 0;
	}
};