m=input()
a=(2017*2017)%m
p=2017
ret=1
while p>0:
	if p&1:
		ret=(ret*a)%m
	a=(a*a)%m
	p/=2
ret=(ret+2017)%m
print ret
