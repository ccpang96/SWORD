

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

//这个题还是没有完成的，写出来的总是不对 

class Solution {
private:
	//最小堆中的元素大于最大堆
	vector<int>bigHeap;				//最大堆	
	vector<int>littleHeap;			//最小堆
	int numbers;						//数据的总数
public:
	void Insert(int num)
	{
		numbers++;
		if (numbers % 2 == 0) { //偶数
			//加入最小堆 保证最小堆中的元素要比最大堆中大，所以先将新元素与最大堆的顶元素比较，如果比它小就先加入最大堆，然后再取出最大堆的
			//顶元素插入最小堆；如果新元素比最大堆的最大值大，那就直接加入最小堆。
			if (!bigHeap.empty() && num < bigHeap[0]) {

				//将大顶堆的最大值插入小顶堆，然后小顶堆内部进行堆调整
				littleHeapInsert(littleHeap,bigHeap[0]);
				 
				bigHeap.push_back(num);		//加入最大堆	
				swap(bigHeap[0], bigHeap[bigHeap.size() - 1]);	//堆顶元素与末尾元素交换 让新的元素位于堆顶
				bigHeap.pop_back();		//删除堆顶的最大值
				 
			}
			else {
				littleHeapInsert(littleHeap,num);
			}
				
		}
		else {	//奇数
			//加入最大堆
			//同理如上
			if (!littleHeap.empty() && num > littleHeap[0]) {
				bigHeapInsert(bigHeap,littleHeap[0]);	//自下往上的进行调整

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

		if (numbers % 2 == 0) { //偶数个
			return static_cast<double>(bigHeap[0] + littleHeap[0]) / 2.0;
		}
		else {	//是奇数
			return static_cast<double>(bigHeap[0]);
		}
	}


	//最小堆堆调整 //从上往下调整
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


	//最大堆堆调整
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


	//大顶堆的插入
	void bigHeapInsert(vector<int>&input, int val) {
		input.push_back(val);	//插入堆的尾部
		
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

	//小顶堆的插入
	void littleHeapInsert(vector<int>&input, int val) {
		input.push_back(val);	//插入堆的尾部

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