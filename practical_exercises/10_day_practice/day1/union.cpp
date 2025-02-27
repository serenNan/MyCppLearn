/* 联合体学习.cpp */
#include <cstdio>
#include <iostream>

using namespace std;
using namespace std;
// union 使用相同的内存地址
union myun {
  struct {
    int x;
    int y;
    int z;
  } u;
  int k;
  int f;
} a;
int main() {
  a.u.x = 4;
  a.u.y = 5;
  a.u.z = 6;
  a.k = 0; // 覆盖掉第一个int空间值
  a.f = 1;
  printf("%d %d %d %d %d\n", a.u.x, a.u.y, a.u.z, a.k, a.k);
  cout << &a.u.x << endl;
  cout << &a.u.y << endl;
  cout << &a.u.z << endl;
  cout << &a.u << endl;

  return 0;
}