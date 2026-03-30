import numpy as np
import matplotlib.pylab as plt

# x=np.array([-1.0,1.0,2.0])
# print(x)
# y=x>0
# print(y)
# y=y.astype(np.int_)
# print(y)

# def sigmoid(x):
#     return 1/(1+np.exp(-x))

# x=np.array([-1.0,1.0,2.0])
# print(sigmoid(x))
def sigmoid(x):
    return 1/(1+np.exp(-x))
x=np.arange(-5.0,5.0,0.1)
y=sigmoid(x)
plt.plot(x,y)
plt.ylim(-0.1,1.1)
plt.show()
