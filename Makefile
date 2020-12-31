all:
	g++ *.cpp -otest
clean:
	rm *.o | true
	rm test | true