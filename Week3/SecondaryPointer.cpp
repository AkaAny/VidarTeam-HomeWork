#include "SecondaryPointer.h"
#include "MemUtils.h"
#include <cstdio>
#include <cstdlib>

void SecondaryPointer::DoSecondaryPointer()
{
	size_t row_num = 10;
	size_t col_num = 20;
	int** pp= MemUtils::AllocSecondDimArray<int>(row_num, col_num);
	int current_val = 0;
	for (size_t i_row = 0; i_row < row_num; i_row++)
	{
		for (size_t i_col = 0; i_col < col_num; i_col++)
		{
			pp[i_row][i_col] = current_val;
			current_val++;
		}
	}
	test(pp);
}

void SecondaryPointer::test(int** pp) {
	for (size_t i = 0; i < 10; i++)
	{
		for (size_t j = 0; j < 20; j++)
		{
			printf("%3d, ", pp[i][j]);
		}
		puts("");
	}
}

