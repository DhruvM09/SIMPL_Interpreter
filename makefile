CC := g++
all :
	${CC} *.cpp -Iinclude -o simpl.exe

clean :
	rm -f *.exe
