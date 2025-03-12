with open('input_1.txt', 'r') as file:
    data = list(map(int, file.readline().rstrip().split()))

pr = 1
for el in data:
    pr *= el

with open('output_1.txt', 'w') as file:
    file.write(str(pr))
