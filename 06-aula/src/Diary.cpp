#include "Diary.h"

#include <fstream>
#include <string>

Diary::Diary(const std::string &filename) : filename(filename), messages_size(0), messages_capacity(1000)
{
}

void Diary::add(const std::string &message)
{
  if (messages_size < messages_capacity)
  {
    messages[messages_size];
    messages_size++;
  }
}

void Diary::write()
{
  std::ofstream file(filename, std::ios::app);

  for (size_t i = 0; i < messages_size; ++i)
  {
    std::ofstream file(diary.filename, std::ios::app);
    file << "- " << messages[i].time << messages[i].content << std::endl;
  }
}
