#include "Diary.h"

int main(int argc, char const *argv[])
{
  Diary d("diary.md");
  
  d.load_messages();

  return 0;
}
