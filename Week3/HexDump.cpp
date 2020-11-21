#include "HexDump.h"
#include "OffsetUtils.h"
#include <sstream>


void HexDump::Dump(char* ptr, size_t dump_size, size_t bytes_per_col)
{
	const char* split = "  ";
	//�����ͷ
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
		unsigned char current = ptr[i_pos]; //��ǰλ�ã�����unsigned�ڸ�����ʱ���������룬���Ҷ���
		//��ӡ��ͷ��ַ
		size_t row_offset = i_pos * bytes_per_col * sizeof(char); //ÿ�������ƫ��
		printf("%p(+%x)", &current, row_offset);

		PrintRowHeader(&current, row_offset);

		size_t row_str_size = bytes_per_col * sizeof(char) + 1; //�Ӹ�'\0'�ض����ڵ�ַ�ϵ���������
		char* row_as_str = (char*)malloc(row_str_size); //һ�е��ַ�����ʽ
		if (!row_as_str) {
			return;
		}
		memset(row_as_str, 0, row_str_size);
		for (size_t i_col = 0; i_col < bytes_per_col; i_col++)
		{
			current = ptr[current_offset];
			PrintByteAsHex(current);
			printf("  ");
			if (current >= 0x20 && current <= 0x7e) { //ASCII�ɴ�ӡ�ַ���0x20 - 0x7E�������ǿ��ַ���
				row_as_str[i_col] = current;
			}
			else {
				row_as_str[i_col] = '.';
			}
			printf("%s", split);
			current_offset++;
		}
		//��ӡ��β
		printf("	|%s|", row_as_str);
		printf("\n");
	}
}

void HexDump::PrintByteAsHex(unsigned char byte_c)
{
	if (byte_c <= 0xf) { //ֻ��һλ��Ϊ��������벹��0
		printf("0");
	}
	printf("%x", byte_c);
}

// �������׿ո�ʹ������루�ú�������stl�ɣ�����ƴ���ַ������ۻ
void HexDump::PrintRowHeader(unsigned char* current_addr, size_t offset)
{
	if (offset == 0) { //log10(0)�������max(double)
		offset = 1;
	}
	//һ����ֵ�10����ת16����ʵ��
	size_t dec_count = log10(offset) + 1;
	char* offset_str = (char*)malloc(dec_count+1); //��Ϊ16����λ��<=10����λ��������10����λ��������һ�����õ�
	if (!offset_str) {
		return;
	}
	memset(offset_str, 0, dec_count+1);
	sprintf_s(offset_str, dec_count+1, "%x", offset);
	std::stringstream ss;
	ss << "%" << (9 - strlen(offset_str) - 1) << "c\0";
	printf(ss.str().c_str(), ' ');//9='+'+sizeof(size_t) ȷ��dump_size����ʱ����ĵ�ַƫ�Ʋ���Ӱ����루���ǻ��ǻ���λ����Ҫ��ȥƫ�Ƶ�������ȣ�

}
