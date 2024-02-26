#include "./file.hpp"
#include "./../external/whereami/src/whereami.h"
#include <cstdio>
#include <cstring>
#include <string.h>
#include <string>

#ifdef __APPLE__
#include <__nullptr>
#endif

#include <stdio.h>

const std::string get_application_path(int *dir_len) {
    int _len = wai_getExecutablePath(nullptr, 0, nullptr);
    char *_path = new char[_len + 1];
    wai_getExecutablePath(_path, _len, dir_len);
    _path[_len] = '\0';
    return {_path};
}

const std::string get_application_dir(const std::string &path, int dir_len) {
    return path.substr(0, dir_len);
}

bool can_open_file(const std::string &path) {
#ifdef _WIN32
    std::string _path = to_windows_path(path);
    FILE *_file;
    fopen_s(&_file, _path.c_str(), "r");
#else
    std::string _path = path;
    FILE *_file = fopen(_path.c_str(), "r");
#endif

    if (_file == nullptr) {
        return false;
    }
    return true;
}

const std::string to_windows_path(const std::string &path) {
    std::string _path = path;

    for (size_t i = 0; i < _path.length(); i++) {
        if (_path[i] == '/') {
            _path[i] = '\\';
        }
    }

    return _path;
}