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
  upgrade_messages_array();

  Message m;

  m.content = message;
  m.date.set_from_string(get_current_date());
  m.time.set_from_string(get_current_time());

  messages[messages_size] = m;
  messages_size++;
}

void Diary::write()
{
  //TODO: talvez não seja a melhor forma de fazer isso!
  std::ofstream ofs;
  ofs.open(filename, std::ofstream::out | std::ofstream::trunc);
  ofs.close();

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
      add(m);
    }
  }

  file.close();
  return 0;
}

void Diary::add(const Message message)
{
  upgrade_messages_array();

  messages[messages_size] = message;
  messages_size++;
}

void Diary::upgrade_messages_array()
{
  if (messages_size >= messages_capacity)
  {
    //TODO: fazer um método privado em Diary para colocar esses passos lá
    messages_capacity *= 2;
    Message *new_messages = new Message[messages_capacity];

    for (size_t i = 0; i < messages_size; i++)
    {
      new_messages[i] = messages[i];
    }

    messages = new_messages;
  }
}

Message* Diary::search(const std::string& what)
{
  for (size_t i = 0; i < messages_size; i++)
  {
    std::size_t found = messages[i].content.find(what);
    if(found < std::string::npos){
      return &messages[i];
    }
  }
  return nullptr;
}