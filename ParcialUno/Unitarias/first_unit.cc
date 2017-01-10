#include"first.h"
#include"gtest/gtest.h"

TEST(factorial, positivos){
    ASSERT_EQ(1,1);
    ASSERT_EQ(120,factorial(5));
}

TEST(factorial, negativos){
    ASSERT_EQ(0,factorial(-5));
}

TEST(factorial, cero){
    ASSERT_EQ(1,factorial(0));
}
