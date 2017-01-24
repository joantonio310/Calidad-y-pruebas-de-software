#include "TypeParameterized.h"

typedef testing::Types<Child1, Child2> implementations;

INSTANTIATE_TYPED_TEST_CASE_P(MiPrueba, TypeParameterized, implementations);