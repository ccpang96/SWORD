#include<vector>
#include<iostream>
using namespace std;


//ѭ��ʵ�ַ����˶δ���
/*
class Solution {
public:
	bool findValue(int target, vector<vector<int>>&array, size_t i, size_t j) {
		if (i == array.size() || j <0) //����߽�
			return false;
		if (array[i][j] == target) { //�ҵ� ����true
			return true;
		}
		else if (array[i][j] > target) { //��ǰֵ��targetҪ����������
			j -= 1; //������
			return findValue(target, array, i, j);
		}
		else { //��ǰֵ��targetҪС����������
			i += 1;
			return findValue(target, array, i, j);
		}

	}
	bool Find(int target, vector<vector<int> > array) {
		if (array.empty())
			return false;
		return findValue(target, array, 0, array[0].size() - 1); //�ӵ�һ�����һ�п�ʼ����
	}
};



int main() {
	
	vector<vector<int>>v1 { {1, 2, 3}, { 4,5,6 }, { 7,8,9 }};
	if (Solution().Find(12, v1))
		cout << "�ҵ���" << endl;
	else
		cout << "û�ҵ�" << endl;
	system("pause");
	return 0;
}
*/

//��ѭ��ʵ��:
