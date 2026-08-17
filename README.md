# ID3TagCLI
ID3 Tag CLI is a simple portable command line utility used for reading and editing ID3 meta information (tags) of audio and video files. It internally uses [TagLib](https://github.com/taglib/taglib) library.

## Features
 - Allows read and modification of artist, title, album, year, track number and genre of MP3, OGG, FLAC, Speex, WavPack, TrueAudio, WAV, AIFF, MP4 and ASF files
 - Supports Unicode on both Windows and Linux
 - Is portable
 - Is flexible
 - Is easy to use

## Usage

```
Usage: id3-tags-cli [options] file

    -h |     --help    Prints this help and exits.
    -v |  --version    Prints version information and exits.
    -a |   --artist    [STR] Sets the Artist/Performer.
    -t |    --title    [STR] Sets the Title/Song name/Content.
    -A |    --album    [STR] Sets the Album/Movie/Show title.
    -y |     --year    [INT] Sets the Year.
    -T |    --track    [INT] Sets the Track number/Position.
    -g |    --genre    [STR] Sets the Genre.

  [STR] -  String type
  [INT] - Integer type

  If no arguments are specified, information of given file is retrieved.
  If the option is not specified, the value is unchanged.
  If the argument is empty string ("") (for [STR]) or 0 (for [INT]) the value is cleared.

Written by Zereges <https://github.com/Zereges/id3-tag-cli>
```

### Examples
```
$ id3-tags-cli -a AC⚡DC -t Thunderstruck --album "The Razors Edge" -g "" acdc-thunder.mp3
$ id3-tags-cli adcd-thunder.mp3
Information for file adcd-thunder.mp3
Artist: AC⚡DC
 Title: Thunderstruck
 Album: The Razors Edge
  Year: 0
 Track: 0
 Genre:
```

## Installation
### Windows
Get latest release from [Releases](https://github.com/Zereges/id3-tag-cli/releases) page. Place it somewhere and optionally add it to the `PATH`.

### Linux
You will have to compile the application from sources. See *Compilation* section for more info.

## Compilation
### Windows (MSVC)
You will have to get (and compile dependencies). Then just use the provided solution (`.sln`) file.

 - [TagLib](https://taglib.org/)
 - [WinGetopt](https://github.com/alex85k/wingetopt)

Both use *CMake* build system.

Or you can download pre-compiled versions here [`id3-tags-cli-win32-deps.zip`](https://github.com/Zereges/id3-tag-cli/releases/download/v1.0/id3-tags-cli-win32-deps.zip) and extract them to root directory (MSVC is configured to look for headers and static lib files there).

### Linux (make)

To build `ID3TagCLI` you need:

* a C++17-compatible compiler, such as GCC or Clang
* GNU Make
* `pkg-config`
* TagLib development files

The Makefile uses `pkg-config` to obtain the compiler and linker options required by the installed TagLib library. You therefore normally do not need to manually configure TagLib include or library paths.

On current Debian releases, for example:

```bash
sudo apt install build-essential pkg-config libtag-dev
```

Some older Debian and Ubuntu releases provide the TagLib development files as:

```bash
sudo apt install libtag1-dev
```

Clone the repository and run:

```bash
make
```

The resulting executable is:

```text
./id3-tags-cli
```

## License
ID3TagCLI is distributed under GLP-3.0. See [LICENSE](https://github.com/Zereges/id3-tag-cli/blob/master/LICENSE) file for more information.
