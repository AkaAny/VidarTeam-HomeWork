#include "C1_Akira.h"
#include "MemUtils.h"
#include "LinkedList.h"
#include <cstring>
#include <cstdlib>
#include <cstdio>

void C1_Akira::PrintUpperOrLower(const char* buf, size_t buf_len)
{
	char* const upper_buf = MemUtils::MallocAndZero<char>(buf_len);
	int upper_count = 0;

	char* const lower_buf = MemUtils::MallocAndZero<char>(buf_len);
	int lower_count = 0;

	for (size_t i = 0; i < buf_len; i++)
	{
		char current_char = buf[i];
		//printf("pos:%d char:%c\n", i, current_char);
		//先统一存入原字符
		upper_buf[i] = current_char;
		lower_buf[i] = current_char;
		switch (GetCharType(current_char)) 
		{
		case UPPER: //大写字母，转换成小写
			lower_buf[i] = current_char + 32;
			upper_count++;
			break;
		case LOWER: //小写字母，转换成大写
			upper_buf[i] =current_char - 32;
			break;
		default:
			break;
		}
	}

	if (upper_count > lower_count){
		printf("%s\n", upper_buf);
		return;
	}
	if (upper_count < lower_count) {
		printf("%s\n", lower_buf);
		return;
	}
	printf("upper_buf:%s\nlower_buf:%s\n", upper_buf, lower_buf);
}

CharType C1_Akira::GetCharType(char c)
{
	if (c >= 'a' && c <= 'z') {
		return LOWER;
	}
	if (c >= 'A' && c <= 'Z') {
		return UPPER;
	}
	return UNKNOWN;
}
