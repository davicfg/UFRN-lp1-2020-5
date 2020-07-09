#include <iostream>
#include <sstream>
#include <string>
#include "Diary.h"

int main(int argc, char const *argv[])
{
  std::cout << "SHOW" << std::endl;
  Diary d("diary.md");
  
  d.load_messages();

  for (size_t i = 0; i < d.messages_size; i++)
  {
    std::cout << d.messages[i].content << std::endl;
  }
  
  return 0;
}
