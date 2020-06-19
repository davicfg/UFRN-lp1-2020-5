#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

void show_help(const std::string &program_name);
void add_message(const std::string &file_name, const std::string message);
int list_messages(const std::string &file_name);
bool find_today_title(const std::string &file_name);
void add_today_title(const std::string &file_name);
std::string format_current_date(const std::string &format);
std::string get_current_date();
std::string get_current_time();

int main(int argc, char const *argv[])
{
  std::string diary_file_name = "diary.md";

  add_today_title(diary_file_name);

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

  std::string new_message;

  if (argc == 2)
  {
    std::cout << "Informe a mensagem" << std::endl;
    std::getline(std::cin, new_message);

    add_message(diary_file_name, new_message);

    return 0;
  }
  else
  {
    new_message = argv[2];

    add_message(diary_file_name, new_message);

    return 0;
  }
}

void show_help(const std::string &program_name)
{
  std::cout << "Uso:" << std::endl;
  std::cout << "  " << program_name << " add <message>" << std::endl;
  std::cout << "  " << program_name << " list" << std::endl;
}

void add_message(const std::string &file_name, const std::string message)
{
  std::ofstream diary(file_name, std::ios::app);
  diary << "- " << get_current_time() << " " << message << std::endl;
  std::cout << "Messagem Adicionana" << std::endl;
}

int list_messages(const std::string &file_name)
{
  std::ifstream file;

  file.open(file_name);

  if (!file.is_open())
  {
    std::cerr << "Arquivo não existente ou sem permissão de leitura."
              << std::endl;
    return 1;
  }

  std::string message;

  int line_number = 0;

  while (!file.eof())
  {
    ++line_number;
    std::getline(file, message);

    if (message.size() == 0)
    {
      continue;
    }

    if ((message.find("#") == std::string::npos))
    {
      std::cout << message << std::endl;
    }
  }

  file.close();
  return 0;
}

bool find_today_title(const std::string &file_name)
{
  std::ifstream file;

  file.open(file_name);

  if (!file.is_open())
  {
    std::cerr << "Arquivo não existente ou sem permissão de leitura."
              << std::endl;
    exit(1);
  }

  std::string message;

  int line_number = 0;

  while (!file.eof())
  {
    ++line_number;
    std::getline(file, message);

    if (message.size() == 0)
    {
      continue;
    }

    if (message.find(get_current_date()) != std::string::npos)
    {
      return false;
    }
  }

  file.close();
  return true;
}

void add_today_title(const std::string &file_name)
{
  if (find_today_title(file_name) == 1)
  {
    std::ofstream diary(file_name, std::ios::app);
    diary << "# " << get_current_date() << std::endl;
  }
}

std::string format_current_date(const std::string &format)
{
  std::time_t time = std::time(nullptr);
  char result[1024];

  std::strftime(result, sizeof(result), format.c_str(), std::localtime(&time));

  return std::string(result);
}

std::string get_current_date() { return format_current_date("%d/%m/%Y"); }

std::string get_current_time() { return format_current_date("%H:%M:%S"); }