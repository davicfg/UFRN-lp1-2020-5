#include "Config.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

Config::Config(const std::string &name) : filename(name)
{
  load_config();
}
int Config::load_config()
{
  //Tentar abrir o arquivo se não chamar create_default_file()

  std::ifstream file;

  file.open(filename);

  if (!file.is_open())
  {
    return create_default_file();
    
  }

  std::string file_line;

  int line_number = 0;

  while (!file.eof())
  {
    ++line_number;
    std::getline(file, file_line);

    if (file_line.size() == 0)
    {
      continue;
    }

    std::size_t pos;
    if (file_line.find("path=") != std::string::npos)
    {
      pos = file_line.find("=");
      path = file_line.substr(pos+1);
    }
    else if (file_line.find("default_format=") != std::string::npos)
    {
      pos = file_line.find("=");
      default_format = file_line.substr(pos+1);
    }
  }

  file.close();
  return 0;
}

int Config::create_default_file()
{
  //TODO: talvez não seja a melhor forma de fazer isso!
  // std::ofstream ofs;
  // ofs.open(filename, std::ofstream::out | std::ofstream::trunc);
  // ofs.close();

  std::ofstream config_file(filename, std::ios::app);

  config_file << "path=diary.md"<< std::endl;
  config_file << "default_format=%d %t: %m" << std::endl;
  config_file.close();

  return 0;
}