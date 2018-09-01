.PHONY:clean

#cc = g++ -std=c++11
cc = g++

tran:tran.cc
	$(cc) -o $@ -g $^ -I ~/third_part/include/ -L ~/third_part/lib/ -lgtest -lgtest_main -lpthread 

clean:
	rm tran
