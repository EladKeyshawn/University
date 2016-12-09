all: clean Mean run expected

Mean:
	gcc -o Mean MeanWindow.c MeanWindowMain.c

clean:
	rm Mean 2> /dev/null

run: 
	./Mean

expected:
	cat MeanWindow.out.1