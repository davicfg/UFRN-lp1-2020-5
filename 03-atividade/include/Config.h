#if !defined(CONIF_H)
#define CONIF_H

#include <string>
struct Config
{
  std::string path;
  std::string default_format;
  std::string filename="diary.config";

  Config(const std::string& filename);
  void load_config();
  void create_default_file();
};

#endif // CONIF_H
