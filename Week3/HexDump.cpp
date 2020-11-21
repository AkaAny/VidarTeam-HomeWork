#include "HexDump.h"
#include "OffsetUtils.h"
#include <sstream>


void HexDump::Dump(char* ptr, size_t dump_size, size_t bytes_per_col)
{
	const char* split = "  ";
	//输出列头
	printf("%9c+%8c", ' ', ' ');//9=sizeof(void*)+'(' 8=tab+"  "+%x
	for (size_t i_col = 0; i_col < bytes_per_col; i_col++)
	{
		printf("%x", i_col);
		printf("%4c",' ');
	}
	printf("\n");
	size_t current_offset = 0;
	for (size_t i_pos = 0; i_pos < dump_size; i_pos++)
	{
		unsigned char current = ptr[i_pos]; //当前位置，不用unsigned在负数的时候会输出补码，打乱对齐
		//打印列头地址
		size_t row_offset = i_pos * bytes_per_col * sizeof(char); //每行首项的偏移
		printf("%p(+%x)", &current, row_offset);

		PrintRowHeader(&current, row_offset);

		size_t row_str_size = bytes_per_col * sizeof(char) + 1; //加个'\0'截断相邻地址上的垃圾数据
		char* row_as_str = (char*)malloc(row_str_size); //一行的字符串形式
		if (!row_as_str) {
			return;
		}
		memset(row_as_str, 0, row_str_size);
		for (size_t i_col = 0; i_col < bytes_per_col; i_col++)
		{
			current = ptr[current_offset];
			PrintByteAsHex(current);
			printf("  ");
			if (current >= 0x20 && current <= 0x7e) { //ASCII可打印字符：0x20 - 0x7E（不考虑宽字符）
				row_as_str[i_col] = current;
			}
			else {
				row_as_str[i_col] = '.';
			}
			printf("%s", split);
			current_offset++;
		}
		//打印列尾
		printf("	|%s|", row_as_str);
		printf("\n");
	}
}

void HexDump::PrintByteAsHex(unsigned char byte_c)
{
	if (byte_c <= 0xf) { //只有一位，为了输出对齐补个0
		printf("0");
	}
	printf("%x", byte_c);
}

// 处理行首空格，使输出对齐（让孩子用用stl吧，这种拼接字符串的累活）
void HexDump::PrintRowHeader(unsigned char* current_addr, size_t offset)
{
	if (offset == 0) { //log10(0)输出的是max(double)
		offset = 1;
	}
	//一种奇怪的10进制转16进制实现
	size_t dec_count = log10(offset) + 1;
	char* offset_str = (char*)malloc(dec_count+1); //因为16进制位数<=10进制位数，按照10进制位数分配是一定够用的
	if (!offset_str) {
		return;
	}
	memset(offset_str, 0, dec_count+1);
	sprintf_s(offset_str, dec_count+1, "%x", offset);
	std::stringstream ss;
	ss << "%" << (9 - strlen(offset_str) - 1) << "c\0";
	printf(ss.str().c_str(), ' ');//9='+'+sizeof(size_t) 确保dump_size过大时后面的地址偏移不会影响对齐（但是还是会移位，需要减去偏移的输出长度）

}
