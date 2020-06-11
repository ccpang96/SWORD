#pragma once
/*
题目： 面3：数组中重复的数字
在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。
数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。
请找出数组中任意一个重复的数字。

输入：
[2, 3, 1, 0, 2, 5, 3]
输出：2 或 3
*/
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<unordered_set> //hash_set
using namespace std;

class Solution {
public:
	//修改数组查找重复的数字
	bool findRepetitiveNumber(vector<int>&v1, int & duplication) {
		//判断数组长度是否小于0
		if (v1.size() <= 0)
			return false;
		//判断输入的数据是否符合要求
		for (int i = 0; i < v1.size(); ++i) {
			if (v1[i] <0 || v1[i] > v1.size() - 1)
				return false;
		}
		for (int index = 0; index < v1.size(); ++index) {
			while (v1[index] != index) { //如果v[0] != 0
				if (v1[index] == v1[v1[index]]) {
					duplication = v1[index];
					return true;
				}
				//交换v1[i] 和
				int temp = v1[v1[index]];
				v1[v1[index]] = v1[0];
				v1[index] = temp;

			}
		}
		return false;
	}

	//不修改数组找出重复的数字
	bool findRepetitiveNumberWithOutChangeArr(vector<int>&v1) {
		//int length = v1.size();
		unordered_set<int> hash_s;
		for (int index = 0; index < v1.size(); index++)
			hash_s.insert(v1[index]);
		for (int i = 0; i < hash_s.bucket_count(); i++) { //多少个桶
			int n = hash_s.bucket_size(i); //桶中元素的数量
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
	//将输入的string转换成vector
	vector<int> stringToIntegerVector(string input) {
		vector<int>v1;

		input = input.substr(1, input.length() - 2); //去掉左右两侧的[]
		string item;
		stringstream ss;
		ss.str(input);
		char delim = ','; //分界符
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
