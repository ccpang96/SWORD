#pragma once
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<stack>
using namespace std;

static bool kIsVaild = true;  //用于判断输入的字符是否非法 默认合法

class Solution {
public:
	int stringToInteger(string str) {
		long long  num = 0;
		if (str.empty()) {
			kIsVaild = false;
			return 0; //字符串为空 非法返回0
		}
		int len = str.length();
		bool minus = false; //用于标示是正号还是负号

							//去除字符串前部的空格
		int i = 0;
		for (; i < len; i++) {
			if (str[i] != ' ')
				break;
		}

		//判断是否有负号位
		if ((str[i] < '0' || str[i] > '9') && (str[i] != '+' && str[i] != '-')) {
			kIsVaild = false;
			return 0;//非法字符返回
		}
		else if (str[i] == '+') {
			i++;
		}
		else if (str[i] == '-') {
			minus = true;
			i++;

		}

		//开始遍历有效数字部分 123abc
		int j = i;
		while (j < len) {
			if (str[j] >= '0' && str[j] <= '9') {
				num = num * 10 + str[j] - '0';
				if (!minus && num > 0x7FFFFFFF) { //num上溢
					kIsVaild = false;
					num = 0x7FFFFFFF;
					break;
				}
				if (minus && num > 0x80000000) { //num下溢
					kIsVaild = false;
					num = int(0x80000000);
					break;
				}
				j++;
			}
			else if (str[j] == ' ')
				j++;
			else { //遇到非法字符
				num = 0;
				kIsVaild = false;
				break;
			}
		}
		num = minus ? -num : num;
		return (int)num;

	}
};

//测试用例：
//字符串为空
//前面有空格,  "  123"
//含有正号或负号： "+123" "-123"
//非法输入 "abcd"
//字符串中间或后面有空格："12 12 12 "
//正整数溢出  > 0x7FFFFFFF
//负整数溢出  < 0x80000000

int main() {

	string line;

	while (getline(cin, line)) {
		int answer = Solution().stringToInteger(line);
		cout << (kIsVaild ? "有效   " : "无效   ") << answer << endl;
	}

	system("pause");
	return 0;
}



