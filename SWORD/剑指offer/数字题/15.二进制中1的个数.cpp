

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<sstream>
#include<queue>
#include<stack>
using namespace std;

 
//正数的原码、反码、补码都是其本身; 
//负数反码：原码符号位不变，其余位取反
//负数补码：符号位不变，反码的其余位+1

class Solution {
public:
	int NumberOf1(int n) {
		
		int result = 0;
		if (n == 0)
			return 0;

		if (n > 0) {
			while (n) {
				if (n % 2 != 0)
					result++;
				n = n >> 1;
			}
		}

		
		
		if (n < 0) {
			//先求补码，然后将所有的数字保存到一个vector中，最后求vector中所有1的个数
			//从右至左找到第一个1，然后将左边的所有位都翻转
			
			//将n变为正数
			n = n * -1;


			int i = 0;
			bool firstFlag = true;
			vector<int>v1(32, 0);
			while (i < 31) {
				//还未找到第一个1
				if (firstFlag == true) { 
					if (n % 2 == 1) {
						firstFlag = false;
						v1[i] = 1;
					}
				}
				//已经找到了第一个1
				else {
					if (n % 2 == 0) {
						v1[i] = 1;
					}	
				}
				n = n >> 1;
				i++;
			}

			//符号位设置为1
			v1[31] = 1;
			for (int i = 0; i < 32; i++) {
				if (v1[i] == 1)
					result++;
			}
		}

		return result;
	}
};


//负数用补码表示
class Solution1 {
public:
	int NumberOf1(int n) {
		int result = 0;
		while (n) {
			++result;
			n = (n - 1) & n;  //消除掉1个1
		}

		return result;
	}
};

