build:
	g++ main.cpp -o calcPi -fpermissive
	g++ most.cpp -o calcPiButMore -fpermissive
run:
	./calcPi 10000