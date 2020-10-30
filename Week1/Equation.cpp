#include "Equation.h"
#include "MathUtils.h"
#include <cstdio>

void PrintAsString(const char* alias,String* str) {
	printf("\n--- %s ---\n", alias);
	str->EnumerateZ([](size_t index, char c)->void {
		printf("%d -> %c\n", index, c);
		});
}

void SubString(const char* buf, size_t buf_len,
	size_t start_index, size_t count) {
	const char* buf_start = &buf[start_index];
	String* n1 = new String('\0');
	for (size_t i = 0; i < count; i++)
	{
		n1->Append(buf_start[i]);
	}
}

String* Until(const char* buf, size_t buf_len, size_t &start_index, char c_until) {
	const char* buf_start = &buf[start_index];
	String* result = new String(*buf_start);
	start_index++;
	for (size_t i = 1; i < buf_len; i++)
	{
		char current = buf_start[i];
		start_index++;
		if (current == c_until){
			break;
		}
		result->Append(buf_start[i]);
	}
	return result;
}

Equation* Equation::Create(const char* buf, size_t buf_len, long radix)
{
	Equation* result = new Equation();
	//�ָ��ַ���
	size_t next_index = 0;
	
	//��һ����
	String* n1_str =Until(buf, buf_len, next_index, '+');
	//PrintAsString("��һ����", n1_str);
	if (!MathUtils::ParseInt(n1_str, radix, result->n1)) {
		return nullptr;
	}
	//�ڶ�����
	String* n2_str =Until(buf, buf_len, next_index, '=');
	//PrintAsString("�ڶ�����", n2_str);
	if (!MathUtils::ParseInt(n2_str, radix, result->n2)) {
		return nullptr;
	}
	//���
	String* result_str= Until(buf, buf_len, next_index, '\0');
	//PrintAsString("���", result_str);
	if (!MathUtils::ParseInt(result_str, radix, result->result)) {
		return nullptr;
	}
	return result;
}
