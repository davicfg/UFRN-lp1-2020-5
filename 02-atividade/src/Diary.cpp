#include "Diary.h"
#include "Util.h"

#include <iostream>
#include <sstream>
#include <string>

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

int Diary::load_messages()
{
  std::ifstream file;

  file.open(filename);

  if (!file.is_open())
  {
    return 0;
  }

  std::string file_line;

  int line_number = 0;

  std::string current_date = "";
  while (!file.eof())
  {
    ++line_number;
    std::getline(file, file_line);

    if (file_line.size() == 0)
    {
      continue;
    }

    if ((file_line.find("#") != std::string::npos))
    {
      std::stringstream stream(file_line);
      char discard;

      stream >> discard;
      stream >> discard;
      stream >> current_date;
    }
    else
    {
      Message m;
      m.date.set_from_string(current_date);

      std::stringstream stream(file_line);
      char discard;
      std::string time;

      stream >> discard;
      stream >> time;

      m.time.set_from_string(time);
      getline(stream, m.content);

      m.content = m.content.substr(1);
    }
  }

  file.close();
  return 0;
}