'''b = 9223372036854780 // 2
print(b & 0xffffffff)
print(b >> 32)
print(b)
c = 2**32
print(c & 0xffffffff)
print(c >> 32)
print(c)
d = b * c
print(d & 0xffffffff)
d = d >> 32
print(d & 0xffffffff)
print(d >> 32)
print(b * c)

a = 2**64 - 3*2**35
print(a);
print(a & 0xffffffff)
print((a >> 32) & 0xffffffff)
print(a >> 64)'''

print(9223372036854780223372036854781//101231)
print(9223372036854780223372036854781%101231)