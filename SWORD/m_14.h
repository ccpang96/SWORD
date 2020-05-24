#pragma once
/*
给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），
每段绳子的长度记为 k[0],k[1]...k[m] 。请问 k[0]*k[1]*...*k[m] 可能的最大乘积是多少？
例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
*/

#include<iostream>
#include<vector>
using namespace std;

//动态规划算法：先计算小问题的最优解并保存下来，再以此为基础求取大问题的最优解
//执行用时:0 ms, 在所有 C++ 提交中击败了100.00% 的用户
//内存消耗 : 6.3 MB, 在所有 C++ 提交中击败了100.00%的用户
class Solution {
public:
	int cuttingRope(int n) {
		if (n < 2)  //要求减的段数m>1，所以此处返回0，视为非法
			return 0;
		if (n == 2) //要求减的段数m>1,所以减为2段，1x1
			return 1;
		if (n == 3) //减为
			return 2; // 1X2 > 1x1x1    

		int max = 0;

		vector<int>products;
		products.assign(n + 1, 0); //赋予初值0
		products[0] = 0;
		products[1] = 1;
		products[2] = 2;
		products[3] = 3;

		for (int i = 4; i <= n; i++) {
			max = 0;
			for (int j = 1; j <= i / 2; j++) {
				int product = products[j] * products[i - j];  //i = 4时，1x3，2x2
				if (max < product)
					max = product;
				products[i] = max;
			}
		}
		max = products[n];
		return max;
	}
};

//贪心算法
//执行用时 :0 ms, 在所有 C++ 提交中击败了100.00% 的用户
//内存消耗:6.1 MB, 在所有 C++ 提交中击败了100.00%的用户
class Solution1 {
public:
	int cuttingRope(int n) {
		if (n < 2)
			return 0;
		if (n == 2)
			return 1;
		if (n == 3)
			return 2;

		int timeOf3 = n / 3;
		if (n - timeOf3 * 3 == 1)
			timeOf3 -= 1;
		int timeOf2 = (n - timeOf3 * 3) / 2;
		return (int)(pow(3, timeOf3)) *(int)(pow(2, timeOf2));
	}
};

/*
int main() {

	int n = 20;
	cout << Solution1().cuttingRope(n) << endl;
	system("pause");
	return 0;
}
*/
