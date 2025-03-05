dct = {'Hello': 'Hi',
       'Bye': 'Goodbye',
       'List': 'Array'}
find_value = input()
key_ans = ''
for key, value in dct.items():
    if value == find_value:
        key_ans = str(key)
if key_ans != '':
    print(key_ans)
else:
    print('Key is not found')
