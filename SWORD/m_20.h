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
		//����0~9֮�����
		return *str > before;  //*strָ���ַ�����λ�� > beforeָ����ַ���λ��
	}

	//����+-������ǰ��ɨ������
	bool scanInteger(const char **str) {
		if (**str == '+' || **str == '-')
			++(*str);
		return scanUnsignedInteger(str);
	}

	bool isNumber(string str) {
		string::size_type index;
		//��ȥ����β�Ŀո�
		while (!str.empty()) {
			index = str.find(' ');
			if (index != string::npos)
				str.erase(index, 1);
		}
		const char * s = str.c_str();
		bool numeric = scanInteger(&s); //ɨ����������
		if (*s == '.') {
			++s;
			//С��������û������ ����233.
			//�������ֿ���û�� .123
			//������С�����ֶ������� 233.123
			numeric = scanUnsignedInteger(&s) || numeric; //ɨ��С������
		}
		if (*s == 'E' || *s == 'e') {
			++s;
			numeric = numeric && scanInteger(&s); //����+ - ���Թ������������Թ������յ���ĩβ
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

