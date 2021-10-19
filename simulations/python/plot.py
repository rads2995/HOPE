import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("simulation.txt")

time = data[:,0]
x = data[:,1]
y = data[:,2]

plt.plot(x, y, 'r')
plt.savefig("output.png")
