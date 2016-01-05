#include <iostream>
#include <string>
#include <cassert>

#include "ArrayList.h"

int main()
{
    ArrayList<std::string> list;

    list.add("asd");
    list.add("qwe");

    std::cout << "List size: " << list.size() << std::endl;

    for (int i = 0; i < list.size(); i++)
    {
        std::cout << list.get(i) << std::endl;
    }

    list.remove("asd");

    list.clear();
    std::cout << "List size: " << list.size() << std::endl;

    return 0;
}
