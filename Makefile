PROJECT=main

all:
	g++ -o $(PROJECT)  $(PROJECT).cpp -lxbee

clean-all:
	rm *.o
	
clean:
	rm *.o
