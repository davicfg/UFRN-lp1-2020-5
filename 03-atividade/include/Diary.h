#if !defined(DIARY_H)
#define DIARY_H

#include "Message.h"
#include "Config.h"
#include <string>
#include <vector>
struct Diary
{
  Diary(const std::string& filename, const Config config);
  ~Diary();

  std::string filename;
  std::vector<Message> messages;
  Config config;

  void add(const std::string& message);
  void add(const Message message);
  void write();
  int load_messages();
  std::vector<Message*> search(const std::string& what);

};
#endif