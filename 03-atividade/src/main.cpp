#include "App.h"
#include "Config.h"

int main(int argc, char const *argv[])
{
  Config config("diary.config");
  App aplication("diary.md", config);

  aplication.run(argc, argv);
  return 0;
}
