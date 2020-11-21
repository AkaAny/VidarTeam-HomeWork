#pragma once
#include "type_def.h"
#include <string>
#include <list>
class IntConverter
{
public:
	static size_t GetNumberCount(UDec num);
	static bool ConvertTo(UDec dec_num, UDec dst, std::list<UDec>& result);
	static bool ItoA(UDec dec_num, UDec dst, std::list<std::string>& result);
	
private:
	template <typename T>
	// 泛型除法，当被除数<除数时余数返回除数本身
	static T Divide(T be_divided, T div_num, T &out_rem) {
		out_rem = be_divided % div_num; //奇妙的是，当被除数小于除数，%运算符返回0而不是被除数本身
		if (be_divided < div_num) {
			out_rem = be_divided;
		}
		return be_divided / div_num;
	}
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
	
};

