#include "gtest/gtest.h"
#include "desCesar.hpp"
#include <vector>

template<class instanceType>
class FixTyped : public testing::Test
{
public:
  FixTyped()
  {
    instance2Test = new instanceType;
  }
  virtual ~FixTyped()
  {
    delete instance2Test;
    instance2Test = NULL;
  }
protected:
  desCesar* instance2Test;
};

typedef testing::Types<desCesar> implementations;

TYPED_TEST_CASE(FixTyped, implementations);


TYPED_TEST(FixTyped, testName)
{
  std::vector<std::string> x;
  x.push_back("DONE");
  x.push_back("GARDEN");
  x.push_back("FKDAFD");
  EXPECT_EQ("GARDEN",this->instance2Test->descypher("RLCOPY",x));
}