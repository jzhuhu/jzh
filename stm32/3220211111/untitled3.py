"""
Newton法求二元函数

import numpy as np
from sympy import symbols, diff


# 首先定义二维向量内的元素
x1 = symbols("x1")
x2 = symbols("x2")


def jacobian(f, x):

    grandient = np.array([diff(f, x1).subs(x1, x[0]).subs(x2, x[1]), diff(f, x2).subs(x1, x[0]).subs(x2, x[1])], dtype=float)
    return grandient


def hessian(f, x):

    hessian_obj = np.array([[diff(f, x1, 2), diff(diff(f, x1), x2)], [diff(diff(f, x2), x1), diff(f, x2, 2)]], dtype=float)
    return hessian_obj


def newton(f, x, iters):

    Hessian_T = np.linalg.inv(hessian(f, x))
    H_G = np.matmul(Hessian_T, jacobian(f, x))
    x_new = x - H_G
    print("第1次迭代后的结果为:", x_new)
    for i in range(1, iters):
        Hessian_T = np.linalg.inv(hessian(f, x_new))
        H_G = np.matmul(Hessian_T, jacobian(f, x_new))
        x_new = x_new - H_G
        print("第"+str(i+1)+"次迭代后的结果为:", x_new)
    return x_new

if __name__ == "__main__":
    x = np.array([1.2,1.2], dtype=float)
    f = 100*(x2-x1**2)**2+(1-x1)**2
    print(newton(f, x, 2))
    
    """
    """
import numpy as np
import matplotlib.pyplot as plt
 
def jacobian(x):
 return np.array([-400*x[0]*(x[1]-x[0]**2)-2*(1-x[0]),200*(x[1]-x[0]**2)])
 
def hessian(x):
 return np.array([[-400*(x[1]-3*x[0]**2)+2,-400*x[0]],[-400*x[0],200]])
 
X1=np.arange(-1.5,1.5+0.05,0.05)
X2=np.arange(-3.5,2+0.05,0.05)
[x1,x2]=np.meshgrid(X1,X2)
f=100*(x2-x1**2)**2+(1-x1)**2; # 给定的函数
plt.contour(x1,x2,f,20) # 画出函数的20条轮廓线
 
 
def newton(x0):
 
 print('初始点为:')
 print(x0,'\n')
 W=np.zeros((2,10**3))
 i = 1
 imax = 1000
 W[:,0] = x0 
 x = x0
 delta = 1
 alpha = 1
 
 while i<imax and delta>10**(-5):
  p = -np.dot(np.linalg.inv(hessian(x)),jacobian(x))
  x0 = x
  x = x + alpha*p
  W[:,i] = x
  delta = sum((x-x0)**2)
  print('第',i,'次迭代结果:')
  print(x,'\n')
  i=i+1
 W=W[:,0:i] # 记录迭代点
 return W
 
x0 = np.array([1.2,1.2])
W=newton(x0)
 
plt.plot(W[0,:],W[1,:],'g*',W[0,:],W[1,:]) # 画出迭代点收敛的轨迹
plt.show()
"""
"""
import numpy as np
import random
import matplotlib.pyplot as plt

def goldsteinsearch(f,df,d,x,alpham,rho,t):
    flag=0
    a=0
    b=alpham
    fk=f(x)
    gk=df(x)
    phi0=fk
    dphi0=np.dot(gk,d)
    alpha=b*random.uniform(0,1)

    while(flag==0):
        newfk=f(x+alpha*d)
        phi=newfk
        if(phi-phi0<=rho*alpha*dphi0):
            if(phi-phi0>=(1-rho)*alpha*dphi0):
                flag=1
            else:
                a=alpha
                b=b
                if(b<alpham):
                    alpha=(a+b)/2
                else:
                    alpha=t*alpha
        else:
            a=a
            b=alpha
            alpha=(a+b)/2
    return alpha

def rosenbrock(x):
    return x[0]**3-x[1]**3+9*x[0]*x[1]# 给定的函数

def jacobian(x):
    return np.array([3*x[0]**2+9*x[1],-3*x[1]**2+9*x[0]])# 给定的函数梯度


X1=np.arange(-1.5,1.5+0.05,0.05)
X2=np.arange(-3.5,2+0.05,0.05)
[x1,x2]=np.meshgrid(X1,X2)
f=x1**3-x2**3+9*x1*x2; # 给定的函数
plt.contour(x1,x2,f,20) # 画出函数的20条轮廓线

def steepest(x0):
    print('初始点为:')
    print(x0,'\n')
    imax = 100
    W=np.zeros((2,imax))
    W[:,0] = x0
    i = 1
    x = x0
    grad = jacobian(x)
    delta = sum(grad**2)  # 初始误差

    while i<imax and delta>10**(-12):
        p = -jacobian(x)
        x0=x
        alpha = goldsteinsearch(rosenbrock,jacobian,p,x,1,0.1,2)



        x = x + alpha*p
        W[:,i] = x
        grad = jacobian(x)
        delta = sum(grad**2)
        i=i+1

    print("迭代次数为:",i)
    print("近似最优解为:")
    print(x,'\n')
    W=W[:,0:i]  # 记录迭代点
    return W

x0 = np.array([5.0,-4.2])
W=steepest(x0)
"""
#当前点的梯度计算
def grad_f(x, y):
    dx = -10*x + 48
    dy = -20*y + 24
    return [dx, dy]


#函数原型函数
def f(x, y):
    return -5*(x**2) + 48*x - 10*(y**2) + 24*y + 11


#主函数
if __name__ == "__main__":
    #初始的x,y位置
    x = 0.0
    y = 0.0
    #学习率
    learning_rate = 0.001
    #最大迭代次数
    max_iter_num = 30000

    for step in range(0, max_iter_num):
        #因为需要求解的极值是最大值，
        #所以需要使用梯度上升公式进行迭代修正
        grad_x, grad_y = grad_f(x, y)
        x += learning_rate * grad_x
        y += learning_rate * grad_y

        #重新计算当前的函数值
        fx = f(x, y)

        #每迭代1000次，输出一下当前的函数值结果
        if step % 1000 == 0:    
            print(x, y, fx)
