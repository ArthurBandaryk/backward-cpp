//#include "backward.hpp"
#include <iostream>

#include "glog/logging.h"

void baz() {
  CHECK_GE(1, 10);
}

void bar() {
  baz();
}

void foo() {
  bar();
}

void f(int i) {
  if (i >= 10) {
    throw("stop");
  } else {
    f(i + 1);
  }
}

int main(int argc, char** argv) {
  // backward::SignalHandling sh;
  // foo();
  try {
    f(0);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  return 0;
}