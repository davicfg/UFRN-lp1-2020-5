
#ifndef W5NAULA05_DATE_H
#define W5NAULA05_DATE_H

#include <string>

struct Date
{
  //Talvez essa funções devam ser static
  std::string format_current_date(const std::string &format);
  std::string get_current_date();
  std::string get_current_time();
};

#endif