#pragma once
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<stack>
using namespace std;

static bool kIsVaild = true;  //�����ж�������ַ��Ƿ�Ƿ� Ĭ�ϺϷ�

class Solution {
public:
	int stringToInteger(string str) {
		long long  num = 0;
		if (str.empty()) {
			kIsVaild = false;
			return 0; //�ַ���Ϊ�� �Ƿ�����0
		}
		int len = str.length();
		bool minus = false; //���ڱ�ʾ�����Ż��Ǹ���

							//ȥ���ַ���ǰ���Ŀո�
		int i = 0;
		for (; i < len; i++) {
			if (str[i] != ' ')
				break;
		}

		//�ж��Ƿ��и���λ
		if ((str[i] < '0' || str[i] > '9') && (str[i] != '+' && str[i] != '-')) {
			kIsVaild = false;
			return 0;//�Ƿ��ַ�����
		}
		else if (str[i] == '+') {
			i++;
		}
		else if (str[i] == '-') {
			minus = true;
			i++;

		}

		//��ʼ������Ч���ֲ��� 123abc
		int j = i;
		while (j < len) {
			if (str[j] >= '0' && str[j] <= '9') {
				num = num * 10 + str[j] - '0';
				if (!minus && num > 0x7FFFFFFF) { //num����
					kIsVaild = false;
					num = 0x7FFFFFFF;
					break;
				}
				if (minus && num > 0x80000000) { //num����
					kIsVaild = false;
					num = int(0x80000000);
					break;
				}
				j++;
			}
			else if (str[j] == ' ')
				j++;
			else { //�����Ƿ��ַ�
				num = 0;
				kIsVaild = false;
				break;
			}
		}
		num = minus ? -num : num;
		return (int)num;

	}
};

//����������
//�ַ���Ϊ��
//ǰ���пո�,  "  123"
//�������Ż򸺺ţ� "+123" "-123"
//�Ƿ����� "abcd"
//�ַ����м������пո�"12 12 12 "
//���������  > 0x7FFFFFFF
//���������  < 0x80000000

int main() {

	string line;

	while (getline(cin, line)) {
		int answer = Solution().stringToInteger(line);
		cout << (kIsVaild ? "��Ч   " : "��Ч   ") << answer << endl;
	}

	system("pause");
	return 0;
}



