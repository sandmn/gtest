//测试文件

#include"abs.h"

TEST(TestCaseTrue,TestTrue)
{
    ASSERT_TRUE(Abs(10) == 10);
    //EXPECT_TRUE(Abs(10) == -10);
    //ASSERT_FALSE(Abs(10) == 10);
    //EXPECT_FALSE(Abs(10) == 10);
    std::cout<<"haha"<<std::endl;
}

//利用TEST宏进行测试
TEST(TestCaseEQ,TestEQ)
{
    //只要能实现== != > >= < <= 运算符运算的类型都可以运用以下宏进行比较
    ASSERT_EQ(Abs(10),10);
    ASSERT_EQ(Abs(-10),10);
    ASSERT_EQ(Abs(0),0);

    //不等于：ASSERT_NE
    //小于：ASSERT_LT
    //小于等于：ASSERT_LE
    //大于：ASSERT_GT
    //大于等于：ASSERT_GE
}

//C风格字符串的比较
TEST(TestCaseC,TestC)
{
    //ASSERT_STREQ  EXPECT_STREQ
    //ASSERT_STRNE  EXPECT_STRNE
    //ASSERT_STRCASEEQ  EXPECT_STRCASEEQ
    //ASSERT_STRCASENE  EXPECT_STRCASENE
    EXPECT_STREQ("bbb","bbb");
    EXPECT_STRNE("AAA","HHH");
    EXPECT_STRCASEEQ("aaa","AAA");
    EXPECT_STRCASENE("aaa","AAA");
    std::cout<<"haha"<<std::endl;
}
