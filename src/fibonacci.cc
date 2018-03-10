#include "fibonacci.h"
#include <cassert>

int Fibonacci1(int n) {
  assert(n >= 0);
  if (n == 0) {
    return 0;
  }

  int previous = 0;
  int last = 1;
  for (int i = 1; i < n; ++i) {
    int tmp = previous;
    previous = last;
    last = tmp + last;
  }
  return last;
}

int Fibonacci2(int n) {
  assert(n >= 0);
  if (n == 0) {
    return 0;
  }

  int previous = 0;
  int last = 1;
  for (int i = 1; i < n; ++i) {
    last += previous;
    previous = last - previous;
  }
  return last;
}

int Fibonacci3(int n) {
  assert(n >= 0);
  if (n < 2) {
    return n;
  }
  return Fibonacci3(n - 1) + Fibonacci3(n - 2);
}
