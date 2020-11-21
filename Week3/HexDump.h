#pragma once
class HexDump
{
public:
	void Dump(char* ptr, size_t dump_size, size_t bytes_per_col);
private:
	void PrintByteAsHex(unsigned char byte_c);
	void PrintRowHeader(unsigned char* current_addr, size_t offset);
};

