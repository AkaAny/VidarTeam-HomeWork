#pragma once
enum CharType
{
	UPPER, //��д��ĸ
	LOWER, //Сд��ĸ
	UNKNOWN //δ֪���ǿ���ʾ�ַ���
};
class C1_Akira
{
public:
	void PrintUpperOrLower(const char* str,size_t str_len);
private:
	CharType GetCharType(char c);
};

