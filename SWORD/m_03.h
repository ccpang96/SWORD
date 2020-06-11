#pragma once
/*
��Ŀ�� ��3���������ظ�������
��һ������Ϊ n ������ nums ����������ֶ��� 0��n-1 �ķ�Χ�ڡ�
������ĳЩ�������ظ��ģ�����֪���м��������ظ��ˣ�Ҳ��֪��ÿ�������ظ��˼��Ρ�
���ҳ�����������һ���ظ������֡�

���룺
[2, 3, 1, 0, 2, 5, 3]
�����2 �� 3
*/
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<unordered_set> //hash_set
using namespace std;

class Solution {
public:
	//�޸���������ظ�������
	bool findRepetitiveNumber(vector<int>&v1, int & duplication) {
		//�ж����鳤���Ƿ�С��0
		if (v1.size() <= 0)
			return false;
		//�ж�����������Ƿ����Ҫ��
		for (int i = 0; i < v1.size(); ++i) {
			if (v1[i] <0 || v1[i] > v1.size() - 1)
				return false;
		}
		for (int index = 0; index < v1.size(); ++index) {
			while (v1[index] != index) { //���v[0] != 0
				if (v1[index] == v1[v1[index]]) {
					duplication = v1[index];
					return true;
				}
				//����v1[i] ��
				int temp = v1[v1[index]];
				v1[v1[index]] = v1[0];
				v1[index] = temp;

			}
		}
		return false;
	}

	//���޸������ҳ��ظ�������
	bool findRepetitiveNumberWithOutChangeArr(vector<int>&v1) {
		//int length = v1.size();
		unordered_set<int> hash_s;
		for (int index = 0; index < v1.size(); index++)
			hash_s.insert(v1[index]);
		for (int i = 0; i < hash_s.bucket_count(); i++) { //���ٸ�Ͱ
			int n = hash_s.bucket_size(i); //Ͱ��Ԫ�ص�����
			if (n > 1) {
				cout << hash_s.bucket(i);
				return true;
			}
		}

		return false;
	}
};

class Input {
public:
	//�������stringת����vector
	vector<int> stringToIntegerVector(string input) {
		vector<int>v1;

		input = input.substr(1, input.length() - 2); //ȥ�����������[]
		string item;
		stringstream ss;
		ss.str(input);
		char delim = ','; //�ֽ��
		while (getline(ss, item, delim)) {
			v1.push_back(stoi(item));
		}
		return v1;
	}
};
/*
int 
() {

	string line;
	while (getline(cin, line)) {
		vector<int>v1;
		v1 = Input().stringToIntegerVector(line);
		int duplication;
		//	if (Solution().findRepetitiveNumber(v1, duplication))
		//		cout << duplication << endl;
		if (Solution().findRepetitiveNumberWithOutChangeArr(v1))
			cout << "success" << endl;

	}
	system("pause");
	return 0;
}
*/
