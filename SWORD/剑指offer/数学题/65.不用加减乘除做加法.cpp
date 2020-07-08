/************************************************************************/
/*@File Name         : 65.不用加减乘除做加法.cpp
/*@Created Date      : 2020/6/11 21:22
/*@Author            : ccpang(ccpang96@163.com)
/*@blog              : www.cnblogs.com/ccpang
/*@Description       :
/************************************************************************/

class Solution {
public:
	int Add(int num1, int num2)
	{
		while (num2 != 0) {
			int temp = num1 ^ num2; //各位相加不算进位
			num2 = (num1  & num2) << 1; //计算进位
			num1 = temp;
		}
		return num1;
	}
};

