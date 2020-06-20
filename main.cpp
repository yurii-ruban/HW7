#include "xstring.h"
#include <utility>

int main(int argc, char** argv)
{
  /* Test constructors */
  std::cout << "Test constructors (char*, std::string, copy, move): " << std::endl;
  custom::xstring hello("Hello");
  custom::xstring world(std::string(" world!"));
  custom::xstring copy(hello);
  custom::xstring thief(std::move(world));
  std::cout << copy << thief << world << std::endl;
  std::cout << std::endl;

  return 0;
}
