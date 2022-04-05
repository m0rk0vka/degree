import matplotlib.pyplot as plt

def trap(fraction):
	sign = 1

	if fraction[0] == '-':
		sign *= -1
		fraction = fraction[1:]

	slesh_index = fraction.find('/')

	numerator = int(fraction[:slesh_index])
	denominator = int(fraction[slesh_index + 1:])

	return sign * numerator / (denominator * 1.0)

with open("50_answer_ss.txt") as f:
	n = f.readline()
	data = f.readlines()

	data = list(map(trap, data))

plt.plot([i for i in range(len(data))], data)
plt.show()