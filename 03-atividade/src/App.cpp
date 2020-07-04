#include "App.h"

#include <iostream>
#include <algorithm>
#include <string>

App::App(const std::string &filename, const Config config) : diary(filename, config)
{
}

int App::run(int argc, char const *argv[])
{
  //TODO: pensar em uma forma melhor de trabalhar com o nome do arquivo.
  diary.filename = diary.config.path;

  diary.load_messages();
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
  else if (input_action == "search")
  {
    if (argc == 2)
    {
      search();
    }
    else
    {
      search(argv[2]);
    }
  }
  else if (input_action == "list")
  {
    if (argc == 2)
    {
      list_messages();
    }
    else
    {
      list_messages(argv[2]);
    }
  }
  else if (input_action == "interactive")
  {
    interactive();
  }
  else
  {
    return show_help(argv[0]);
  }

  return 0;
}

int App::show_help(const std::string &main_name)
{
  std::cout << "Uso:" << std::endl;
  std::cout << "  " << main_name << " add <message>" << std::endl;
  std::cout << "  " << main_name << " list" << std::endl;
  return 1;
}

void App::add()
{
  std::string message;
  std::cout << "Enter your message:" << std::endl;
  std::getline(std::cin, message);

  add(message);
}

void App::add(const std::string &message)
{
  diary.add(message);
  diary.write();
}

int App::search()
{
  std::string term;
  std::cout << "Enter the term to search: " << std::endl;

  std::getline(std::cin, term);

  return search(term);
}

int App::search(const std::string &what)
{
  std::vector<Message *> found_messages = diary.search(what);

  if (found_messages.size() == 0)
  {
    std::cout << "Term '" << what << "' not found." << std::endl;
    return 1;
  }

  for (Message *message : found_messages)
  {
    std::cout << message->content << std::endl;
  }

  return 0;
}

void App::interactive()
{
  std::string option;

  do
  {
    std::cout << "Diário 1.0\n"
              << std::endl;
    std::cout << "Seleciona uma ação:\n"
              << std::endl;
    std::cout << "1) Listar mensagens" << std::endl;
    std::cout << "2) Adicionar nova mensagem\n"
              << std::endl;
    std::cout << "0) Finalizar" << std::endl;

    std::getline(std::cin, option);

    if (option == "1")
    {
      list_messages();
    }
    else if (option == "2")
    {
      add();
    }
    else if (option != "0")
    {
      std::cout << "##Opção inválida##" << std::endl;
    }
  } while (option != "0");
}

void App::list_messages()
{
  list_messages(diary.config.default_format);
}

void App::list_messages(const std::string &format)
{
  std::string formated_ms = format;
  for (Message ms : diary.messages)
  {
    size_t pos;
    while ((pos = formated_ms.find("%d")) != std::string::npos)
    {
      formated_ms.replace(pos, 2, ms.date.to_string());
    }

    while ((pos = formated_ms.find("%t")) != std::string::npos)
    {
      formated_ms.replace(pos, 2, ms.time.to_string());
    }

    while ((pos = formated_ms.find("%m")) != std::string::npos)
    {
      formated_ms.replace(pos, 2, ms.content);
    }

    std::cout << formated_ms << std::endl;

    formated_ms = format;
  }
}
