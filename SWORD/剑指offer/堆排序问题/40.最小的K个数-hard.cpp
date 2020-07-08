/************************************************************************/
/*@File Name         : 40.最小的K个数.cpp
/*@Created Date      : 2020/6/9 9:49
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       : 输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
/************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<sstream>
#include<queue>
#include<stack>
#include<ctime>
#include<cassert>
using namespace std;



//这种sort的方法是不会被通过的
//class Solution {
//public:
//	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
//		vector<int>result;
//
//		if (input.size() == 0 || k == 0 || input.size() < k)
//			return result;
//
//		sort(input.begin(), input.end());
//
//		for (int i = 0; i < k; i++) {
//			result.push_back(input[i]);
//		}
//		return result;
//	}
//};
//
//



class Solution {
public:

	//构建大小为k的堆
	vector<int>GetLeastNumbers_Solution(vector<int>input, int k) {
		vector<int>heap;
		if (input.empty() || k == 0 || input.size() < k)
			return heap;


		for (int i = 0; i < k; i++) {
			heap.push_back(input[i]);
		}

		buildHeap(heap);

		for (int i = k; i < input.size(); i++) {
			if (input[i] < heap[0]) {
				heap[0] = input[i];
				adjustHeap(heap, 0, k);
			}
		}
		return heap;
	}
	


	//构建的大小为input.size()的堆
	vector<int>GetLeastNumbers(vector<int>input, int k) {

		vector<int>result;
		if (input.empty() || k == 0 || input.size() < k)
			return result;

		buildHeap(input);

		for (int i = input.size() - 1; i >= k; i--) {
			swap(input[0], input[i]);
			adjustHeap(input, 0, i);
		}

		for (int i = 0; i < k; i++) {
			result.push_back(input[input.size() - 1 - i]);
		}
		return result;
	}




	//构建大顶堆
	void buildHeap(vector<int>& heap) {
		//只对父节点进行调整
		for (int i = heap.size() / 2 - 1; i >= 0; i--) {
			adjustHeap(heap, i, heap.size());
		}
	}

	//调整大顶堆
	void adjustHeap(vector<int>&heap, int i, int length) {
		int temp = heap[i];
		for (int k = 2 * i + 1; k < length; k = 2 * k + 1) {
			if (k + 1 < length && heap[k + 1] > heap[k])
				k = k + 1;

			if (heap[k] > temp) {
				heap[i] = heap[k];
				i = k;
			}
			else
				break;
		}
		heap[i] = temp;
	}
};



//函数一： 生成一个含有n个在[range_l,range_r]之间元素的数组
vector<int> generateRandomArray(int n, int range_l, int range_r) {
	assert(range_l <= range_r);
	vector<int>input;

	srand(time(NULL));
	for (int i = 0; i < n; i++)
		input.push_back(rand() % (range_r - range_l + 1) + range_l);
	return input;
}




//int main() {
//
//
//	clock_t startTime = clock();
//	vector<int> input = generateRandomArray(1e+7, 1, 1e+7);
//	vector<int>result = Solution().GetLeastNumbers_Solution(input, 40);
//
//	//vector<int>result = Solution().GetLeastNumbers(input, 40);
//
//	for (auto &m : result)
//		cout << m << endl;
//
//	clock_t endTime = clock();
//	cout << "运行时间：" << double(endTime - startTime) / CLOCKS_PER_SEC * 1000 << "毫秒" << endl;
//	system("pause");
//	return 0;
//}
