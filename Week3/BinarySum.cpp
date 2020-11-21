#include "BinarySum.h"
#include "IntConverter.h"
#include <iostream>

void BinarySum::DoBinarySum(unsigned int input_num)
{
	size_t result = 0;
	std::list<UDec> bin_list; //让我用一下stl吧，不想重新实现一个ByteBuf了
	IntConverter::ConvertTo(input_num,2, bin_list);
	for (auto itor = bin_list.begin(); itor != bin_list.end(); itor++)
	{
		if (*itor == 1) {
			result++;
		}
	}
	std::cout << "1的出现次数：" << result << std::endl;
}
