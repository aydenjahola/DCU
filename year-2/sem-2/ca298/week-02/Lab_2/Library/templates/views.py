from django.http import HttpResponse
from django.shortcuts import render
import random


def index(request):
    return render(request, 'index.html')


def variable(request):
    x = 5  # create a variable called x and give it a value
    # pass the variable x to the template variable.html with the name 'x'
    y = 8
    return render(request, 'variable.html', {'x': x, 'y': y})


def add(request):
    x = 2
    y = 5
    z = x + y
    return render(request, 'add.html', {'x': x, 'y': y, 'z': z})


def randomnumber(request):
    x = random.randint(0, 100)  # generate a random number between 0 and 100
    return render(request, 'random.html', {'x': x})


def ex2(request):
    x = list(range(1, 31))
    return render(request, 'ex2.html', {'x': x})


def fizzbuzz(request):
    x = list(range(1, 101))
    return render(request, 'fizzbuzz.html', {'x': x})
