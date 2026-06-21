#include <iostream>
#include <boost/filesystem.hpp>
#include <memory>

int main()
{
    std::cout << "Hello Third Party Include!" << std::endl;

    // use a shared ptr
    auto value = std::make_shared<int>(4);
    std::cout << "value=" << *value << std::endl;

    // trivial use of boost filesystem
    boost::filesystem::path path = "/usr/share/cmake/modules";
    if(path.is_relative())
    {
        std::cout << "Path is relative" << std::endl;
    }
    else
    {
        std::cout << "Path is not relative" << std::endl;
    }

   return 0;
}
