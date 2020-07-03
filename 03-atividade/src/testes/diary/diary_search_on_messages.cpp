#include <iostream>

#include "Diary.h"

int main(int argc, char const *argv[])
{
  Diary d("diary.md");
  
  d.load_messages();
  d.add("Davi show 1");
  d.add("bla");

  Message* found = d.search("bla");

  std::cout << found->content << std::endl;
  d.write();


  return 0;
}
