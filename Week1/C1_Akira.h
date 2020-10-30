#pragma once
enum CharType
{
	UPPER, //大写字母
	LOWER, //小写字母
	UNKNOWN //未知（非可显示字符）
};
class C1_Akira
{
public:
	void PrintUpperOrLower(const char* str,size_t str_len);
private:
	CharType GetCharType(char c);
};

