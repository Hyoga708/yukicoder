def gcd(a,b):
	if b==0:
		return a
	else:
		return gcd(b,a%b)
a,b=map(long,raw_input().split())
x=max(a+b,a*b)
y=min(a+b,a*b)
print gcd(x,y)
