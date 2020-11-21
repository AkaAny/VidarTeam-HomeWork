#pragma once
#include <cstdlib>
#include <cstring>

class MemUtils
{
public:
	template <typename T>
	//��̬����һ����ά���飬����MeZoneѧ����˼·���о����˼·����������̬����Nά���飩
	static T** AllocSecondDimArray(size_t row_num, size_t col_num) {
		T** pp = (T**)malloc(row_num * sizeof(T*));
		if (!pp) {
			return nullptr;
		}
		for (size_t i_row = 0; i_row < row_num; i_row++)
		{
			size_t col_size = col_num * sizeof(T);
			pp[i_row] = (T*)malloc(col_size); //����һ��
			memset(pp[i_row], 0, col_size);
		}
		return pp;
	}
};

