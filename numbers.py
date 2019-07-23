from random import randint
from sys import argv

iter = 30
if len(argv) > 1:
	iter = int(argv[1])

def args(count):
	uni = set()

	while len(uni) < count:
		uni.add(randint(0, 200))

	uni.shuffle()
	return [str(x) for x in uni]

print " ".join(args(100))
