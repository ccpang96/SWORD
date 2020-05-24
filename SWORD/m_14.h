#pragma once
/*
����һ������Ϊ n �����ӣ�������Ӽ����������ȵ� m �Σ�m��n����������n>1����m>1����
ÿ�����ӵĳ��ȼ�Ϊ k[0],k[1]...k[m] ������ k[0]*k[1]*...*k[m] ���ܵ����˻��Ƕ��٣�
���磬�����ӵĳ�����8ʱ�����ǰ������ɳ��ȷֱ�Ϊ2��3��3�����Σ���ʱ�õ������˻���18��
*/

#include<iostream>
#include<vector>
using namespace std;

//��̬�滮�㷨���ȼ���С��������ŽⲢ�������������Դ�Ϊ������ȡ����������Ž�
//ִ����ʱ:0 ms, ������ C++ �ύ�л�����100.00% ���û�
//�ڴ����� : 6.3 MB, ������ C++ �ύ�л�����100.00%���û�
class Solution {
public:
	int cuttingRope(int n) {
		if (n < 2)  //Ҫ����Ķ���m>1�����Դ˴�����0����Ϊ�Ƿ�
			return 0;
		if (n == 2) //Ҫ����Ķ���m>1,���Լ�Ϊ2�Σ�1x1
			return 1;
		if (n == 3) //��Ϊ
			return 2; // 1X2 > 1x1x1    

		int max = 0;

		vector<int>products;
		products.assign(n + 1, 0); //�����ֵ0
		products[0] = 0;
		products[1] = 1;
		products[2] = 2;
		products[3] = 3;

		for (int i = 4; i <= n; i++) {
			max = 0;
			for (int j = 1; j <= i / 2; j++) {
				int product = products[j] * products[i - j];  //i = 4ʱ��1x3��2x2
				if (max < product)
					max = product;
				products[i] = max;
			}
		}
		max = products[n];
		return max;
	}
};

//̰���㷨
//ִ����ʱ :0 ms, ������ C++ �ύ�л�����100.00% ���û�
//�ڴ�����:6.1 MB, ������ C++ �ύ�л�����100.00%���û�
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
