#if !defined(DIARY_H)
#define DIARY_H

#include "Message.h"
#include <string>

struct Diary
{
  Diary(const std::string& filename);

  std::string filename;
  //Quando um array e alocado dinamecamente ele é um ponteiro
  Message* messages;
  size_t messages_size;
  size_t messages_capacity;

  
  void add(const std::string& message);
  void write();
};
#endif