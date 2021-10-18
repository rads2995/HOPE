import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("simulation.txt")

time = data[:,0]
x = data[:,1]
y = data[:,2]
z = data[:,3]

plt.plot(x, z, 'r')
plt.savefig("output.png")
