#include"main.h"
//TEST宏中可以写正常的c++代码，代码执行正确就表示通过
//以下为测试代码
TEST(TestCaseHello,TestHello)
{
    //TEST宏中可以写正常的c++代码
    std::cout<<"hello world"<<std::endl;
}

TEST(TestCaseHello,TestHaha)
{
    std::cout<<"haha"<<std::endl;
}


