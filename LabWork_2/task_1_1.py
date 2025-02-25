s = input()
ans = ''
i = 1
while i < len(s):
    if s[i].isdigit() and s[i - 1].isalpha():
        ans += (s[i - 1] * int(s[i]))
        i += 2
    elif s[i].isalpha() and s[i - 1].isalpha():
        ans += s[i - 1]
        i += 1
if s[-1].isalpha():
    ans += s[-1]
print(ans)
