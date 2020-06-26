#include "Diary.h"

#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char* argv[])
{
    Diary d("diary.md");

    d.add("msg 1");
    d.messages[0].date.set_from_string("22/06/2020");
    d.add("msg 2");
    d.messages[1].date.set_from_string("22/06/2020");
    d.add("msg 3");
    d.messages[2].date.set_from_string("22/06/2020");

    d.add("msg 4");
    d.messages[3].date.set_from_string("25/06/2020");
    d.add("msg 5");
    d.messages[4].date.set_from_string("25/06/2020");
    d.add("msg 6");
    d.messages[5].date.set_from_string("25/06/2020");

    d.add("msg 7");
    d.messages[6].date.set_from_string("26/06/2020");
    d.add("msg 8");
    d.messages[7].date.set_from_string("26/06/2020");
    d.add("msg 9");
    d.messages[8].date.set_from_string("26/06/2020");

    d.add("msg 10");
    d.messages[8].date.set_from_string("26/06/2020");
    d.add("msg 11");
    d.messages[8].date.set_from_string("26/06/2020");
    d.write();
    return 0;
}