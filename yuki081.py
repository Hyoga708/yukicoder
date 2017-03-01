from decimal import Decimal
n=input()
ret=Decimal("0")
for i in xrange(n):
	a=raw_input()
	ret+=Decimal(a)
print("{0:.10f}".format(ret))
