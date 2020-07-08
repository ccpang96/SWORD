/************************************************************************/
/*@File Name         : 3.数组中重复的数字.cpp
/*@Created Date      : 2020/6/11 20:23
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       :
/************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<sstream>
#include<queue>
#include<stack>
#include<set>
using namespace std;

 


class Solution {
	set<int>set1;
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	bool duplicate(int numbers[], int length, int* duplication) {

		for (int i = 0; i < length; i++) {
			set1.insert(numbers[i]);
			if (set1.size() < i + 1) {
				*duplication = numbers[i];
				return true;
			}
		}
		return false;
	}
};

//int main() {
//	int arr[] = { 1,2,2,3 };
//	int length = 4;
//	int *result = nullptr;
//
//	system("pause");
//	return 0;
//}