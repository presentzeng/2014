all:ser cli
.PHONY:all
ser:server.c tcp.c
	clear
	gcc -o $@ $^
cli:client.c tcp.c
	clear
	gcc -o $@ $^
.PHONY:clean
clean:
	rm -rf ser cli
