#include "BinarySum.h"
#include "IntConverter.h"
#include <iostream>

void BinarySum::DoBinarySum(unsigned int input_num)
{
	size_t result = 0;
	std::list<UDec> bin_list; //������һ��stl�ɣ���������ʵ��һ��ByteBuf��
	IntConverter::ConvertTo(input_num,2, bin_list);
	for (auto itor = bin_list.begin(); itor != bin_list.end(); itor++)
	{
		if (*itor == 1) {
			result++;
		}
	}
	std::cout << "1�ĳ��ִ�����" << result << std::endl;
}
