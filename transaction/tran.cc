#include"tran.h"

//事件机制：框架提供一些特定的时机，可以在这些时机执行自定义的代码
//这里的框架是指gtest框架，此处需要借助类对象将自定制的逻辑代码注册进框架，然后框架在合适的时机调用执行这段逻辑
//这里有三个时机：
//TEST级别(在每个TEST的开始和结束时会自动执行初始化和清理函数)，
//TESTCASE级别（在每个TESTCASE的开始和结束会自动执行初始化和清理）
//GROBAL级别（全局的开始和结束会自动执行初始化和清理）

//创建子类对父类中的初始化和清理函数进行重写
//TEST级别
class MyTest:public testing::Test
{
    public:
    //TEST级别
    //初始化
    void SetUp()
    {
        std::cout<<"SetUp"<<std::endl;
        m.insert(std::pair<int,int>(1,1));
        m.insert(std::make_pair(2,1));
        m.insert(std::make_pair(3,1));
        m.insert(std::make_pair(4,1));
    }
    //清理
    void TearDown()
    {
        m.clear();
        std::cout<<"TearDown"<<std::endl;
    }
    //TESTCASE级别
    //初始化函数
    static void SetUpTestCase()
    {
        std::cout<<"SetUpTestCase"<<std::endl;
    }
    //清理函数
    static void TearDownTestCase()
    {
        std::cout<<"TearDownTestCase"<<std::endl;
    }
    std::map<int,int> m;
};

//注意如果使用TEST和TESTCASE级别的事件机制，此处使用的宏应该为TEST_F
//TEST_F宏会自动创建第一个参数表示的类对象，并将该类对象注册进框架中
//框架会在合适的实际调用初始化和清理函数
//注意：第一个参数要与类名相同
TEST_F(MyTest,TestSize)
{
    ASSERT_EQ(m.size(),4);
}
TEST_F(MyTest,TestFind)
{
    std::map<int,int>::iterator it = m.find(2);
    ASSERT_NE(it,m.end());
}

//全局事件机制：
//全局事件要自己创建类对象，手动将类对象注册进框架中。以上两种事件机制都有对应的宏去实现

//构造全局类
class GlobalTest:public testing::Environment
{
    public:
        //初始化函数
        void SetUp()
        {
            std::cout<<"Grobal SetUp"<<std::endl;
        }
        //清理函数
        void TearDown()
        {
            std::cout<<"Grobal TearDown"<<std::endl;
        }
};
//创建全局类对象并将其注册进框架中
int main(int argc,char* argv[])
{
    //初始化
    testing::InitGoogleTest(&argc,argv);
    //创建子类对象并由父类指针指向
    testing::Environment* env = new GlobalTest;
    //将对象注册进框架中
    testing::AddGlobalTestEnvironment(env);
    return RUN_ALL_TESTS();
}
//int main(int argc,char* argv[])
//{
//    //初始化
//    testing::InitGoogleTest(&argc,argv);
//    //创建全局的子类对象，用父类指针指向
//    testing::Environment* env = new GlobalTest();
//    //将类对象注册进框架中
//    testing::AddGlobalTestEnvironment(env);
//    return RUN_ALL_TESTS();
//}



//不使用事件机制
//void MakeMap(std::map<int,int>& m)
//{
//    m.insert(std::pair<int,int>(1,1));
//    m.insert(std::make_pair(2,1));
//    m.insert(std::make_pair(3,1));
//    m.insert(std::make_pair(4,1));
//}
//
//
////此处的TEST_F宏在执行时会自动创建一个子类对象并将其注册进框架中
////框架会在何时的时机调用
//TEST(TestMapSize,TestSize)
//{
//    //map中的元素类型是一个结构体pair的对象
//    //结构体pair为：std::pair<T1,T2>,所以构造一个pair类型的结构体应为：std::pair<T1,T2>(x1,x2)
//    //构建结构体pair类型的对象的函数为：std::make_pair(x1,x2)
//    //创建一个map
//    std::map<int,int> m;
//    MakeMap(m);
//    //ASSERT_TRUE(m.size() == 4) << "m.size" << m.size();
//
//    ASSERT_EQ(m.size(),4);
//}
//
//TEST(TestMapFind,TestFind)
//{
//    std::map<int,int> m;
//    MakeMap(m);
//
//    //在map中查找某个元素。返回该元素所在的位置迭代器
//    std::map<int,int>::iterator it = m.find(6);
//    //auto = m.find(6);//auto中自动识别对象的类型
//    ASSERT_EQ(it,m.end());
//}
//
//TEST(TestMapSqual,TestSqual)
//{
//    std::map<int,int> m;
//    MakeMap(m);
//
//    EXPECT_EQ(m[2],1);
//}
