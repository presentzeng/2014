all:ser cli
.PHONY:all
ser:server.c
	clear
	gcc -o $@ $<
cli:client.c
	clear
	gcc -o $@ $<
.PHONY:clean
clean:
	rm -rf ser cli
