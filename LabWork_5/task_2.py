with open('input_2.txt', 'r') as file:
    data = list([line.rstrip() for line in file])

with open('output_2.txt', 'w') as file:
    file.write(" ".join(sorted(data)))
