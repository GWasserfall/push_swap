from random import randint

a = 0
n = []

while a < 100000:
	n.append(randint(0, 20000000))
	a += 1

result = set(n)

with open("numbers.txt", 'w') as f:
	f.write(" ".join([ str(x) for x in result]))