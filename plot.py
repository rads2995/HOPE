import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("nonlinear_result.txt")

plt.plot(data[:,1], data[:,2])
plt.savefig("plot.png")
