#pragma once
#include "LinkedList.h"
class MathUtils
{
public:
	static bool ParseInt(String *str,long radix,long &out);
	static long Pow(long base, long times);

	template <typename T>
    // Pow的泛型版本，用同类数据运算加强精度
	static T PowGeneric(T base, T times) {
        if (times == 0 && base != 0) {//人为规定
            return 1;
        }
        T result = base;
        for (T i = 1; i < times; i++)
        {
            result = base * result;
        }

        return result;
	}
private:
	static bool ConvertCharToInt(char c,long &out);
};

