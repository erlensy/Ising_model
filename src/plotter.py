from matplotlib import pyplot as plt
import multiprocessing
import numpy as np
from matplotlib.animation import FuncAnimation

def animate(i):
    im.set_array(lattices[i])
    return im,
    
    
if __name__ == '__main__':
    lattice = []
    lattices = []
    with open("../data/lattice.txt") as file:
        for row in file:
            if "," in row:
                lattices.append(lattice)
                lattice = []
                continue
            lattice.append(list(map(int, row.rstrip().split(" "))))


    nFrames = 300
    fig = plt.figure()
    im = plt.imshow(lattices[0], cmap = "Greys")
    anim = FuncAnimation(fig, animate, frames = nFrames, interval = 25, blit = True)
    plt.show()

