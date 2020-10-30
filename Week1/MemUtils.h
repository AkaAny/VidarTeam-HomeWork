#pragma once
#include "type_def.h"

class MemUtils
{
public:
	template <typename T>
	static T* MallocAndZero(size_t len) {
		return (T*) mallocAndFillInternal(len, 0);
	}

	template <typename T>
	static T** MallocAndZeroSpace(size_t x_len, size_t y_len) {
		size_t space_len = sizeof(T) * x_len * y_len;
		return (T**)mallocAndFillInternal(space_len, 0);
	}
private:
	static ptr_t mallocAndFillInternal(size_t len, int init_val);
};
