#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<sstream>
#include<queue>
#include<stack>
using namespace std;

 

class Solution {
public:
	vector<int> printNumbers(int n) {
		vector<int>result;
		if (n <= 0)
			return result;
		int max = pow(10, n) - 1;
		for (int i = 1; i <= max; i++)
			result.push_back(i);
		return result;
	}
};