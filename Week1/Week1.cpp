// VidarTeam-HomeWork.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "C1_Akira.h"
#include "C1_Liki.h"
#include "C1_XiaoYu.h"
#include "C1_R4U.h"

int main()
{
    std::cout << "这是Any的第一周作业，按任意键继续" << std::endl;
    getchar();
    
    //akira的大小写
    std::cout << std::endl << "Akira的大小写" << std::endl;
    char str_for_akira[] = "This is a Test string";
    C1_Akira* c1_akira = new C1_Akira();
    c1_akira->PrintUpperOrLower(str_for_akira, sizeof(str_for_akira));

    //liki的图形
    std::cout << std::endl << "Liki的圆形" << std::endl;
    C1_Liki* c1_liki = new C1_Liki();
    c1_liki->DrawFunction(30, 30, [](DecInt x, DecInt y)->bool {
        DecInt tolerance = 2; //本来也想写外面的，但是这样的话callback的定义会因为泛型不明确
        DecInt radis = 4;
        DecInt result = MathUtils::PowGeneric<DecInt>(x, 2) + MathUtils::PowGeneric<DecInt>(y, 2);

        return abs(result - radis * radis) <= tolerance;
        });
    std::cout << std::endl << "Liki的心型线" << std::endl;
    c1_liki->DrawFunction(30, 30, [](DecInt x, DecInt y)->bool {
        DecInt tolerance = 2;
        DecInt x_square = MathUtils::PowGeneric<DecInt>(x, 2);
        DecInt x_s_cbrt = MathUtils::PowGeneric<DecInt>(x_square,0.3); //x的平方的立方根
        
        DecInt result = x_square + MathUtils::PowGeneric<DecInt>(y - x_s_cbrt, 2);
        return abs(result - 1) <= tolerance;
        });

    //xiaoyu的等式
    std::cout << std::endl << "xiaoyu的等式" << std::endl;
    char equation_for_xiaoyu[] = "b+c=17";
    C1_XiaoYu* c1_xiaoyu = new C1_XiaoYu();
    c1_xiaoyu->PrintMinEquation(equation_for_xiaoyu, sizeof(equation_for_xiaoyu));

    //R4U的约瑟夫环
    std::cout << std::endl << "R4U的约瑟夫环" << std::endl;
    C1_R4U* c1_r4u = new C1_R4U();
    c1_r4u->PrintWillBePicked(4, 3, 2);

    std::cout << "\nHello Vidar Team!\n";
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
