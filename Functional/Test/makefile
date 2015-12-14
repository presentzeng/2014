src :=$(wildcard *.cc)
test:$(src)
	clear
	g++ -o $@ $(src) -std=c++0x
	clear
	./test
	rm test
