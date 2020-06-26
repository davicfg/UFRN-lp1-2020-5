#include "Diary.h"

#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char* argv[])
{
    Diary d("diary.md");
    
    d.write();
    return 0;
}