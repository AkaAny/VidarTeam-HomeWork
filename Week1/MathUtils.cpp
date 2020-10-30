#include "MathUtils.h"
#include <algorithm>

bool MathUtils::ParseInt(String* str,long radix,long &out)
{
    bool valid = true;
    out = 0;
    if (!str) {
        return false;
    }
    str->EnumerateZ([radix,&valid,&out](size_t index, char c)->void {
        long bit = 0;
         bool convertable = ConvertCharToInt(c,bit);
        if (!convertable || radix <= bit) { //非法输入
            valid = false;
            return;
        }
        //printf("Z %d bit:%ld\n", index, bit);
        long role = Pow(radix, index); //权
        //printf("Z %d pow:%ld\n", index, role);
        out += bit * role;
        });
    return valid;
}

long MathUtils::Pow(long base, long times)
{
    if (times == 0 && base != 0) {//人为规定
        return 1;
    }
    long result = base;
    for (long i = 1; i < times; i++)
    {
        result = base * result;
    }
    
    return result;
}

bool MathUtils::ConvertCharToInt(char c,long &out)
{
    if (c == '\0') {
        out= 0;
        return true;
    }
    if (c >= '0' && c <= '9') {
        out= c - '0';/*将数字字符转换成数字*/
        return true;
    }
    if (c >= 'A' && c <= 'Z') {
        out= c - 'A' + 10;
        return true;
    }
    if (c >= 'a' && c <= 'z') {
        out= c - 'a' + 10;
        return true;
    }
    return false;
}
