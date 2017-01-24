#include "gtest/gtest.h"
#include "Ordenamiento.h"


typedef Ordenamiento<int> * factoryMethod();

Ordenamiento<int> * instance1()
{
    return new Ordenamiento<int>();
}


class Fixture : public testing::TestWithParam<factoryMethod*>
{
protected:
    Ordenamiento<int> * instance2Test;
public:
    void SetUp()
    {
        instance2Test = (*GetParam())();
    }
    
    void TearDown()
    {
        delete instance2Test;
        instance2Test = NULL;
    }
};

TEST_P(Fixture, bubbleASC){
    
    int vec[] = {4, 3, 2, 1, 4, 10};
    this->instance2Test->burbuja(vec, 6, Ordenamiento<int>::asc);
    for(int i = 0; i < 5; i++){
        EXPECT_LE(vec[i], vec[i+1]);
    }
}

TEST_P(Fixture, bubbleDESC){
    
    int vec[] = {4, 3, 2, 1, 4, 10};
    this->instance2Test->burbuja(vec, 6, Ordenamiento<int>::desc);
    for(int i = 0; i < 5; i++){
        EXPECT_GE(vec[i], vec[i+1]);
    }
}

TEST_P(Fixture, insertASC){
    
    int vec[] = {4, 3, 2, 1, 4, 10};
    this->instance2Test->insercion(vec, 6, Ordenamiento<int>::asc);
    for(int i = 0; i < 5; i++){
        EXPECT_LE(vec[i], vec[i+1]);
    }
}

TEST_P(Fixture, insertDESC){
    
    int vec[] = {4, 3, 2, 1, 4, 10};
    this->instance2Test->insercion(vec, 6, Ordenamiento<int>::desc);
    for(int i = 0; i < 5; i++){
        EXPECT_GE(vec[i], vec[i+1]);
    }
}

TEST_P(Fixture, selectASC){
    
    int vec[] = {4, 3, 2, 1, 4, 10};
    this->instance2Test->seleccion(vec, 6, Ordenamiento<int>::asc);
    for(int i = 0; i < 5; i++){
        EXPECT_LE(vec[i], vec[i+1]);
    }
}

TEST_P(Fixture, selectDESC){
    
    int vec[] = {4, 3, 2, 1, 4, 10};
    this->instance2Test->seleccion(vec, 6, Ordenamiento<int>::desc);
    for(int i = 0; i < 5; i++){
        EXPECT_GE(vec[i], vec[i+1]);
    }
}

TEST_P(Fixture, quickASC){
    
    int vec[] = {4, 3, 2, 1, 4, 10};
    this->instance2Test->quicksort(vec, 0, 5, Ordenamiento<int>::asc);
    for(int i = 0; i < 5; i++){
        EXPECT_LE(vec[i], vec[i+1]);
    }
}

TEST_P(Fixture, quickDESC){
    
    int vec[] = {4, 3, 2, 1, 4, 10};
    this->instance2Test->quicksort(vec, 0, 5, Ordenamiento<int>::desc);
    for(int i = 0; i < 5; i++){
        EXPECT_GE(vec[i], vec[i+1]);
    }
}

TEST_P(Fixture, mergeASC){
    
    int vec[] = {4, 3, 2, 1, 4, 10};
    this->instance2Test->mergesort(vec, 0, 5, Ordenamiento<int>::asc, 5);
    for(int i = 0; i < 5; i++){
        EXPECT_LE(vec[i], vec[i+1]);
    }
}

TEST_P(Fixture, mergeDESC){
    
    int vec[] = {4, 3, 2, 1, 4, 10};
    this->instance2Test->mergesort(vec, 0, 5, Ordenamiento<int>::desc, 5);
    for(int i = 0; i < 5; i++){
        EXPECT_GE(vec[i], vec[i+1]);
    }
}

INSTANTIATE_TEST_CASE_P(CaseName, Fixture, testing::Values(&instance1));