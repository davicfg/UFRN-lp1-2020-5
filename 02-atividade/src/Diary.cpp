#include "Diary.h"
#include "Util.h"

Diary::Diary(const std::string &name) : filename(name), messages(nullptr), messages_size(0), messages_capacity(10)
{
  messages = new Message[messages_capacity];
}

Diary::~Diary()
{
  delete[] messages;
}

void Diary::add(const std::string &message)
{
  if (messages_size >= messages_capacity)
  {
    return;
  }

  Message m;

  m.content = message;
  m.date.set_from_string(get_current_date());
  m.time.set_from_string(get_current_time());

  messages[messages_size] = m;
  messages_size++;
}

void Diary::write()
{
  std::string current_date = "";
  for (size_t i = 0; i < messages_size; i++)
  {
    Message message = messages[i];

    if (message.date.to_string() != current_date)
    {
      std::ofstream diary(filename, std::ios::app);
      diary << "# " << message.date.to_string() << std::endl;
    }

    std::ofstream diary(filename, std::ios::app);
    diary << "- " << message.time.to_string() << " " << message.content << std::endl;

    current_date = message.date.to_string();
  }
}