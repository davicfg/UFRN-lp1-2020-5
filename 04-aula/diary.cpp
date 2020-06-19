#include <iostream>
#include <string>
#include <fstream>

void show_help(const std::string &programName);
void add_mesage(const std::string &file_name, const std::string mesage);
int list_messages(const std::string &file_name);

int main(int argc, char const *argv[])
{
  std::string diary_file_name = "diary.txt";

  if (argc == 1)
  {
    show_help(argv[0]);
    return 1;
  }

  std::string add_action = "add";
  std::string list_action = "list";

  std::string input_action = argv[1];

  if (input_action != add_action and input_action != list_action)
  {
    show_help(argv[0]);
    return 1;
  }

  if (argv[1] == list_action)
  {
    return list_messages(diary_file_name);
    
  }

  std::string newMessage;

  if (argc == 2)
  {
    std::cout << "Informe a mensagem" << std::endl;
    std::getline(std::cin, newMessage);

    add_mesage(diary_file_name, newMessage);

    return 0;
  }
  else
  {
    newMessage = argv[2];

    add_mesage(diary_file_name, newMessage);

    return 0;
  }
}

void show_help(const std::string &programName)
{
  std::cout << programName << " add <message>" << std::endl;
}

void add_mesage(const std::string &file_name, const std::string mesage)
{
  std::ofstream diary(file_name, std::ios::app);
  diary << mesage << std::endl;
  std::cout << "Messagem Adicionana" << std::endl;
}

int list_messages(const std::string &file_name){
  std::ifstream file;

  file.open(file_name);

  if (!file.is_open()) {
    std::cerr << "Arquivo não existente ou sem permissão de leitura."
              << std::endl;
    return 1;
  }

  std::string message;

  int line_number = 0;

  while (!file.eof()) {
    ++line_number;
    std::getline(file, message);

    if (message.size() == 0) {
      continue;
    }

    std::cout << message << std::endl;
  }

  file.close();
  return 0;
}