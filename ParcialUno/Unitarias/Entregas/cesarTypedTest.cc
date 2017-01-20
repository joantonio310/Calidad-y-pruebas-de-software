#include "Cifrado.h"
#include "Cesar.h"
#include "Vinegere.h"
#include "../gtest/gtest.h"

template <class T>
Cifrado *factoryMethod() {
    return new T;
}

template <class T>
class FixTyped : public testing::Test {

public:
    FixTyped() : inst(factoryMethod<T>()){}

protected:
    Cifrado *inst;
};

typedef testing::Types<Cesar, Vinegere> imple;

TYPED_TEST_CASE(FixTyped, imple);

TYPED_TEST(FixTyped, testName) {
    EXPECT_EQ("garden", this->inst->decrypt());
}