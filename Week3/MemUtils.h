#pragma once
#include <cstdlib>
#include <cstring>

class MemUtils
{
public:
	template <typename T>
	//动态分配一个二维数组，来自MeZone学长的思路（感觉这个思路可以用来动态分配N维数组）
	static T** AllocSecondDimArray(size_t row_num, size_t col_num) {
		T** pp = (T**)malloc(row_num * sizeof(T*));
		if (!pp) {
			return nullptr;
		}
		for (size_t i_row = 0; i_row < row_num; i_row++)
		{
			size_t col_size = col_num * sizeof(T);
			pp[i_row] = (T*)malloc(col_size); //分配一列
			memset(pp[i_row], 0, col_size);
		}
		return pp;
	}
};

