all:ser cli
.PHONY:all
src1:=ser.c
src2:=cli.c
ser:$(src1)
	gcc -g -o $@  $(src1) -lpthread  -lsercli -I /myinclude/
cli:$(src2)
	gcc -g -o $@  $(src2) -lpthread  -lsercli -I /myinclude/

