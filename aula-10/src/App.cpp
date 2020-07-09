#include "App.h"

#include <iostream>
#include <string>

App::App(const std::string &filename) : diary(filename)
{
}

int App::run(int argc, char const *argv[])
{
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
  }else if(input_action == "search"){
    if(argc == 2){
      search();
    }else{
      search(argv[2]);
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

void App::list_messages()
{
  for (size_t i = 0; i < diary.messages_size; ++i)
  {
    const Message &message = diary.messages[i];
    std::cout << "- " << message.content << std::endl;
  }
}

void App::search(){
  std::string term;
  std::cout << "Enter the term to search: " << std::endl;

   std::getline(std::cin, term);

   search(term);
}

void App::search(const std::string& what){
  Message* found = diary.search(what);

  if(found == nullptr){
    std::cout << "Message not found" << std::endl;
  }
  std::cout << found->content << std::endl;
  
}
