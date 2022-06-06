#include "failure-function-install.h"

static testing::Environment* const backward_env =
    testing::AddGlobalTestEnvironment(new BackwardFailureEnvironment{});
