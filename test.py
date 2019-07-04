from subprocess import check_output, PIPE, Popen
from random import randint

numbers = [str(randint(1, 100000)) for x in range(1, 30)]

for i in range(1, 10000):
	ps = Popen(['./push_swap'] + numbers, stdout=PIPE)

	command = ['./checker'] + numbers
	output = check_output(command, stdin=ps.stdout)
	res = output.decode("utf-8")
	ps.wait()

	if res != 'OK\n':
		print("FAIL!!")
		break