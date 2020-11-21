#include "IOUtils.h"
#include <Windows.h> //�����������רҵ����ҵҪ�����Ͳ�����CMake��ƽ̨��

size_t ReadFileOnWindows(std::string file_path, char* &out_buf);

size_t IOUtils::ReadFile(std::string file_path, char* &out_buf)
{
    //����out_buf��Ҫ���ô�������Ϊout_buf��Ϊһ����ֵַ����������Ҫ��ֵ
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
    //ȷ����ȡָ�����ļ�ͷ
    if (SetFilePointer(hFile, 0, NULL, FILE_BEGIN)== INVALID_SET_FILE_POINTER) {
        out_buf = NULL;
        CloseHandle(hFile);
        return 0;
    }
    dwFileSize= GetFileSize(hFile,NULL); //��Ԥ�ڶ�ȡ���ļ��������ո�λ
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
