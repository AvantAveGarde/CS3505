LIBDIR = ../A2/Dependencies/libharu/src
LIBNAME = hpdfs
INCLUDE = ../A2/Dependencies/libharu/include

output: main.o haruPDF.o spiral.o
	g++ main.o haruPDF.o spiral.o -o testPage -I$(INCLUDE) -L$(LIBDIR) -l$(LIBNAME)

main.o: main.cpp
	g++ -c main.cpp -I$(INCLUDE) -L$(LIBDIR) -l$(LIBNAME)

haruPDF.o: haruPDF.cpp haruPDF.h
	g++ -c haruPDF.cpp -I$(INCLUDE) -L$(LIBDIR) -l$(LIBNAME)

spiral.o: spiral.cpp spiral.h
	g++ -c spiral.cpp

clean:
		rm *.o testPage
