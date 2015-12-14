src := $(wildcard *.cc)
test:$(src)
	clear
	g++ -o $@ $^ -lpthread
	clear
	./test
	rm test
