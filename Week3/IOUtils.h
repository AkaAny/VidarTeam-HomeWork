#pragma once
#include <string>
class IOUtils
{
public:
	static size_t ReadFile(std::string file_path,char* &out_buf);
};

