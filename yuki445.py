import math
from decimal import *
a,b=map(int,raw_input().split())
print int(50*a+math.floor(Decimal(50*a)/(Decimal(0.8)+Decimal(0.2)*b)))
