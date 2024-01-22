from django.urls import path
from . import views

urlpatterns = [
    path('', views.index, name="index"),
    path('variable', views.variable, name="variable"),
    path('add', views.add, name="add"),
    path('random', views.randomnumber, name='random'),
    path('ex2', views.ex2, name='ex2'),
    path('fizzbuzz', views.fizzbuzz, name='fizzbuzz'),
]
