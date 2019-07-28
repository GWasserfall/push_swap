from random import randint
from sys import argv

iter = 30
if len(argv) > 1:
	iter = int(argv[1])

def args(count):
	uni = set()

	while len(uni) < int(count):
		uni.add(randint(-100, 3000))

	return [str(x) for x in uni]

print " ".join(args(argv[1]))
