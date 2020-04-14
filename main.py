import math

def f(x) :
    return math.exp(-(1/(x*x)))/(x*x)

def simpson(A, eps) :
    a = A
    b = 1.5
    I=eps+1
    I1=0
    N=2
    while N<=4 or math.fabs(I1-I)>eps :
        sum2 = 0
        sum4 = 0
        sum = 0
        h=(b-a)/(2*N)
        i=1
        while i <= 2*N-1 :
            sum4 += f(a+h*i)
            sum2 += f(a+h*(i+1))
            i += 2
        sum = f(a)+4*sum4+2*sum2-f(b)
        I=I1
        I1=(h/3)*sum
        N *= 2
    return I1

def pryam(A, n) :
    b = 1.5
    a = A
    n = int(n)
    s = (f(a)+f(b))/2
    h = (b-a)/n
    i = 1
    while i<=n-1 :
        s += f(a+i*h)
        i += 1
    l=h*s
    return l

A = (4*0.0001)**(1/4)
print("A = ", A)
print("I (Simpson, eps = 0.0001) = ", simpson(A, 0.0001))
print("Enter count of rectangles. N = ")
n=input()
print("I (Rectangles, N >= 100) = ", pryam(A,n))
