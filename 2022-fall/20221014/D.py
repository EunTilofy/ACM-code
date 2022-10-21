import math
with open('partitions.in', 'r') as f:
    n, m = map(int, f.read().split())
    siz = []
    Set = []
    for i in range(1, m + 1):
        M = map(int, f.read().split())
        siz[i] = M[0]
        Seti = []
        for j in range(1, siz[i] + 1):
            Seti.append(M[j])
        Set.append(Seti)

for i in range(1, m + 1):
    print(siz[i])
    for j in range(0, siz[i]):
        print(Set[i][j])
    
# if k > n // 2: k = n - k + 1
# with open('partitions.out', 'w') as f:
    # print(1 if n == 1 else 2 * k, file=f)