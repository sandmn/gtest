#include<iostream>
#include<gtest/gtest.h>

void fun()
{
    int* p = NULL;
    //*p = 10;
}

TEST(TestDeath,TestFun)
{
    ASSERT_DEATH(fun(),"");
}
