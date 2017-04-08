s=raw_input()
left="(^^*)"
right="(*^^)"
l=0
r=0
i=0
while i<len(s):
	if s[i:i+5]==left:
		l+=1
	elif s[i:i+5]==right:
		r+=1
	i+=5
print l,r
