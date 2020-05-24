#include<vector>
#include<iostream>
using namespace std;


//循环实现发生了段错误
/*
class Solution {
public:
	bool findValue(int target, vector<vector<int>>&array, size_t i, size_t j) {
		if (i == array.size() || j <0) //到达边界
			return false;
		if (array[i][j] == target) { //找到 返回true
			return true;
		}
		else if (array[i][j] > target) { //当前值比target要大，则往左走
			j -= 1; //往左走
			return findValue(target, array, i, j);
		}
		else { //当前值比target要小，则往下走
			i += 1;
			return findValue(target, array, i, j);
		}

	}
	bool Find(int target, vector<vector<int> > array) {
		if (array.empty())
			return false;
		return findValue(target, array, 0, array[0].size() - 1); //从第一行最后一列开始访问
	}
};



int main() {
	
	vector<vector<int>>v1 { {1, 2, 3}, { 4,5,6 }, { 7,8,9 }};
	if (Solution().Find(12, v1))
		cout << "找到了" << endl;
	else
		cout << "没找到" << endl;
	system("pause");
	return 0;
}
*/

//用循环实现:
