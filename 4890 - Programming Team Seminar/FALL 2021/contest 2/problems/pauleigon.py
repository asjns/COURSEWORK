import math

N, P, Q = [int(x) for x in input().split()]
if P+Q < N or (math.floor((P+Q)/N)%2) == 0:
    print("paul")
else:
    print("opponent")