from random import randint, shuffle
from sys import argv

# nums = """40 -23 45 16 69 -19 -2 24 72 -38 5 21 43 -60 -53 99 -93 4 44 83 -69 -3 85 6 42 98 17 -92 -85 -52 51 -71 93 10 26 -42 28 50 -91 64 -73 61 92 -47 -90 67 2 -6 32 -45 -16 96 57 71 -77 -7 11 -26 29 65 -62 -9 59 -48 54 -56 56 -88 35 -58 15 14 75 -61 94 25 36 -24 -57 -80 -30 88 -22 -36 31 -94 -18 -54 62 38 -49 -99 39 -31 78 49 -32 -17 86 66"""

# print '", "'.join(nums.split(" "))

if len(argv) != 2:
	print "Please specify the number of integers you would like"
	quit(100)

def args(count):
	uni = set()

	while len(uni) < int(count):
		uni.add(randint(-10, int(count)))

	l = [str(x) for x in uni]
	shuffle(l)

	return l

print " ".join(args(argv[1]))