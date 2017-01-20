#include "class.h"
#include "../gtest/gtest.h"

template <class T>
Base * factoryMethod()
{
    return new T;
}

template <class T>
class TypedFixture : public testing::Test
{
protected:
    Base * instance2Test;
public:
    TypedFixture() : instance2Test(factoryMethod<T>()) {}
    ~TypedFixture()
    {
        delete instance2Test;
        instance2Test = NULL;
    }
};

typedef testing::Types<Cesar> implementations;

TYPED_TEST_CASE(TypedFixture, implementations);

TYPED_TEST(TypedFixture, pruebaCesar)
{
    EXPECT_NE("not found!", this->instance2Test->decrypt("RLCOPY"));
}