from difflib import SequenceMatcher

n = int(input())
strings = []

for _ in range(n):
    strings.append(str(input()))
    
s2 = min(strings,key=len)

for s1 in strings:
    match = SequenceMatcher(None, s1, s2).find_longest_match(
        0, len(s1), 0, len(s2))
    s2 = s2[match.b : match.b + match.size]
    
print(match.size)
