'''
	Austin Fouch
	CMPS 367 Python Programming
	Homework #4
	homework3.py
		This program takes in two files as command line arguments and
		calculates the Levenshtein Distance of the strings contained
		in the files. Also displays the aligned strings. 
'''
import sys	# for command line args
import time	# for program exec time

# load_file()
#	returns the first string in a file
def load_file(filename):
	content = []
	f = open(filename, 'r')
	content = [x.strip('\n') for x in f.readlines()]
	f.close()
	return content[0]
# load_file()

# get_input()
#	returns tuple that contains the strings from the input files
def get_input():
	str1 = load_file(sys.argv[1])	# file 1 as str
	str2 = load_file(sys.argv[2])	# file 2 as str
	print("Input Sequences")
	print("-" * 30)
	print(str1)
	print(str2)
	print("-" * 30)
	return (str1, str2)
# get_input()

# calc_Levenshtein_Distance()
#	creates matrix based on the input strings, calculates the Levenshtein
#	Distance between the strings, and prints the strings out, aligned
def calc_Levenshtein_Distance():
	start = time.time()
	tmp = get_input()
	S = tmp[0]			# first file as string
	T = tmp[1]			# second file as string
	M = len(S) + 1
	N = len(T) + 1
	D = [[0 for element in range(M)] for element in range(N)]
	E = [[0 for element in range(M)] for element in range(N)]
	''' inserting into D and E '''
	for i in range(0, M):
		D[0][i] = i
		for j in range(0, N):
			D[j][0] = j
	for i in range(1,N):
		for j in range(1,M):		
			if S[j-1] == T[i-1]:
				D[i][j] = D[i-1][j-1]
				E[i][j] = 0
			else:
				x = D[i-1][j] + 1
				y = D[i][j-1] + 1
				z = D[i-1][j-1] + 1
				D[i][j] = min((x,y,z))
				if x == min((x,y,z)):
					E[i][j] = 1
				elif y == min((x,y,z)):
					E[i][j] = 2
				elif z == min((x,y,z)):
					E[i][j] = 0
	''' creating result strings '''
	S_RESULT = ""
	T_RESULT = ""
	i = N - 1
	j = M - 1
	while i > 0 or j > 0:
		if E[i][j] == 0:
			S_RESULT = S[j-1] + S_RESULT
			T_RESULT = T[i-1] + T_RESULT
			i -= 1
			j -= 1
		if E[i][j] == 1:
			S_RESULT = '-' + S_RESULT
			T_RESULT = T[i-1] + T_RESULT
			i -= 1
		if E[i][j] == 2:
			S_RESULT = S[j-1] + S_RESULT
			T_RESULT = '-' + T_RESULT
			j -= 1
	end = time.time()
	''' print result strings, edit distance, and execution time '''
	print("Aligned Sequences")
	print("-"*30)
	print(S_RESULT)
	print(T_RESULT)
	print("-"*30)
	print("The minimum edit distance is", D[-1][-1])
	print("Completed in", float(end-start), "seconds")
# calc_Levenshtein_Distance()

# Main
calc_Levenshtein_Distance()
# Main