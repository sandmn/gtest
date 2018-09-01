.PHONY:clean

main:main.cc
	g++ -o $@ -g $^ -I ~/third_part/include/ -L ~/third_part/lib/ -lgtest -lgtest_main -lpthread

clean:
	rm main
