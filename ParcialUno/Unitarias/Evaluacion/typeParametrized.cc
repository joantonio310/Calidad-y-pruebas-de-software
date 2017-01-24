#include "typeParameterized.h"

typedef testing::Types<Ordenamiento<int> > implementations;

INSTANTIATE_TYPED_TEST_CASE_P(MiTest, TypeParameterized, implementations);