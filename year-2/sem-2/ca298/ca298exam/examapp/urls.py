from django.urls import path, include
from . import views
from .forms import * # add o imports at the top of the file

urlpatterns = [
    path('',views.index, name="index"),# mywebsite.com 
    path('register/', views.UserSignupView.as_view(), name="register"),
    path('login/',views.LoginView.as_view(template_name="login.html", authentication_form=UserLoginForm), name='login'),
    path('logout/', views.logout_user, name="logout"),
    path('games/', views.all_games, name='games'),
    path('games/<int:game_id>/', views.single_game, name='single_game'),
    path('games/<int:game_id>/edit', views.edit_game, name='edit_game'),
    path('games/create/', views.create_game, name='create_game'),
    path('games/<str:platform>/', views.view_products, name='view_products'),
    path('buy/<int:game_id>/', views.buy_game, name='buy_game'),
    path('orders/', views.previous_orders, name="previous_orders"),
    path('basket/', views.basket, name="basket"),
    path('checkout/', views.checkout, name="checkout"),


]