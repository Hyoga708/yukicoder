s=raw_input()
#(^^*)
left=[[0 for i in range(6)] for j in range(len(s))]
left[0][0]=1
right=[[0 for i in range(6)] for j in range(len(s))]
right[0][0]=1
for i in xrange(len(s)):
	if i==0:
		if s[0]=='(':
			left[0][1]=1
			right[0][1]=1
		continue
	for j in range(6):
		left[i][j]+=left[i-1][j]
		right[i][j]+=right[i-1][j]
	if s[i]=='(':
		left[i][1]+=left[i-1][0]
		right[i][1]+=right[i-1][0]
	elif s[i]=='^':
		left[i][2]+=left[i-1][1]-left[i-1][2]
		left[i][3]+=left[i-1][2]-left[i-1][3]
		right[i][3]+=right[i-1][2]-right[i-1][3]
		right[i][4]+=right[i-1][3]-right[i-1][4]
	elif s[i]=='*':
		left[i][4]+=left[i-1][3]-left[i-1][4]
		right[i][2]+=right[i-1][1]-right[i-1][2]
	elif s[i]==')':
		left[i][5]+=left[i-1][4]
		right[i][5]+=right[i-1][4]
print left[len(s)-1][5],right[len(s)-1][5]
