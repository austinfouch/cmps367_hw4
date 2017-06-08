import sys

def load_file(filename):
	content = []
	f = open(filename, 'r')
	content = [x.strip('\n') for x in f.readlines()]
	f.close()
	return content[0] # need further implementation if more than 1 line in file

def get_input():
	str1 = load_file(sys.argv[1])	# file 1 as str
	str2 = load_file(sys.argv[2])	# file 2 as str
	print("Input Sequences")
	print("-" * 30)
	print(str1)
	print(str2)
	print("-" * 30)
	return (str1, str2)

def align_input():
	tmp = get_input()
	S = tmp[0]
	T = tmp[1]
	M = len(S) + 1
	N = len(T) + 1
	D = [[0 for x in range(M)] for x in range(N)] # matrix M x N where M = rows and N = cols
	for i in range(M):	# loops 9 times
		for j in range(N):		# loops 7 times
			print(S[j], T[i])
			if S[j] == T[i]:
				D[i][j] = D[i-1][j-1]
			else:
				x = D[i-1][j] + 1
				y = D[i][j-1] + 1
				z = D[i-1][j-1] + 1
				D[i][j] = min((x,y,z))

align_input()
#calculate edit distance
#get execution time