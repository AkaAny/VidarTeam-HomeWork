// Week3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <Windows.h> //PE头结构
#include "BinarySum.h"
#include "SecondaryPointer.h"
#include "HexDump.h"
#include "IOUtils.h"
#include "IntConverter.h"

int main()
{
    std::cout << "这是Any的第三周作业，第二周咕咕了，按任意键继续" << std::endl;
    getchar();

    //二进制统计
    BinarySum* b_sum = new BinarySum();
    b_sum->DoBinarySum(12345);

    //二级指针
    SecondaryPointer* sec_pointer = new SecondaryPointer();
    sec_pointer->DoSecondaryPointer();

    //HexDump
    HexDump* hex_dump = new HexDump();
    //读取一个PE文件
    char* buf = NULL;
    size_t buf_len = IOUtils::ReadFile("..\\Debug\\Week3.exe", buf);
    hex_dump->Dump(buf,
        sizeof(IMAGE_DOS_HEADER) + sizeof(IMAGE_NT_HEADERS), 10); //加NT头是为了看到This prgram cannot be run in DOS mode

    std::cout << "\nHello Vidar Team!\n";
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
