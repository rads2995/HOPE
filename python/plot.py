import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("../debug/nonlinear_result.txt")

ax = plt.figure().add_subplot(projection='3d')
ax.plot(data[:,1], data[:,2], data[:,3], lw=0.5)
ax.set_xlabel("x")
ax.set_ylabel("y")
ax.set_zlabel("z")
ax.set_title("Lorenz Attractor")
fig = ax.get_figure()
fig.savefig("figure.png")
