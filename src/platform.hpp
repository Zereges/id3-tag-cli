#pragma once
#include <string>
#include <vector>

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
#define MAIN wmain
#else
#define MAIN main
#endif


namespace platform
{
#ifdef _WIN32
    using char_t = wchar_t;
    using string = std::wstring; // windows uses UTF16BE
#elif __unix__
    using char_t = char;
    using string = std::string; // linux should use UTF8
#else
    static_assert("Error: Unknown platform");
#endif

    struct convert
    {
        static std::vector<std::string> convert_args(int argc, platform::char_t** argv)
        {
            std::vector<std::string> args;
            for (int i = 0; i < argc; ++i)
                args.push_back(from(argv[i]));
            return args;
        }

        static std::string from(const platform::char_t* str)
        {
#ifdef _WIN32
            int required_size = WideCharToMultiByte(CP_UTF8, 0, str, -1, nullptr, 0, nullptr, nullptr);
            std::string result(required_size, '\0');
            WideCharToMultiByte(CP_UTF8, 0, str, -1, result.data(), result.size(), nullptr, nullptr);
            result.resize(required_size - 1); // '\0'
            return result;
#else
            return str;
#endif
        }
    };
}
