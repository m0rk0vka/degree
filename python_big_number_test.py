a = 9223372036854780 // 4
b = 9223372036854780 // 2
print(a)
print(b)
print("ans = ", a + b)

a = -(9223372036854780 // 4)
b = -(9223372036854780 // 2)
print(a)
print(b)
print("ans = ", a + b)

a = -(9223372036854780 // 4)
b = 9223372036854780 // 2
print((a + b) & 0xffffffff)
print((a + b) >> 32)
print("ans = ", a + b)

a = 9223372036854780 // 4
b = -(9223372036854780 // 2)
print((a + b) & 0xffffffff)
print((a + b) >> 32)
print("ans = ", a + b)
