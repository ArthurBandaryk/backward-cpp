#include "glog/logging.h"
#include "gtest/gtest.h"

int f(int i) {
  if (i >= 10) {
    CHECK(false);
    return i;
  } else {
    return f(i + 1);
  }
}

TEST(StackTrace, CheckFail) {
  f(0);
  // CHECK(false);
}
