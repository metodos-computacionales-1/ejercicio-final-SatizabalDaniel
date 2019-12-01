#!/usr/bin/env python
# coding: utf-8

# In[ ]:


import matplotlib.pyplot as plt
import numpy as np
from IPython.display import clear_output
%%bash
g++ pendulo.cpp
./a.out 10000000 >pendulo.txt
pendulo = np.genfromtxt("pendulo.txt")
theta=Pendulo[:,1]
t=Pendulo[:,0]
omega=Pendulo[:,2]
plt.figure(figsize=(15,4))
plt.plot(time,theta,c='r')
plt.grid()
plt.xlabel('t(s)')
plt.ylabel('Theta')
plt.title('Fderv=1.4 N')
plt.show()
for i in range(10,len(theta),100):
    plt.scatter(theta[:i],omega[:i],s=3,c='r',label='t='+str(t[i])+'s')
    plt.ylim(-3.2,1.7)
    plt.xlim(-3.3,3.3)
    plt.grid()
    plt.legend()
    plt.xlabel('Theta')
    plt.ylabel('Omega')
    plt.savefig(str(i).zfill(4)+'.png')
    plt.close()

