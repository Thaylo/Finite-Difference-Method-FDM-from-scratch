all:
	clang++ *.cpp -otest
clean:
	rm *.o | true
	rm test | true