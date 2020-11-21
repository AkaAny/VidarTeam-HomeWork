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
	// ���ͳ�������������<����ʱ�������س�������
	static T Divide(T be_divided, T div_num, T &out_rem) {
		out_rem = be_divided % div_num; //������ǣ���������С�ڳ�����%���������0�����Ǳ���������
		if (be_divided < div_num) {
			out_rem = be_divided;
		}
		return be_divided / div_num;
	}
	template <typename T>
	// Pow�ķ��Ͱ汾����ͬ�����������ǿ����
	static T PowGeneric(T base, T times) {
		if (times == 0 && base != 0) {//��Ϊ�涨
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

