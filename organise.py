import os
import sys

def print_functions(path):
	with open(path, "r") as f:
		print f.read()


def is_function(line):
	text = ""
	if line[0] in ['/', '*', '\t', ' ', '\n', '{', '}', '#']:
		return False
	if ('\t') in line:

		return line.split("\t")[0] in ['int', 'char', 'bool', 't_', 'void', 'long']
	else:

		return line.split(" ")[0] in ['int', 'char', 'bool', 't_', 'void', 'long']

def count_functions(path):
	count = 0
	with open(path, "r") as f:
		for line in f.readlines():
			if is_function(line):
				print " ", line,
				count += 1
	return count

for root, folders, files in os.walk(sys.argv[1]):
	if "git" in root or "libft" in root:
		continue
	for f in files:
		if (f.endswith(".c")):
			print "\n", f
			print count_functions(root + "/" + f)