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

    d.add("msg 11");
    d.add("ldasd");
    d.add("mssdsadg 11");
    d.add("msdasdasdg 11");
    d.add("msqweeg 11");
    d.add("ms213g 11");
    d.add("msqewe231g 11");
    d.add("ms123g 11");
    d.add("msg213 11");
    d.add("ms123g 11");
    d.add("ms123g 11");
    d.add("ms123g 11");
    d.add("msg123 11");
    d.add("msg123 11");
    d.add("ms213g 11");
    d.add("msggh 11");
    d.add("msqwesfgg 11");
    d.add("msfghg 11");

    d.write();
    std::cout << d.messages_capacity << std::endl;
    return 0;
}