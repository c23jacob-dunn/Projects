def add(*args):
    total = 0
    for arg in args:
        total += arg
    print(total)

add(100,99,98)



def calculate(n, **kwargs):
    print(kwargs)
    for key,value in kwargs.items():
        print(key)
    print(kwargs["add"])
    n += kwargs["add"]
    n *= kwargs["multiply"]
    print(n)

calculate(2, add=3, multiply=5)



class Car:
    def __init__(self, **kw):
        self.make = kw.get("make")
        self.model = kw.get("model")

my_car = Car(make="Dodge")
print(my_car.model)
