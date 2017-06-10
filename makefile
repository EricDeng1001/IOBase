obj=In.o terminput.o fileinput.o inputControll.o \
			 out.o termoutput.o fileoutput.o outputControll.o\
			 getch.o IOBase.o
CXXFLAGS+=-std=c++11
CXXFLAGS+=-g
drive: drive.cpp libIOBase.a
libIOBase.a: $(obj) IOBase.h
	ar -rcs libIOBase.a $(obj) 
IOBase.o:IOBase.h
In.o: In.h 
terminput.o:terminput.h
fileinput.o:fileinput.h
inputControll.o:inputControll.h
out.o: out.h
termoutput.o:termoutput.h
fileoutput.o:fileoutput.h
outputControll.o:outputControll.h
getch.o:getch.h
.PHONY:clean
clean: 
	rm  $(obj) drive libIOBase.a 



