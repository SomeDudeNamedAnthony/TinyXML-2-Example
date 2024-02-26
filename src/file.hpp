#ifndef TX2E_FILE
#define TX2E_FILE

#include <string>

extern bool can_open_file(const std::string &path);
extern const std::string to_windows_path(const std::string &path);
extern const std::string get_application_path(int *dir_len);
extern const std::string get_application_dir(const std::string &path,
                                             int dir_len);

#ifdef _WIN32
#define PATH_SEP '\\'
#else
#define PATH_SEP '/'
#endif

#endif // TX2E_FILE
