x = 100
y = 10

p = x
q = y

res = 0
for i in range(30,-1,-1):
	cx = int(p/pow(2,i))
	cy = int(q/pow(2,i))

	if cx != cy:
		res += 1

	if cx == 1:
		p -= pow(2,i)
	if cy == 1:
		q -= pow(2,i)

print(res)
print(type(res))