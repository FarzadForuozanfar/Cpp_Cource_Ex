feri = []
while(True):
    x = int(input())
    if not x == 0:
        feri.append(x)
    else:
        break
feri.reverse()
for x in feri:
    print(x)