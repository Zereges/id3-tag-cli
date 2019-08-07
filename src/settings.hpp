#pragma once
#include <string>
#include <optional>
#include <exception>

#include <getopt.h>

#include "help.hpp"

struct arguments_parse_exception final : std::runtime_error
{
    explicit arguments_parse_exception(const std::string& msg)
        : runtime_error(msg)
    {
    }

    explicit arguments_parse_exception(const char* const msg)
        : runtime_error(msg)
    {
    }
};

class arguments
{
    arguments(bool help, bool version)
        : help(help), version(version)
    {
    }

public:
    static arguments parse_args(int argc, char* argv[])
    {
        for (;;)
        {
            static option options[] =
            {
                {    "help",       no_argument, nullptr, 'h' },
                { "version",       no_argument, nullptr, 'v' },
                {  "artist", required_argument, nullptr, 'a' },
                {   "title", required_argument, nullptr, 't' },
                {   "album", required_argument, nullptr, 'A' },
                {    "year", required_argument, nullptr, 'y' },
                {   "track", required_argument, nullptr, 'T' },
                {   "genre", required_argument, nullptr, 'g' },
                {   nullptr,                 0, nullptr,  0  }
            };

            int option_index = 0;
            int c = getopt_long(argc, argv, "hva:t:A:y:Y:g:", options, &option_index);
            if (c == -1)
                break;

            switch (c)
            {
            case 'h':
                return {true, false};
            case 'v':
                return {false, true};
            case 'a':

            }
        }
    }

    bool is_help() const
    {
        return help;
    }

    bool is_version() const
    {
        return version;
    }

    std::pair<bool, std::string> artist() const
    {
        return { m_artist.has_value(), m_artist.value_or("") };
    }

    void set_artist(std::string artist)
    {
        m_artist = std::move(artist);
    }

    std::pair<bool, std::string> title() const
    {
        return { m_title.has_value(), m_title.value_or("") };
    }

    void set_title(std::string title)
    {
        m_title = std::move(title);
    }

    std::pair<bool, std::string> album() const
    {
        return { m_album.has_value(), m_album.value_or("") };
    }

    void set_album(std::string album)
    {
        m_album = std::move(album);
    }

    std::pair<bool, int> year() const
    {
        return { m_year.has_value(), m_year.value_or(0) };
    }

    void set_year(int year)
    {
        m_year = year;
    }

    std::pair<bool, int> track() const
    {
        return { m_track.has_value(), m_track.value_or(0) };
    }

    void set_track(int track)
    {
        m_track = track;
    }

    std::pair<bool, std::string> genre() const
    {
        return { m_genre.has_value(), m_genre.value_or("") };
    }

    void set_genre(std::string genre)
    {
        m_genre = std::move(genre);
    }

private:
    bool help;
    bool version;
    std::optional<std::string> m_artist;
    std::optional<std::string> m_title;
    std::optional<std::string> m_album;
    std::optional<int> m_year;
    std::optional<int> m_track;
    std::optional<std::string> m_genre;
};
