#include"gtest/gtest.h"
#include "Hierarchie.h"
#include "Ordenamiento.h"

template<class instanceType>
class FixTyped : public testing::Test
{
public:
    FixTyped()
    {
        instance2Test = new instanceType;
    }
    ~FixTyped()
    {
        delete instance2Test;
        instance2Test = NULL;
    }
protected:
    Ordenamiento<int>* instance2Test;
};

// child 1 = burbuja, child 2 = insercion

typedef testing::Types<Ordenamiento<int> > implementations;

TYPED_TEST_CASE(FixTyped, implementations);

TYPED_TEST(FixTyped, bubble){
    
    int vec[] = {4, 3, 2, 1, 4, 10};
    this->instance2Test->burbuja(vec, 6, Ordenamiento<int>::asc);
    for(int i = 0; i < 5; i++){
        EXPECT_LE(vec[i], vec[i+1]);
    }
}

TYPED_TEST(FixTyped, insert){
    
    int vec[] = {4, 3, 2, 1, 4, 10};
    this->instance2Test->insercion(vec, 6, Ordenamiento<int>::asc);
    for(int i = 0; i < 5; i++){
        EXPECT_LE(vec[i], vec[i+1]);
    }
}

TYPED_TEST(FixTyped, select){
    
    int vec[] = {4, 3, 2, 1, 4, 10};
    this->instance2Test->seleccion(vec, 6, Ordenamiento<int>::asc);
    for(int i = 0; i < 5; i++){
        EXPECT_LE(vec[i], vec[i+1]);
    }
}

TYPED_TEST(FixTyped, quick){
    
    int vec[] = {4, 3, 2, 1, 4, 10};
    this->instance2Test->quicksort(vec, 0, 5, Ordenamiento<int>::asc);
    for(int i = 0; i < 5; i++){
        EXPECT_LE(vec[i], vec[i+1]);
    }
}

TYPED_TEST(FixTyped, merge){
    
    int vec[] = {4, 3, 2, 1, 4, 10};
    this->instance2Test->mergesort(vec, 0, 5, Ordenamiento<int>::asc, 5);
    for(int i = 0; i < 5; i++){
        EXPECT_LE(vec[i], vec[i+1]);
    }
}