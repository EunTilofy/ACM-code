import sys
import math
a,b = map(int,sys.stdin.readline().split())
c = 1.0
if(b==1):
    if(a==1):
        print(1)
    else:
        print(-1)
else:
    if(b>=a):
        print(1)
    else:
        for i in range (a-b):
            c = c*b/(b-1)
            c = math.floor(c+0.5)
        d=math.floor(c+0.5)
        print(d)
