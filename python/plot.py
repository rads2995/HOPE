import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("simulation_result.txt")

t = data[:,0]
x = data[:,1]
y = data[:,2]

plt.plot(t, x)
#plt.plot(t, y)
plt.savefig("output.png")

