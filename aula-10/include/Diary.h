#if !defined(DIARY_H)
#define DIARY_H

#include "Message.h"
#include <string>

struct Diary
{
  Diary(const std::string& filename);
  ~Diary();

  std::string filename;
  //Quando um array e alocado dinamecamente ele é um ponteiro
  Message* messages;
  size_t messages_size;
  size_t messages_capacity;

  void add(const std::string& message);
  void add(const Message message);
  void write();
  int load_messages();
  void upgrade_messages_array();
  Message* search(const std::string& what);

};
#endif