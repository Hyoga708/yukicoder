from decimal import *
vl,vr=map(long,raw_input().split())
d=input()
w=input()
t=Decimal(d)/Decimal(vl+vr)
print w*t
