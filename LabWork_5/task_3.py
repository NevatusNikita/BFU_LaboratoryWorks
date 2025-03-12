with open('input_3.txt', 'r', encoding='utf8') as file:
    data = list()
    for line in file.readlines():
        prev = list(line.split())
        prev[2] = int(prev[2])
        data.append(prev)

mx = max(data, key=lambda rec: rec[2])
mn = min(data, key=lambda rec: rec[2])
mx[2] = str(mx[2])
mn[2] = str(mn[2])

with open('output_3_older.txt', 'w', encoding='utf8') as file:
    file.write(" ".join(mx))

with open('output_3_younger.txt', 'w', encoding='utf8') as file:
    file.write(" ".join(mn))
