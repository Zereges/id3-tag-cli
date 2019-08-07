#include <iostream>
#include <optional>

#include "platform.hpp"

TAGLIB_HEADERS_BEGIN
  #include <taglib/tag.h>
  #include <taglib/fileref.h>
TAGLIB_HEADERS_END

#include "arguments.hpp"
#include "help.hpp"

bool process_file(arguments&& args)
{
    /*
        TagLib::FileRef f(argv[1]);
        f.tag()->setTitle(argv[2]);
        f.save();
    */
    return true;
}

constexpr static const int RETURN_OK = 0;
constexpr static const int RETURN_ERROR = 1;

int MAIN(int argc, platform::char_t* argv[])
{
    std::string exe_name = platform::convert::from(argv[0]);
    std::optional<arguments> args;
    try
    {
        auto arg_vec = platform::convert::convert_args(argc, argv);
        args = arguments::parse_args(argc, arg_vec);
    }
    catch (const arguments_parse_exception& ex)
    {
        std::cerr << ex.what() << "\n";
        print_usage(std::cerr, exe_name);
        return RETURN_ERROR;
    }

    if (args->is_help())
    {
        print_help(exe_name);
        return RETURN_OK;
    }
    if (args->is_version())
    {
        print_version_info();
        return RETURN_OK;
    }

    if (!process_file(std::move(args.value())))
    {
        print_usage(std::cerr, exe_name);
        return RETURN_ERROR;
    }
}
