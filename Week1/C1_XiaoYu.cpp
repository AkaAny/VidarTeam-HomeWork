#include "C1_XiaoYu.h"
#include "Equation.h"
#include <cstdio>

void C1_XiaoYu::PrintMinEquation(const char* buf, size_t buf_len)
{
	String* full = String::Create(buf, buf_len);
	//�ָ��ַ���
	printf("equaltion:%s\n", buf);
	Equation* eq2 = Equation::Create(buf, buf_len, 2);
	if (eq2 && eq2->IsValid()) {
		printf("�Ƕ�����n");
		return;
	}
	Equation* eq10 = Equation::Create(buf, buf_len, 10);
	if (eq10 && eq10->IsValid()) {
		printf("��10����\n");
		return;
	}
	Equation* eq16 = Equation::Create(buf, buf_len, 16);
	if (eq16 && eq16->IsValid()) {
		printf("��16����\n");
		return;
	}

}