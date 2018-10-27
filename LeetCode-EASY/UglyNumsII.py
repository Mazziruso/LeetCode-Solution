# n = 9
#
# us = [1, 2, 3, 4, 5]
#
#
# n1 = n
#
# while n > 5:
# 	num = us[-1]
# 	a = num
# 	while a != 1:
# 		num += 1
# 		a = num
# 		# us.reverse()
# 		for x in us[-1:0:-1]:
# 			while (a % x) == 0:
# 				a = int(a/x)
#
# 	# us.reverse()
# 	us += [num]
# 	n -= 1
#
#
# if n1 <= 5:
# 	print('{}-th ugly number is '.format(n1), us[n1-1])
# else:
# 	print('{}-th ugly number is '.format(n1), us[-1])

# def uglyNums(num, us):
# 	a = num
# 	for x in us[-1:0:-1]:
# 		while (a % x) == 0:
# 			a = int(a/x)
#
# 	if a == 1:
# 		us += [num]
# 		return num, us
#
# 	return uglyNums(num+1, us)
#
# n = 150
# us = [1, 2, 3, 4, 5]
#
# n1 = n
#
# while n > 5:
# 	num, us = uglyNums(us[-1]+1, us)
# 	n -= 1
#
#
# if n1 <= 5:
# 	print('{}-th ugly number is '.format(n1), us[n1-1])
# else:
# 	print('{}-th ugly number is '.format(n1), num)
#
# print(us)


#最优
primes = [2, 7, 13, 19]
n = 1000

us = [1]
ik = [0 for k in range(0, len(primes))]
uk = [i for i in primes]

while n > 1:

	umin = min(uk)

	if umin != 1:
		us.append(umin)

	for k in range(0, len(primes)):
		if umin == uk[k]:
			ik[k] += 1
			uk[k] = primes[k] * us[ik[k]]

	n -= 1


print(us[-1])

