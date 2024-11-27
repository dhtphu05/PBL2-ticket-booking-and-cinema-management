
#include <string>
#include <iostream>
#ifndef UNICODE
#define UNICODE
// Chuyển đổi từ wchar_t sang UTF-8 mà không sử dụng std::vector

#include <windows.h> // Để sử dụng API chuyển đổi giữa các kiểu mã hóa

// Chuyển đổi từ UTF-8 (hoặc bất kỳ mã hóa nào) sang std::wstring (Unicode)
std::wstring convertToWString(const std::string &str)
{
    int len = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);
    std::wstring wstr(len, 0);
    MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, &wstr[0], len);
    return wstr;
}

// Chuyển đổi từ std::wstring (Unicode) về UTF-8
std::string convertToUTF8(const std::wstring &wstr)
{
    int len = WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, NULL, 0, NULL, NULL);
    std::string str(len, 0);
    WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, &str[0], len, NULL, NULL);
    return str;
}
std::string wchar_to_utf8(std::string &wstr)
{
    std::wstring str = convertToWString(wstr);
    return convertToUTF8(str);
}
#endif