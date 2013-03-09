stack: main.o stampbuf.o stampstream.o stamp.o
	g++ -Wall -g -o stamping main.o stampbuf.o stampstream.o stamp.o  

stampstream.o: stampstream.cpp 
	g++ -Wall -g -c stampstream.cpp 

stampbuf.o: stampbuf.cpp 
	g++ -Wall -g -c stampbuf.cpp

stamp.o: stamp.cpp 
	g++ -Wall -g -c stamp.cpp

clean:
	rm -f stamping main.o stamp.o stampbuf.o stampstream.o *~