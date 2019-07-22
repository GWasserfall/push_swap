from random import randint
from sys import argv

iter = 30
if len(argv) > 1:
	iter = int(argv[1])

print " ".join( [str(randint(0, 5000000)) for x in range(0, iter)] )
