import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("simulation_result.txt")

time = data[:,0]
x = data[:,1]
y = data[:,2]

plt.plot(x, y)
plt.savefig("output.png")

