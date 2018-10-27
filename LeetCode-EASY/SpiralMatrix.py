def spiralMatrix(matrix, x, y, m, n, start):
	if n < 0:
		print("Error!")
	elif (n == 0) or (m == 0):
		return
	elif n == 1:
		for i in range(m):
			matrix[x+i][y] = start
			start += 1
	elif m == 1:
		for i in range(n):
			matrix[x][y+i] = start
			start += 1
	else:
		for i in range(n):
			matrix[x][y+i] = start
			start += 1
		for i in range(1, m):
			matrix[x+i][y+n-1] = start
			start += 1
		for i in range(1, n):
			matrix[x+m-1][y+n-i-1] = start
			start += 1
		for i in range(1, m-1):
			matrix[x+m-i-1][y] = start
			start += 1
		spiralMatrix(matrix, x+1, y+1, m-2, n-2, start)


m = 20
n = 30
matrix = []
for i in range(m):
	matrix = matrix + [[0 for j in range(n)]]

spiralMatrix(matrix, 0, 0, m, n, 1)

for i in matrix:
	for j in i:
		print("%4d"%j, end=' ')
	print(end='\n')