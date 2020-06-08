/************************************************************************/
/*@File Name         : 11旋转数字最小的数字.cpp
/*@Created Date      : 2020/6/2 9:36
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       :
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。*/
/************************************************************************/


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
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.empty())
			return 0;
		int left = 0;
		int right = rotateArray.size() - 1;

		//迭代找到最小值
		while (left < right) {
			int mid = (right + left) >> 1;
			if (rotateArray[mid] > rotateArray[right]) {
				//此时最小值在mid的右边部分
				left = mid + 1;
			}
			else if (rotateArray[mid] == rotateArray[right])
				right--;
			else
				right = mid;
		}
		return rotateArray[left];
	}
};