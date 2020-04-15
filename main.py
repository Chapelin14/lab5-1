import math

def f(x) :
    return math.exp(-(1/(x*x)))/(x*x)

def Simpson(a, b, h) :
    sum = f(a) + f(b)
    i = 1
    x = a + h
    while x < b - h :
        if i%2 != 0 :
            sum += 4*f(x)
        else :
            sum += 2*f(x)
        x += h
        i += 1
    return h*sum/3.

def rectangles(a, b, h) :
    sum = 0
    x = a + h * 0.5
    while x < b :
        sum += f(x)
        x += h
    sum *= h
    return sum




A = (4*0.0001)**(1/4)
print("A = ", A)

a = A
b = 1.5
h = 0.00005
simp = Simpson(a, b , h)
h /= 2
divsimp = Simpson(a, b, h)
err_val = math.fabs(simp - divsimp)/12.
while err_val > 0.0001 :
    simp = Simpson(a, b , h)
    h /= 2
    divsimp = Simpson(a, b, h)
    err_val = math.fabs(simp - divsimp)/12
print("I (w eps =< 0.0001) = ", Simpson(a, b, h), " Error: ", err_val)
rect = rectangles(a, b, h)
h /= 2
divrect = rectangles(a, b ,h)
err_val = math.fabs(rect - divrect)/4.
while err_val > 0.0001 :
    rect = rectangles(a, b, h)
    h /= 2
    divrect = rectangles(a, b ,h)
    err_val = math.fabs(rect - divrect)/4.
print("I (w eps =< 0.0001) = ", rectangles(a, b, h), " Error: ", err_val)
input()
