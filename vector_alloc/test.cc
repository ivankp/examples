#include <iostream>
#include <vector>

using namespace std;

void test(const vector<int>& v) {
  cout << v.size() << '\t' << v.capacity() << endl;
}

int main()
{
  vector<int> v;
  v.reserve(3);
  test(v);

  for (int i=0;i<25;++i) {
    v.push_back(i);
    test(v);
  }

  return 0;
}
