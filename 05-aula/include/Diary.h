#include <string>

struct Diary
{
  std::string filename;

  void add_message(const std::string &file_name, const std::string message);
  int list_messages(const std::string &file_name);
  bool find_today_title(const std::string &file_name);
  void add_today_title(const std::string &file_name);
};
