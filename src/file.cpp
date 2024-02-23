#include "./file.hpp"
#include "./../external/whereami/src/whereami.h"
#include <cstdio>
#include <cstring>
#include <sys/_types/_size_t.h>

#ifdef __APPLE__
#include <__nullptr>
#endif

#include <stdio.h>

const char *get_application_path(int *dir_len) {
    int _len = wai_getExecutablePath(nullptr, 0, nullptr);
    char *_path = new char[_len + 1];
    wai_getExecutablePath(_path, _len, dir_len);
    _path[_len] = '\0';
    return _path;
}

const char *get_application_dir(const char *const path, int dir_len) {
    char *_dir = new char[dir_len + 1];
    for (int i = 0; i < dir_len; i++) {
        _dir[i] = path[i];
    }
    _dir[dir_len] = '\0';
    return _dir;
}

bool can_open_file(const char *const path) {
    FILE *_file = fopen(path, "r");
    if (_file == nullptr) {
        return false;
    }
    return true;
}

const char *to_windows_path(const char *const path) {
    char *_path = new char[sizeof(path)];
    strcpy(_path, path);

    size_t _len = strlen(_path);
    for (size_t i = 0; i < _len; i++) {
        if (_path[i] == '/') {
            _path[i] = '\\';
        }
    }

    return _path;
}