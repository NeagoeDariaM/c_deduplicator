build:
	gcc main.c hash.c openfolder.c -o deduplicator
clean:
	rm -f deduplicator *.o
