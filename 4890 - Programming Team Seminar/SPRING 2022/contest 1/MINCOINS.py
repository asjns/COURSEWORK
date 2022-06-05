T = int(input())

for _ in range(T):
    X = int(input())
    if X % 5 > 0:
        print(-1)
    else:
        print(X // 10 + (X % 10) // 5)
    
