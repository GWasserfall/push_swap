from random import shuffle

sa = [3, 10, 5, 8, 4, 9, 2, 6, 1, 8, 7]
sb = []

#shuffle(sa)


def pa():
	if len(sb) > 1:
		sa.insert(1, sb.pop())

def pb():
	if len(sa) > 1:
		sb.insert(1, sa.pop())

def rb():
	if len(sb) > 1:
		sb.append(sb.pop(0))
		
pb()
pb()

while len(sa) > 0:

	if sb[0] - sa[0] > 0:
			pb()
	
	rb()

	print "SA :", sa
	print "SB :", sb