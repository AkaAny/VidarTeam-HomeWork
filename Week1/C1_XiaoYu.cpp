#include "C1_XiaoYu.h"
#include "Equation.h"
#include <cstdio>

void C1_XiaoYu::PrintMinEquation(const char* buf, size_t buf_len)
{
	String* full = String::Create(buf, buf_len);
	//分割字符串
	printf("equaltion:%s\n", buf);
	Equation* eq2 = Equation::Create(buf, buf_len, 2);
	if (eq2 && eq2->IsValid()) {
		printf("是二进制n");
		return;
	}
	Equation* eq10 = Equation::Create(buf, buf_len, 10);
	if (eq10 && eq10->IsValid()) {
		printf("是10进制\n");
		return;
	}
	Equation* eq16 = Equation::Create(buf, buf_len, 16);
	if (eq16 && eq16->IsValid()) {
		printf("是16进制\n");
		return;
	}

}