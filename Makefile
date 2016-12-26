
%: %.cpp
	g++ $^ -lglut -lGL -lGLU -o $@.o
	./$@.o
	rm $@.o

clean:
	rm -rf *.o
