# print('Hello World\n')

# hello = "Jacob"
# print(hello)


# Name = input('Name: ')
# Age = input('Age: ')
# print('Hello', Name, 'you are', Age, 'years old')


# hello = 'hello'.upper()
# print(hello)

# hello = 'hello'
# print(hello.upper())

# lower = 'LOWER'.lower()
# print(hello)

# world = 'heLlO WorLD'
# print(world.capitalize())

# count = 'coffee'
# print(count.count('ff'))

# count = 'coffee'
# print(count.count('FF'))

# count = 'coffee'
# print(count.upper().count('FF'))


# x = 'hello'
# y = 3
# z = 'yes'
# print(x * y)
# print(x + z)

# x = 'hello'
# y = 'hello'
# print(x == y)
# print(x != y)

# print(ord('Z'))
# print(ord('a'))
# print('a' > 'Z')

# result = 6 == 6
# print(result)


# x = input('Name: ')
# if x == 'Josh':
#     print('Drives a Prius')
# elif x == 'Coob':
#     print('Sexiest man alive')
# else:
#     print("Sad")


# x = [4, True, 'hi']
# x.append('hello')
# x.extend([4,5,5,5,5])
# y = 'Coob'
# print(x)
# print(len(x), len(y))
# print(x.pop()) #Pulls last item and removes from list
# print(x)
# print(x.pop(1)) #Pulls indexed item and removes from list
# print(x)
# print(x[0])
# x[0] = 'hey'
# print(x)

# z = x #Refernce to x list
# print(x, z)
# z = x[:] #Copy current list
# x[0] = 0
# print(x, z)

# x = (0,1,2,3) #Unchanable list
# #x[0] = 5 #Does not work
# print(x)

# x = [[], (), [[], [], [3,4,5]]] #Lists inside lists


# for i in range(1,10, 2): #start, stop, step
#     print(i)

# for i in [3,4,42,3,2,4]:
#     print(i)

# x = [3,4,42,3,2,4]
# for i in range(len(x)):
#     print(x[i])

# for i, element in enumerate(x):
#     print(i, element)

# i = 0
# while i < 10:
#     print('run')
#     i+=1
#     if i == 10:
#         break


# x = [0,1,2,3,4,5,6,7,8]
# y = ['hi', 'hello', 'goodbye', 'cya', 'sure']
# s = "hello"
# sliced1 = x[2:4:1] # [start:stop:step]
# sliced2 = y[::-1] # easy way to reverse list
# sliced3 = (1,2,3,4,4,3,2,1)[::2]
# print(sliced1)
# print(sliced2)
# print(sliced3)


# x = set() #best way to do it
# s = {1,2,3,4,4} #worse way to do it, creates dictionary
# print(s)
# s.add(5)
# print(s)
# s.remove(5)
# print(s)
# print(4 in s)
# print(6 in s)

# s2 = {4,3,2,1}
# print(s.union(s2))
# print(s.difference(s2))
# print(s.intersection(s2))


# x = {'key': 4}
# print(x['key'])

# x['key2'] = 5
# x[2] = 8
# x[3] = [1,2,3,4]
# print(x)

# print('key' in x)
# print(list(x.values()))
# print(list(x.keys()))

# del x['key']
# print(x)

# for key, value in x.items():
#     print(key, value)

# for key in x:
#     print(key, x[key])


# x = [x for x in range(5)]
# print(x)

# x = [x + 5 for x in range(5)]
# print(x)

# x = [x % 2 for x in range(5)]
# print(x)

# x = [0 for x in range(5)]
# print(x)

# x = [[0 for x in range(100)] for x in range(5)]
# print(x)

# x = [i for i in range(100) if i % 5 == 0]
# print(x)

# x = {i : 0 for i in range(100) if i % 5 == 0} #dictionary
# print(x)

# x = {i for i in range(100) if i % 5 == 0} #set
# print(x)

# x = tuple(i for i in range(100) if i % 5 == 0) #tuple
# print(x)


# def func():
#     print('run') 
#     def func():
#         print('hi')
#     func()
# func()

# def func(x, y, z = None):
#     print(x, y, z)
#     return x * y, x / y #can retrurn multiple things in a touple
# r1, r2 = func(5, 6)
# print(r1, r2)


# def func(x):
#     def func2():
#         print(x)

#     return func2

# print(func(3))
# print(func(3)())
# func(3)()

# x = func(3)
# x()

# def func(*args, **kwargs):
#     pass
# x = [1,2,3,4]
# print(x)
# print(*x) #unpacks the list

# def func(x,y):
#     print(x,y)
# pairs = [(1,2), (3,4)]
# for pair in pairs:
#     func(*pair)

# func(**{'x':2, 'y':5}) #** for dictionary

# def func(*args, **kwargs):
#     print(args, kwargs)
#     print(*args)
# func(1,2,3,4,5,one=0, two=1)


# x = 'jacob' #global variable to function
# def func(name):
#     x = name #local varibale to function
# print(x)
# func('changed')
# print(x, '\n')

# x = 'jacob' #global variable to function
# def func(name):
#     global x # make varibale global DO NOT USE
#     x = name #local varibale to function
# print(x)
# func('changed')
# print(x)


# raise Exception('Bad')
# raise FileExistsError('Anything')

# try:
#     x = 7 / 0
# except Exception as e:
#     print(e)
# finally:
#     print('finally')


# x = lambda x, y: x + y
# print(x(2, 32))

# x = [1,2,3,4,5,6,7,8,9]
# mp = map(lambda i: i+2, x)
# print(list(mp))

# fltr = filter(lambda i: i % 2 == 0, x) #better than below
# print(list(fltr))

# def func(i): #worse than above
#     i = i * 3
#     return i % 2 == 0
# fltr = filter(func, x)
# print(list(fltr))

# x = f'hello {6 + 8}'
# print(x)

# print(f'hello {21}')