#pragma once
//��ʵ��һ�����������ַ��� s �е�ÿ���ո��滻��"%20"��

#include<iostream>
#include<string>

using namespace std;


class Input {
public:


};

class Solution {
public:
	string replaceSpace(string s) {

		string array;
		for (auto &c : s) {
			if (c == ' ') {
				array.push_back('%');
				array.push_back('2');
				array.push_back('0');
			}
			else
				array.push_back(c);

		}
		return array;
	}


};
/*
int main() {

	string line;

	while (getline(cin, line)) {
		string s = Solution().replaceSpace(line);
		cout << s << endl;
	}

	system("pause");
	return 0;
}
*/
