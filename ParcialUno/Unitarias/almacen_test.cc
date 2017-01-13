#include"gtest/gtest.h"
#include"Almacen.h"
#include"time.h"

class TimeFixture : public testing::Test{
public:
    virtual void SetUp(){
        tiempo = time(NULL);
    }
    virtual void TearDown(){
        
        EXPECT_TRUE((time(NULL) - tiempo) >= 1) << "Error: tardo demasiado";
    }
private:
    time_t tiempo;
};

class AlmacenFixture : public TimeFixture{
public:
    void SetUp(){
        //a->add(3,3);
        TimeFixture::SetUp();
    }
    void TearDown(){
        
    }
    static void SetUpTestCase(){
        a = new Almacen<int>(4);
    }
    static void TearDownTestCase(){
        delete a;
    }
    static Almacen<int> *a;
};

Almacen<int>* AlmacenFixture::a = 0;

TEST_F(AlmacenFixture, size){
    a->size();
}

TEST_F(AlmacenFixture, empty){
    a->empty();
}

TEST_F(AlmacenFixture, deletePos){
    for(int i = 0; i < 1000000000; i++){
        
    }
    a->deletePos(1);
}

