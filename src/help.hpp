#pragma once
#include <iostream>
#include <iomanip>
#include <string>

constexpr static int VERSION = 110;

inline void print_usage(std::ostream& stream, const std::string& exe_name)
{
    stream << "Usage: " << exe_name << " [options] file" << std::endl;
}

inline void print_version_info()
{
    std::cout
        << "id3-tags-cli " << std::fixed << std::setprecision(2) << VERSION / 100.0 << "\n"
        << "License GPL-3.0: GNU GPL version 3 <https://www.gnu.org/licenses/>" << "\n"
        << "This is free software: you are free to change and redistribute it." << "\n"
        << "This program comes with ABSOLUTELY NO WARRANTY!" << "\n"
        << "\n"
        << "Written by Zereges <https://github.com/Zereges/id3-tag-cli>" << std::endl
        ;
}

inline void print_help(const std::string& exe_name)
{
    print_usage(std::cout, exe_name);
    std::cout
        << "\n"
        << "    " << "-h" << " | " << "    --help" << "    " << "Prints this help and exits." << "\n"
        << "    " << "-v" << " | " << " --version" << "    " << "Prints version information and exits." << "\n"
        << "    " << "-a" << " | " << "  --artist" << "    " << "[STR] Sets the Artist/Performer." << "\n"
        << "    " << "-t" << " | " << "   --title" << "    " << "[STR] Sets the Title/Song name/Content." << "\n"
        << "    " << "-A" << " | " << "   --album" << "    " << "[STR] Sets the Album/Movie/Show title." << "\n"
        << "    " << "-y" << " | " << "    --year" << "    " << "[INT] Sets the Year." << "\n"
        << "    " << "-T" << " | " << "   --track" << "    " << "[INT] Sets the Track number/Position." << "\n"
        << "    " << "-g" << " | " << "   --genre" << "    " << "[STR] Sets the Genre." << "\n"
        << "\n"
        << "  " << "[STR] -  String type" << "\n"
        << "  " << "[INT] - Integer type" << "\n"
        << "\n"
        << "  " << "If no arguments are specified, information of given file is retrieved." << "\n"
        << "  " << "If the option is not specified, the value is unchanged." << "\n"
        << "  " << "If the argument is empty string (\"\") (for [STR]) or 0 (for [INT]) the value is cleared." << "\n"
        << "\n"
        << "Written by Zereges <https://github.com/Zereges/id3-tag-cli>" << std::endl
        ;
}
