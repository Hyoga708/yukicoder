n=input()
ret=0
base=1
while n:
	ret+=base*(n%7)
	base*=10
	n/=7
print ret
