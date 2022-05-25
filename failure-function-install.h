#include "backward.hpp"
//#include "boost/stacktrace.hpp"
#include "glog/logging.h"
#include "gtest/gtest.h"

class BackwardFailureEnvironment : public ::testing::Environment {
 public:
  ~BackwardFailureEnvironment() override {}

  void SetUp() override {
    google::InstallFailureFunction([]() {
      using namespace backward;
      StackTrace st;
      st.load_here();
      Printer p;
      p.object = true;
      p.color_mode = ColorMode::always;
      p.address = true;
      p.print(st);

      // StackTrace st;
      // st.load_here();

      // TraceResolver tr;
      // tr.load_stacktrace(st);
      // for (size_t i = 0; i < st.size(); ++i) {
      //   ResolvedTrace trace = tr.resolve(st[i]);
      //   std::cerr << "#" << i
      //             << " " << trace.object_filename
      //             << " " << trace.object_function
      //             << " " << trace.source.line
      //             << " " << trace.source.col
      //             << " [" << trace.addr << "]"
      //             << std::endl;
      // }

      // std::cerr << boost::stacktrace::stacktrace();
      std::exit(EXIT_FAILURE);
    });
  }

  void TearDown() override {}
};
