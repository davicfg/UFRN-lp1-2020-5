#include "Diary.h"
#include "Util.h"

#include <iostream>
#include <sstream>
#include <string>

Diary::Diary(const std::string &name) : filename(name)
{
}

Diary::~Diary()
{
}

void Diary::add(const std::string &message)
{
  Message m;

  m.content = message;
  m.date.set_from_string(get_current_date());
  m.time.set_from_string(get_current_time());

  messages.push_back(m);
}

void Diary::write()
{
  //TODO: talvez não seja a melhor forma de fazer isso!
  std::ofstream ofs;
  ofs.open(filename, std::ofstream::out | std::ofstream::trunc);
  ofs.close();

  std::string current_date = "";

  for (Message ms : messages)
  {

    if (ms.date.to_string() != current_date)
    {
      std::ofstream diary(filename, std::ios::app);
      diary << "# " << ms.date.to_string() << std::endl;
    }

    std::ofstream diary(filename, std::ios::app);
    diary << "- " << ms.time.to_string() << " " << ms.content << std::endl;

    current_date = ms.date.to_string();
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
  messages.push_back(message);
}

// void Diary::upgrade_messages_array()
// {
//   if (messages_size >= messages_capacity)
//   {
//     //TODO: fazer um método privado em Diary para colocar esses passos lá
//     messages_capacity *= 2;
//     Message *new_messages = new Message[messages_capacity];

//     for (size_t i = 0; i < messages_size; i++)
//     {
//       new_messages[i] = messages[i];
//     }

//     messages = new_messages;
//   }
// }

Message *Diary::search(const std::string &what)
{
  for (auto it = messages.begin(); it != messages.end(); it++)
  {
    std::size_t found = (*it).content.find(what);
    if (found != std::string::npos)
    {
      std::cout << "Diary::search: "<< &(*it) << std::endl;
      return &(*it);
    }
  }
  
  // for (Message ms : messages)
  // {
  //   std::size_t found = ms.content.find(what);
  //   if (found != std::string::npos)
  //   {
  //     std::cout << "Diary::search: " << &ms << std::endl;
  //     return &ms;
  //   }
  // }

  return nullptr;
}