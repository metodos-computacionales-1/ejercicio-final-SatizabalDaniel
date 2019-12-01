#!/usr/bin/env python
# coding: utf-8

# In[ ]:


import matplotlib.pyplot as plt
import numpy as np
from IPython.display import clear_output
%%bash
g++ bifurcacion.cpp
./a.out 1000 >bifurcacion.txt
bifurcacion = np.genfromtxt("bifurcacion.txt")
Fder=bifurcacion[:,0]
theta=bifurcacion[:,1]
theta[227:]+=2*np.pi
plt.figure(figsize=(10,10))
plt.scatter(Fd,theta,s=5,c='r')
plt.grid()
plt.xlabel('Fder(N)')
plt.ylabel('Theta')
plt.title('Bifurcacion')
plt.show()

