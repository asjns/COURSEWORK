n = int(input())
courses = {}
for _ in range(n):
    l, f, c = [str(x) for x in input().split()]
    if c not in courses:
        courses[c] = set()
    courses[c].add(l+' '+f)

for c in sorted(courses):
    print(c,len(courses[c]))