n=input()
if n>=50:
	print "000000000000"
else:
	mod=1000000000000
	i=2
	ret=1
	used=False
	while i<=n:
		ret*=i
		if(ret>=mod):
			ret%=mod
			used=True
		i+=1
	i=0
	if used:
		while mod/10>ret:
			i+=1
			mod/=10
	print "0"*i+str(ret)
