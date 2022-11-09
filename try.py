def fact(a):
	j=1
	for i in range(2,a+1):
		j*=i
	return j

n=0
ans =0
while(n<5):
	n+=1
	print(1/fact(n))
	ans += 1/fact(n)