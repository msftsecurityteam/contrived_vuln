all: vuln.o
	gcc -o vuln vuln.o

vuln.o: vuln.c
	gcc -c vuln.c

clean:
	rm vuln vuln.o
