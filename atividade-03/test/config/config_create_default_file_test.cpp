#include "Config.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
int main(int argc, char const *argv[])
{
  Config config("diary.config");

  std::cout << config.filename << std::endl;
  std::cout << config.path << std::endl;
  std::cout << config.default_format << std::endl;
  return 0;
}
