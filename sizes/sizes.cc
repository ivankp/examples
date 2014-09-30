#include <iostream>
#include <vector>

using namespace std;

#define test(var) \
  cout <<"\033[36m"<< #var <<"\033[0m"<< " = " << var << endl;

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

  cout << endl;

  test(sizeof(float))
  test(sizeof(double))
  test(sizeof(long double))

  cout << endl;

  test(sizeof(vector<int>::size_type))
  test(sizeof(vector<int>::iterator))

  cout << endl;

  int i=5;
  cout << "int i=5;" << endl;
  test(i)
  test(i--)
  test((i = 5))
  test(--i)
}
