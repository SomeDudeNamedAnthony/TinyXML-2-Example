#ifndef TX2E_FILE
#define TX2E_FILE

extern bool can_open_file(const char *const path);
extern const char *to_windows_path(const char *const path);
extern const char *get_application_path(int *dir_len);
extern const char *get_application_dir(const char *const path, int dir_len);

#endif // TX2E_FILE
