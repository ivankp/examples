#include <iostream>
#include <vector>

#define test(var) \
  std::cout <<"\033[36m"<< #var <<"\033[0m"<< " = " << var << std::endl;

class blank { };
class blank2 { blank a, b; };

int main()
{
  test(sizeof(bool))
  test(sizeof(char))
  test(sizeof(short))
  test(sizeof(int))
  test(sizeof(unsigned))
  test(sizeof(long))
  test(sizeof(long long))
  test(sizeof(size_t))

  std::cout << std::endl;

  test(sizeof(float))
  test(sizeof(double))
  test(sizeof(long double))

  std::cout << std::endl;

  std::cout << "Largest float incrementable by 1 is: ";
  float x = 0;
  while (x != x+1) x += 1;
  std::cout << x << std::endl;

  std::cout << std::endl;

  test(sizeof(std::vector<int>::size_type))
  test(sizeof(std::vector<int>::iterator))

  std::cout << std::endl;

  std::cout << "class blank { };" << std::endl;
  test(sizeof(blank))
  test(sizeof(std::pair<blank,char>))
  test(sizeof(std::pair<blank,blank>))

  std::cout << "\nclass blank2 { blank a, b; };" << std::endl;
  test(sizeof(blank2))

  std::cout << std::endl;
}
