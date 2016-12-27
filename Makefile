
%: %.cpp
	rm -rf $@.o
	g++ $^ -o $@.o -lgraph
	./$@.o

clean:
	rm -rf *.o
