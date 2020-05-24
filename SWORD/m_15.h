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

//��һ��������ȥ1֮���ٺ�ԭ����������λ�����㣬�õ��Ľ���൱�ڰ������Ķ����Ʊ�ʾ�����ұߵ�1���0
//ִ����ʱ:0 ms, ������ C++ �ύ�л�����100.00% ���û�
//�ڴ����� : 5.9 MB, ������ C++ �ύ�л�����100.00%���û�
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
