

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<sstream>
#include<queue>
#include<stack>
using namespace std;

 
//������ԭ�롢���롢���붼���䱾��; 
//�������룺ԭ�����λ���䣬����λȡ��
//�������룺����λ���䣬���������λ+1

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
			//�����룬Ȼ�����е����ֱ��浽һ��vector�У������vector������1�ĸ���
			//���������ҵ���һ��1��Ȼ����ߵ�����λ����ת
			
			//��n��Ϊ����
			n = n * -1;


			int i = 0;
			bool firstFlag = true;
			vector<int>v1(32, 0);
			while (i < 31) {
				//��δ�ҵ���һ��1
				if (firstFlag == true) { 
					if (n % 2 == 1) {
						firstFlag = false;
						v1[i] = 1;
					}
				}
				//�Ѿ��ҵ��˵�һ��1
				else {
					if (n % 2 == 0) {
						v1[i] = 1;
					}	
				}
				n = n >> 1;
				i++;
			}

			//����λ����Ϊ1
			v1[31] = 1;
			for (int i = 0; i < 32; i++) {
				if (v1[i] == 1)
					result++;
			}
		}

		return result;
	}
};


//�����ò����ʾ
class Solution1 {
public:
	int NumberOf1(int n) {
		int result = 0;
		while (n) {
			++result;
			n = (n - 1) & n;  //������1��1
		}

		return result;
	}
};

