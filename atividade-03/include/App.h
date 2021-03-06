#if !defined(APP_H)
#define APP_H

#include "Diary.h"

#include <string>

struct App
{
  Diary diary;

  App(const std::string& filename, const Config config);

  int run(int argc, char const *argv[]);
  int show_help(const std::string& main_name);
  void add();
  void add(const std::string & message);
  void list_messages();
  void list_messages(const std::string& format);
  int search();
  int search(const std::string& what);
  void interactive();
  
};

#endif
