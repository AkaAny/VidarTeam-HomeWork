#pragma once
#include "LinkedList.h"
class Equation {
public:
	static Equation* Create(const char* buf, size_t buf_len,long radix);

	bool IsValid() {
		return (n1 + n2 == result);
	}
private:
	long n1, n2, result;
};

