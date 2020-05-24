#pragma once
//旋转数组中的最小数
#include<vector>
#include<stack>
#include<sstream>
#include<cmath>

using namespace std;

class Input {
public:
	vector<int> stringToIntegerVector(string input) {
		vector<int>output;
		input = input.substr(1, input.length() - 2);
		stringstream ss;
		ss.str(input);
		char delim = ',';
		string item;
		while (getline(ss, item, delim)) {
			output.push_back(stoi(item));
		}

		return output;
	}
};


class Solution {
public:

	int minArray(vector<int>& numbers) {

		int length = numbers.size();
		int left = 0, right = length - 1;
		while (left < right) {
			int mid = (left + right) >> 1;
			if (numbers[mid] > numbers[right])
				left = mid + 1;
			else if (numbers[mid] == numbers[right])
				right--;
			else
				right = mid;
		}
		return numbers[left];
	}
};

/*
int main() {

	string line;
	while (getline(cin, line)) {
		vector<int>numbers = Input().stringToIntegerVector(line);
		int minValue = Solution().minArray(numbers);
		cout << minValue << endl;
	}
	system("pause");
	return 0;
}
*/
