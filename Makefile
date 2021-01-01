all:
	g++ *.cpp -otest -g
clean:
	rm *.o | true
	rm test | true