OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o Cjt_idiomas.o idioma.o TabFreq.o
	g++ -o program.exe program.o Cjt_idiomas.o idioma.o TabFreq.o $(OPCIONS)
	rm *.o

program.o: program.cc Cjt_idiomas.hh idioma.hh TabFreq.hh
	g++ -c program.cc $(OPCIONS)

Cjt_idiomas.o: Cjt_idiomas.cc Cjt_idiomas.hh
	g++ -c Cjt_idiomas.cc $(OPCIONS)

idioma.o: idioma.cc idioma.hh
	g++ -c idioma.cc $(OPCIONS)

TabFreq.o: TabFreq.cc TabFreq.hh
	g++ -c TabFreq.cc $(OPCIONS)



clean:
	rm *.o
	rm *.exe
	rm *.gch
	rm *.tar
	rm *.x

tar: program.cc Cjt_idiomas.cc Cjt_idiomas.hh idioma.cc idioma.hh TabFreq.cc TabFreq.hh html.zip
	tar -cvf practica.tar program.cc Cjt_idiomas.cc Cjt_idiomas.hh idioma.cc idioma.hh TabFreq.cc TabFreq.hh html.zip Makefile

doxygen: Doxyfile
	doxygen Doxyfile
