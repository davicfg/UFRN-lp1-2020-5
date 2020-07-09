#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {
  string acceptedParameter = "add";
  if (argc == 2 && acceptedParameter == argv[1]) {
    string newMessage;
    std::cin >> newMessage;
    std::cout << newMessage << std::endl;
  } else if (argc == 3 && acceptedParameter == argv[1]) {
    string newMessage = argv[2];
    std::cout << newMessage << std::endl;
  } else {
    std::cout << "Use: " << argv[0] << " add '<message>' " << std::endl;
    return 1;
  }

  return 0;
}
