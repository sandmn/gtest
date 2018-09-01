.PHONY:all

#同时生成有源文件封装的库文件和测试文件的可执行程序
all:libabs.a abs_test

#生成库文件
libabs.a:abs.cc
	g++ -c $^ -o libabs.o  -I ~/third_part/include/ #-L ~/third_part/lib/ -lgtest -lgtest_main -lpthread
	ar -cs $@ libabs.o
#生成可执行程序
abs_test:abs_test.cc
	g++ -o $@ -g $^ -I ~/third_part/include/ -L ~/third_part/lib/ -lgtest -lgtest_main -lpthread -L. -labs

.PHONY:clean
clean:
	rm abs_test
