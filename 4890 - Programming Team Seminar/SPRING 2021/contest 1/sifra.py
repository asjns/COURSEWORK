import re

code = input()

ints = re.findall('[0-9]*',code)

while '' in ints:
    ints.remove('')

res = []
[res.append(x) for x in ints if x not in res]

print(len(res))

