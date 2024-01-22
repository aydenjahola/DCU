from django.http import HttpResponse
from django.shortcuts import render
import random


def index(request):
    count = random.randint(0, 100)
    countb = random.randint(100, 1000)
    return render(request, 'index.html', {'count': count, 'another': countb})


def contact(request):
    return render(request, 'contact.html')
