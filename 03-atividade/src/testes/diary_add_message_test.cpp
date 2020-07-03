#include "Diary.h"

#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char* argv[])
{
    Diary d("diary.md");

    d.add("msg 1");
    d.messages[0].date.set_from_string("25/06/2020");
    d.add("msg 2");
    d.messages[1].date.set_from_string("25/06/2020");
    d.add("msg 3");
    d.messages[2].date.set_from_string("25/06/2020");

    d.add("msg 4");
    d.add("msg 5");
    d.add("msg 6");
    d.write();
    return 0;
}