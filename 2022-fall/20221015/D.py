import math
# with open('partitions.in', 'r') as f:
#     n, m = map(int, f.read().split())
#     siz = []
#     Set = []
#     print(n)
#     print(m)
#     for i in range(1, m + 1):
#         M = map(int, f.read().split())
#         siz[i] = M[0]
#         Seti = []
#         for j in range(1, siz[i] + 1):
#             Seti.append(M[j])
#         Set.append(Seti)

n,m = map(int, input().split())
siz = [0]
Set = [[]]
for i in range(1, m + 1):
    M = list(input().split())
    siz.append(int(M[0]))
    Seti = [0]
    for j in range(1, siz[i] + 1):
        Seti.append(int(M[j]))
    Set.append(Seti)

fact = []
fact.append(1)
nm = 1
for i in range (1, 105):
    nm = nm * i
    fact.append(nm)

C = []
C.append([1])
for i in range(1, 105):
    Ci = [1]
    for j in range (1, i):
        Ci.append(C[i-1][j] + C[i-1][j-1])
    Ci.append(1)
    C.append(Ci)


S = [[0]]
for i in range(1, 105):
    Si = [0]
    for j in range(1, i):
        Si.append(j * S[i - 1][j] + S[i - 1][j - 1])
    Si.append(1)
    S.append(Si)

# d[x][y]
def GET(x, y):
    nm = 0
    for i in range(0, n - y + 1):
        nm = C[n - y][i]
        nm0 = 0
        for j in range (1, n - y - i + 1):
            nm0 = nm0 + S[n - y - i][j]
        nm = nm * nm0 * pow(m, i)  

d = []
for i in range (0, n + 1):
    di = []
    for j in range(0, n + 1):
        di.append(GET(i,j))
    d.append(di)
    
ans = 0

def _1(n):
    if(n & 1):
        return -1
    else:
        return 1

def getans(num, m, l):
    return _1(num) * d[m][l]

ALL = 1<<m 

fa = [0]
for i in range (1, m + 1):
    fa.append(i)

for Par in range(0, ALL):
    _in = [0]
    BLOCK = m
    for i in range (1, m + 1):
        fa.append(i)
    for i in range(0, n):
        if((Par>>i&1) == 0):
            BLOCK = BLOCK - 1
        _in.append(Par>>i&1)
    
    BBLOCK = BLOCK
    all_num = 0
    
    ans = ans + getans(BBLOCK, BLOCK, all_num)
        
 

with open('partitions.out', 'w') as f:
    print(str(ans), file=f)
