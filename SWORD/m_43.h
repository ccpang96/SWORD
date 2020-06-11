#pragma once
#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<queue>
using namespace std;

class Solution {
public:
	int NumberOf1Between1AndN_Solution(int n)
	{
		int result = 0; //存储1出现的次数

		if (n < 0)
			return -1;

		int j = 0;

		if (n < 10)
			return 1;

		string digits = std::to_string(n);

		for (int i = digits.length() - 1; i >= 0; i--) {
			int Weight = pow(10, j + 1);
			int product = pow(10, j);
			int temp = static_cast<int>(digits[i] - '0');
			j++;

			cout << temp << endl;

			if (temp <  1) { //权值为10i 也没有问题
				result += (n / Weight)*product;
			}

			else if (temp == 1) {
				result += (n / Weight) * product + n % product + 1;
			}

			else { //大于1
				result += (n / Weight + 1) * product;
			}
		}
		return result;
	}
};

int main() {

	int answer = Solution().NumberOf1Between1AndN_Solution(21345);
	cout << answer << endl;

	system("pause");
	return 0;
}