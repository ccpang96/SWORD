#pragma once
#include <iostream>
#include<string>
using namespace std;

class Input {
public:
	int stringToInteger(string input) {
		return stoi(input);
	}

};

//当一个整数减去1之后，再和原来的整数做位与运算，得到的结果相当于把整数的二进制表示中最右边的1变成0
//执行用时:0 ms, 在所有 C++ 提交中击败了100.00% 的用户
//内存消耗 : 5.9 MB, 在所有 C++ 提交中击败了100.00%的用户
class Solution {
public:
	int hammingWeight(uint32_t n) {

		int sum = 0;
		while (n) {
			sum++;
			n = (n - 1) &n;
		}
		return sum;
	}
};

/*
int main() {
	string line;
	while (getline(cin, line)) {
		int n = Input().stringToInteger(line);
		int oneNumber = Solution().hammingWeight(n);
		cout << oneNumber << endl;
	}
	system("pause");
	return 0;
}*/
