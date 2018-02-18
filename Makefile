CC     = clang
CFLAGS = -W -Wall

dnslookup: dnslookup.c
	$(CC) $(CFLAGS) dnslookup.c -o dnslookup

clean:
	rm -f dnslookup
