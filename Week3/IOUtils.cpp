#include "IOUtils.h"
#include <Windows.h> //做完这个还有专业课作业要做，就不配置CMake跨平台了

size_t ReadFileOnWindows(std::string file_path, char* &out_buf);

size_t IOUtils::ReadFile(std::string file_path, char* &out_buf)
{
    //这里out_buf需要引用传递是因为out_buf作为一个地址值来看待，需要赋值
    return ReadFileOnWindows(file_path, out_buf);
}

size_t ReadFileOnWindows(std::string file_path, char* &out_buf) {
    DWORD dwActualRead = 0;
    DWORD dwFileSize = 0;
    HANDLE hFile= CreateFileA(file_path.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL,
        OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE) {
        out_buf = NULL;
        CloseHandle(hFile);
        return 0;
    }
    //确保读取指针在文件头
    if (SetFilePointer(hFile, 0, NULL, FILE_BEGIN)== INVALID_SET_FILE_POINTER) {
        out_buf = NULL;
        CloseHandle(hFile);
        return 0;
    }
    dwFileSize= GetFileSize(hFile,NULL); //不预期读取大文件，不接收高位
    if (dwFileSize == INVALID_FILE_SIZE) {
        out_buf = NULL;
        CloseHandle(hFile);
        return 0;
    }
    out_buf = (char*)malloc(dwFileSize);
    memset(out_buf, 0, dwFileSize);
    if (!ReadFile(hFile, out_buf, dwFileSize, &dwActualRead, NULL)) {
        out_buf = NULL;
    }
    CloseHandle(hFile);
    return dwActualRead;
}
