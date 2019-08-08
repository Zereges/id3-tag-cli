#pragma once
#include <string>
#include <vector>
#include <iostream>

#ifdef _MSC_VER
  #define TAGLIB_HEADERS_BEGIN __pragma(warning(disable: 4251))
#else
  #define TAGLIB_HEADERS_BEGIN
#endif

#ifdef _MSC_VER
  #define TAGLIB_HEADERS_END __pragma(warning(default: 4251))
#else
  #define TAGLIB_HEADERS_END
#endif

#ifdef _MSC_VER
  #include <Windows.h>
  #include <io.h>
  #include <fcntl.h>
#define MAIN wmain
#else
#define MAIN main
#endif

namespace platform
{
#ifdef _WIN32
    inline struct static_initialization
    {
        static_initialization()
        {
            constexpr char cp_utf16le[] = ".1200";
            setlocale(LC_ALL, cp_utf16le);
            _setmode(_fileno(stdout), _O_WTEXT);
        }
    } init;

    using char_t = wchar_t;
    using string = std::wstring; // windows uses UTF16BE
    using stream = std::wostream;
    inline stream& cout = std::wcout;

    #define PS(x) L ## x
#elif __unix__
    using char_t = char;
    using string = std::string; // linux should use UTF8
    using stream = std::ostream;
    inline stream& cout = std::cout;

    #define PS(x) x
#else
    static_assert("Error: Unknown platform");
#endif

    struct convert
    {
        static std::vector<std::string> convert_args(int argc, platform::char_t** argv)
        {
            std::vector<std::string> args;
            for (int i = 0; i < argc; ++i)
                args.push_back(from_platform(argv[i]));
            return args;
        }

        static std::string from_platform(const platform::char_t* str)
        {
#ifdef _WIN32
            int required_size = ::WideCharToMultiByte(CP_UTF8, 0, str, -1, nullptr, 0, nullptr, nullptr);
            std::string result(required_size, '\0');
            ::WideCharToMultiByte(CP_UTF8, 0, str, -1, result.data(), result.size(), nullptr, nullptr);
            result.resize(required_size - 1); // '\0'
            return result;
#else
            return str;
#endif
        }

        static platform::string to_platform(const std::string& str)
        {
#ifdef _WIN32
            int required_size = ::MultiByteToWideChar(CP_UTF8, 0, str.data(), -1, nullptr, 0);
            platform::string result(required_size, L'\0');
            ::MultiByteToWideChar(CP_UTF8, 0, str.data(), -1, result.data(), result.size());
            result.resize(required_size - 1); // L'\0'
            return result;
#else
            return str;
#endif
        }

    };
}
