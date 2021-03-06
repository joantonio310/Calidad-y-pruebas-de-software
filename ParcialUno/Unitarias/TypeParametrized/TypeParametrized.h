#include "gtest/gtest.h"
#include "../TypedTest/Hierarchie.h"

class TypeParameterized : public testing::Test
{
public:
    TypeParameterized()
    {
        instance2Test = new instanceType;
    }
    ~TypeParameterized()
    { 
        delete instance2Test;
        instance2Test = NULL;
    }
protected:
    Base* instance2Test;
};

TYPED_TEST_CASE_P(TypeParameterized);

TYPED_TEST(TypeParameterized, simple)
{
    EXPECT_EQ(1, this->instance2Test->doSomething());
}

TYPED_TEST(TypeParameterized, advanced)
{
    EXPECT_EQ(1, this->instance2Test->doSomething());
}

REGISTER_TYPED_TEST_CASE_P(TypeParameterized, simple, advanced);