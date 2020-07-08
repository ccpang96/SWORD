

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

//����⻹��û����ɵģ�д���������ǲ��� 

class Solution {
private:
	//��С���е�Ԫ�ش�������
	vector<int>bigHeap;				//����	
	vector<int>littleHeap;			//��С��
	int numbers;						//���ݵ�����
public:
	void Insert(int num)
	{
		numbers++;
		if (numbers % 2 == 0) { //ż��
			//������С�� ��֤��С���е�Ԫ��Ҫ�������д������Ƚ���Ԫ�������ѵĶ�Ԫ�رȽϣ��������С���ȼ������ѣ�Ȼ����ȡ�����ѵ�
			//��Ԫ�ز�����С�ѣ������Ԫ�ر����ѵ����ֵ���Ǿ�ֱ�Ӽ�����С�ѡ�
			if (!bigHeap.empty() && num < bigHeap[0]) {

				//���󶥶ѵ����ֵ����С���ѣ�Ȼ��С�����ڲ����жѵ���
				littleHeapInsert(littleHeap,bigHeap[0]);
				 
				bigHeap.push_back(num);		//��������	
				swap(bigHeap[0], bigHeap[bigHeap.size() - 1]);	//�Ѷ�Ԫ����ĩβԪ�ؽ��� ���µ�Ԫ��λ�ڶѶ�
				bigHeap.pop_back();		//ɾ���Ѷ������ֵ
				 
			}
			else {
				littleHeapInsert(littleHeap,num);
			}
				
		}
		else {	//����
			//��������
			//ͬ������
			if (!littleHeap.empty() && num > littleHeap[0]) {
				bigHeapInsert(bigHeap,littleHeap[0]);	//�������ϵĽ��е���

				littleHeap.push_back(num);
				swap(littleHeap[0], littleHeap[littleHeap.size() - 1]);
				littleHeap.pop_back();

			}
			else {

				bigHeapInsert(bigHeap,num);
				 
			}
		}
	}

	double GetMedian()
	{
		if (numbers == 0)
			return 0.0;

		if (numbers % 2 == 0) { //ż����
			return static_cast<double>(bigHeap[0] + littleHeap[0]) / 2.0;
		}
		else {	//������
			return static_cast<double>(bigHeap[0]);
		}
	}


	//��С�Ѷѵ��� //�������µ���
	void adjustLittleHeap(vector<int>&input, int i, int length) {
		int temp = input[i];
		for (int k = 2 * i + 1; k < length; k = 2 * k + 1) {
			if (k + 1 < length && input[k + 1] < input[k])
				k = k + 1;

			if (input[k] < temp) {
				input[i] = input[k];
				i = k;
			}
			else
				break;
		}
		input[i] = temp;
	}


	//���Ѷѵ���
	void adjustBigHeap(vector<int>&input, int i, int length) {
		int temp = input[i];
		for (int k = 2 * i + 1; k < length; k = 2 * k + 1) {
			if (k + 1 < length && input[k + 1] > input[k])
				k = k + 1;

			if (input[k] > temp) {
				input[i] = input[k];
				i = k;
			}
			else
				break;
		}
		input[i] = temp;
	}


	//�󶥶ѵĲ���
	void bigHeapInsert(vector<int>&input, int val) {
		input.push_back(val);	//����ѵ�β��
		
		int temp = val;
		int i = input.size() - 1;
		
		for (int k = floor(double(i - 1) / 2.0); k >= 0; k = floor(double((k - 1)) / 2)) {
			if (temp > input[k]) {
				input[i] = input[k];
				i = k;
			}
			else
				break;
		}
		input[i] = temp;
	}

	//С���ѵĲ���
	void littleHeapInsert(vector<int>&input, int val) {
		input.push_back(val);	//����ѵ�β��

		int temp = val;
		int i = input.size() - 1;

		for (int k = floor(double(i - 1) / 2.0); k >= 0; k = floor(double((k - 1)) / 2)) {
			if (temp < input[k]) {
				input[i] = input[k];
				i = k;
			}
			else
				break;
		}
		input[i] = temp;
	}

	
};

//int main() {
//	Solution s;
//
//	cout << endl;
//	s.Insert(5);
//	cout << s.GetMedian() << endl;
//	s.Insert(2);
//	cout << s.GetMedian() << endl;
//	s.Insert(3);
//	cout <<s.GetMedian() << endl;
//	s.Insert(4);
//	cout <<s.GetMedian() << endl;
//	s.Insert(1);
//	cout <<s.GetMedian() << endl;
//	s.Insert(6);
//	cout <<s.GetMedian() << endl;
//	s.Insert(7);
//	cout << s.GetMedian() << endl;
//	s.Insert(0);
//	cout << s.GetMedian() << endl;
//	s.Insert(8);
//	cout << s.GetMedian() << endl;
//	system("pause");
//	return 0;
//}