last = 0
size = 3

for i in range(3):
    index = (last + i + 1) % size
    print(index)
