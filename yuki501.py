n,d=map(int,raw_input().split())
if n>=d:
	print "A"*d+"C"*(n-d)
else:
	m=d-n
	print "A"*(n-m)+"B"*m
