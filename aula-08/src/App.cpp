#include "App.h"

#include <iostream>
#include <string>

App::App(const std::string &filename) : diary(filename)
{
}

int App::run(int argc, char const *argv[])
{
  if (argc == 1)
  {
    return show_help(argv[0]);
  }

  std::string input_action = argv[1];

  if (input_action == "add")
  {
    if (argc == 2)
    {
      add();
    }
    else
    {
      add(argv[2]);
    }
  }
  else if (input_action == "list")
  {
    list_messages();
  }
  else
  {
    return show_help(argv[0]);
  }

  return 0;
}

int App::show_help(const std::string &main_name)
{
  return 1;
}

void App::add()
{
    std::string message;
    std::cout << "Enter your message:" << std::endl;
    std::getline(std::cin, message);

    add(message);
}

void App::add(const std::string& message)
{
    diary.add(message);
    diary.write();
}

void App::list_messages()
{
    for (size_t i = 0; i < diary.messages_size; ++i) {
        const Message& message = diary.messages[i];
        std::cout << "-" << message.content << std::endl;
    }
}