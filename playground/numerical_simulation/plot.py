import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("simulation.txt")

time = data[:,0]
x = data[:,1]
xd = data[:,2]
xdd = data[:,3]

plt.plot(x,xd, 'r--')
plt.savefig("plot.png")
