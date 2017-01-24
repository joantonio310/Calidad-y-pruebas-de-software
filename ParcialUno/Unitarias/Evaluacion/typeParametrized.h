#include "gtest/gtest.h"
#include "Hierarchie.h"
#include "Ordenamiento.h"

template<class instanceType>
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
    Ordenamiento<int>* instance2Test;
};

TYPED_TEST_CASE_P(TypeParameterized);

TYPED_TEST_P(TypeParameterized, bubbleASC){
    
    int vec[] = {4, 3, 2, 1, 4, 10};
    this->instance2Test->burbuja(vec, 6, Ordenamiento<int>::asc);
    for(int i = 0; i < 5; i++){
        EXPECT_LE(vec[i], vec[i+1]);
    }
}

TYPED_TEST_P(TypeParameterized, bubbleDESC){
    
    int vec[] = {4, 3, 2, 1, 4, 10};
    this->instance2Test->burbuja(vec, 6, Ordenamiento<int>::desc);
    for(int i = 0; i < 5; i++){
        EXPECT_GE(vec[i], vec[i+1]);
    }
}

TYPED_TEST_P(TypeParameterized, insertASC){
    
    int vec[] = {4, 3, 2, 1, 4, 10};
    this->instance2Test->insercion(vec, 6, Ordenamiento<int>::asc);
    for(int i = 0; i < 5; i++){
        EXPECT_LE(vec[i], vec[i+1]);
    }
}

TYPED_TEST_P(TypeParameterized, insertDESC){
    
    int vec[] = {4, 3, 2, 1, 4, 10};
    this->instance2Test->insercion(vec, 6, Ordenamiento<int>::desc);
    for(int i = 0; i < 5; i++){
        EXPECT_GE(vec[i], vec[i+1]);
    }
}

TYPED_TEST_P(TypeParameterized, selectASC){
    
    int vec[] = {4, 3, 2, 1, 4, 10};
    this->instance2Test->seleccion(vec, 6, Ordenamiento<int>::asc);
    for(int i = 0; i < 5; i++){
        EXPECT_LE(vec[i], vec[i+1]);
    }
}

TYPED_TEST_P(TypeParameterized, selectDESC){
    
    int vec[] = {4, 3, 2, 1, 4, 10};
    this->instance2Test->seleccion(vec, 6, Ordenamiento<int>::desc);
    for(int i = 0; i < 5; i++){
        EXPECT_GE(vec[i], vec[i+1]);
    }
}

TYPED_TEST_P(TypeParameterized, quickASC){
    
    int vec[] = {4, 3, 2, 1, 4, 10};
    this->instance2Test->quicksort(vec, 0, 5, Ordenamiento<int>::asc);
    for(int i = 0; i < 5; i++){
        EXPECT_LE(vec[i], vec[i+1]);
    }
}

TYPED_TEST_P(TypeParameterized, quickDESC){
    
    int vec[] = {4, 3, 2, 1, 4, 10};
    this->instance2Test->quicksort(vec, 0, 5, Ordenamiento<int>::desc);
    for(int i = 0; i < 5; i++){
        EXPECT_GE(vec[i], vec[i+1]);
    }
}

TYPED_TEST_P(TypeParameterized, mergeASC){
    
    int vec[] = {4, 3, 2, 1, 4, 10};
    this->instance2Test->mergesort(vec, 0, 5, Ordenamiento<int>::asc, 5);
    for(int i = 0; i < 5; i++){
        EXPECT_LE(vec[i], vec[i+1]);
    }
}

TYPED_TEST_P(TypeParameterized, mergeDESC){
    
    int vec[] = {4, 3, 2, 1, 4, 10};
    this->instance2Test->mergesort(vec, 0, 5, Ordenamiento<int>::desc, 5);
    for(int i = 0; i < 5; i++){
        EXPECT_GE(vec[i], vec[i+1]);
    }
}

REGISTER_TYPED_TEST_CASE_P(TypeParameterized, bubbleASC, insertASC, selectASC, quickASC, mergeASC, bubbleDESC, insertDESC, selectDESC, quickDESC, mergeDESC);