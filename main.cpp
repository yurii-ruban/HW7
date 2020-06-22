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

  std::cout << "Test inserts (char, char*, std::string, xstring): " << std::endl;
  hello.insert(',', 5);
  hello.insert(" beautiful", 10);
  hello.insert(std::string("-"), hello.length());
  hello.insert(custom::xstring("beautiful"), hello.length());
  std::cout << hello << thief << std::endl;
  std::cout << std::endl;

  std::cout << "Test appends (char, char*, std::string, xstring): " << std::endl;
  custom::xstring origin;
  origin.append('I');
  origin.append(" am");
  origin.append(std::string(" The"));
  origin.append(custom::xstring(" Matrix"));
  std::cout << origin << std::endl;
  std::cout << std::endl;

  std::cout << "Test contains (char, char*, std::string, xstring): " << std::endl;
  std::cout << "[I : " << origin.contains('I') << "], "
            << "[am : " << origin.contains("am") << "], "
            << "[The : " << origin.contains(std::string("The")) << "], "
            << "[Matrix : " << origin.contains(custom::xstring("Matrix")) << "]\n";
  std::cout << std::endl;

  std::cout << "Test remove (char, char*, xstring, std::string): " << std::endl;
  origin.remove('I', 0);
  origin.remove(" am", 0);
  origin.remove(custom::xstring(" Matrix"), 4);
  origin.remove(std::string(" The"), 0);
  std::cout << origin << std::endl;
  std::cout << std::endl;

  std::cout << "Test reverse, toStdString: " << std::endl;
  hello = hello.reverse();
  std::string stdHello = hello.toStdString();
  std::cout << stdHello << std::endl;
  std::cout << std::endl;

  std::cout << "Equal operators: " << std::endl;
  std::cout << (hello == hello) << " "
            << (hello == stdHello) << " "
            << (hello == "randomstring") << std::endl;
  std::cout << std::endl;

  std::cout << "Plus operators: " << std::endl;
  hello = "Final";
  std::cout << (hello + hello) << " "
            << (hello + stdHello) << " "
            << (hello + " randomstring") << " "
            << (hello + '!') << std::endl;
  std::cout << std::endl;


  return 0;
}
