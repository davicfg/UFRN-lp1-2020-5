#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void show_help(const string &programName);
void add_mesage(const string &file);

int main(int argc, char const *argv[]) {

  if(argc == 1){
    show_help(argv[0]);
    return 1;
  }


  string acceptedParameter = "add";
  string inputAction = argv[1];

  if(acceptedParameter != inputAction){
    show_help(argv[0]);
    return 1;
  }


  string newMessage;

  if(argc == 2){
    cout << "Informe a mensagem" << endl;
    std:getline(cin, newMessage);
  }else{
    newMessage = argv[2];
  }

  ofstream diary("diary", ios::app);
  diary << newMessage << endl;
  cout << "Messagem Adicionana" << endl;
}

void show_help(const string &programName){
  cout << programName << " add <message>" << endl;
}

