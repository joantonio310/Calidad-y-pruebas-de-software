#include"gtest/gtest.h"
#include"Almacen.h"

class AlmacenFixture : public ::testing::Test{
public:
    void SetUp(){
        a->add(3,3);
    }
    void TearDown(){
        
    }
    void TestCaseSetUp(){
        a = new Almacen<int>(4);
    }
    void TestCaseTearDown(){
        delete a;
    }
    Almacen<int> *a = new Almacen<int>(10);
};

TEST_F(AlmacenFixture, Constructor){
    a->size();
}

/*TEST_F(AlmacenFixture, Constructor){
    a->empty();
}

TEST_F(AlmacenFixture, Constructor){
    a->deletePos(1);
}/*

