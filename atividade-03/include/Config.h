#if !defined(CONIF_H)
#define CONIF_H

#include <string>
struct Config
{
  Config(const std::string& filename);
  
  std::string path;
  std::string default_format;
  std::string filename;

  int load_config();
  int create_default_file();
};

#endif // CONIF_H
