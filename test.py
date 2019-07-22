from subprocess import check_output, PIPE, Popen
# from random import randint

# numbers = [str(randint(1, 100000)) for x in range(1, 30)]

# for i in range(1, 10000):
# 	ps = Popen(['./push_swap'] + numbers, stdout=PIPE)

# 	command = ['./checker'] + numbers
# 	output = check_output(command, stdin=ps.stdout)
# 	res = output.decode("utf-8")
# 	ps.wait()

# 	if res != 'OK\n':
# 		print("FAIL!!")
# 		break

from random import randint
from sys import argv

iter = 30
if len(argv) > 1:
	iter = int(argv[1])

def args(count):
	uni = set()

	while len(uni) < count:
		uni.add(randint(0, 5000000))

	return [str(x) for x in uni]
	# return [str(randint(0, 5000000)) for x in range(0, count)]



test_iter = 300

while test_iter > 1:
	command = ['./push_swap'] + args(test_iter)
	try:
		output = check_output(command)
		print("Digits : {0} __ Moves : {1}".format(str(test_iter), len(output.split('\n'))))
	except KeyboardInterrupt:
		quit()
	except Exception as e:
		print("Error!", e.message)
	
	test_iter -= 1