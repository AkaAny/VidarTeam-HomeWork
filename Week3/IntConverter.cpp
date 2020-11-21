#include "IntConverter.h"
#include <cstring>
#include <cstdio>
#include <sstream>

size_t IntConverter::GetNumberCount(UDec num)
{
	std::stringstream ss;
	ss << num;
	size_t dec_count = ss.str().length();
	return dec_count;
}

// 十进制转任意进制
bool IntConverter::ConvertTo(UDec dec_num,UDec dst,std::list<UDec> &result)
{
	size_t max_bit_size = GetNumberCount(dst)+1; //每一位的最大长度，不可能超过进制数本身
	UDec rem = 0;
	while (true) {
		UDec rem = 0;
		dec_num= Divide<UDec>(dec_num, dst, rem);
		/*char* bit_str = (char*)malloc(max_bit_size);
		if (!bit_str) {
			return false;
		}
		memset(bit_str, 0, max_bit_size);
		_itoa_s(rem, bit_str, max_bit_size, dst);
		printf("%s", bit_str);*/
		result.push_front(rem);
		if (dec_num < dst) {
			result.push_front(dec_num);
			break;
		}
	}
	return true;
}