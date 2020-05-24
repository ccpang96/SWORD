#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

class Solution {
public:

	bool scanUnsignedInteger(const char **str) {
		const char *before = *str;
		while (**str != '\0' && **str >= '0' && **str <= '9') {
			++(*str);
		}
		//存在0~9之间的数
		return *str > before;  //*str指向字符串的位置 > before指向的字符串位置
	}

	//遇到+-继续向前，扫描整数
	bool scanInteger(const char **str) {
		if (**str == '+' || **str == '-')
			++(*str);
		return scanUnsignedInteger(str);
	}

	bool isNumber(string str) {
		string::size_type index;
		//先去除首尾的空格
		while (!str.empty()) {
			index = str.find(' ');
			if (index != string::npos)
				str.erase(index, 1);
		}
		const char * s = str.c_str();
		bool numeric = scanInteger(&s); //扫描整数部分
		if (*s == '.') {
			++s;
			//小数点后可以没有数字 比如233.
			//整数部分可以没有 .123
			//整数和小数部分都有数字 233.123
			numeric = scanUnsignedInteger(&s) || numeric; //扫描小数部分
		}
		if (*s == 'E' || *s == 'e') {
			++s;
			numeric = numeric && scanInteger(&s); //遇到+ - 号略过，遇到整数略过，最终到达末尾
		}
		return numeric && *s == '\0';
	}
};

int main() {

	string line;
	while (getline(cin, line)) {
		string s = line;
		bool isnumber = Solution().isNumber(s);
		cout << isnumber << endl;
	}
	system("pause");
	return 0;
}

