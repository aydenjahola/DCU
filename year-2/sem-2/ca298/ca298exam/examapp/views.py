from django.shortcuts import render, get_object_or_404
import random
from .models import *
from .forms import *
from django.views.generic import CreateView
from django.shortcuts import render, redirect
from django.contrib.auth import login, logout
from django.contrib.auth.views import LoginView
from django.contrib.auth.decorators import login_required
from django.utils.timezone import now 


# Create your views here.


def index(request):
    return render(request, 'index.html')

class UserSignupView(CreateView):
    model = User
    form_class = UserSignupForm
    template_name = 'user_signup.html'

    def get_context_data(self, **kwargs):
        return super().get_context_data(**kwargs)

    def form_valid(self, form):
        user = form.save()
        login(self.request, user)
        return redirect('/')




class UserLoginView(LoginView):
    template_name='login.html'


def logout_user(request):
    logout(request)
    return redirect("/")

def all_games(request):
    games = Game.objects.all()
    return render(request, 'games.html', {'games': games})

def single_game(request, game_id):
    game = get_object_or_404(Game, id=game_id)
    return render(request, 'game.html', {'game': game})

def view_products(request, platform):
    games = Game.objects.filter(platform=platform)
    return render(request, 'products.html', {'games': games})

@login_required
def create_game(request):
    user = request.user
    if not user.is_superuser:
        return redirect("/") # bounce the user back to the homepage

    if request.method == "POST":
        form = GameForm(request.POST)
        if form.is_valid():
            new_game = form.save()
            return render(request, 'message.html', {'message.html': f"{new_game.name} created sucessfully"})
        else:
            return render(request, 'create_game.html', {'form':form})
    else:
    #     # its a GET request
    #     # load a new instance of the GameForm 
    #     # show it to the user
        form = GameForm()
        return render(request, 'create_game.html', {'form': form})

def edit_game(request, game_id):
    user = request.user
    if not user.is_superuser:
        return redirect("/")
    
    game = get_object_or_404(Game, id=game_id)
    if request.method == "POST":
        form = GameEditForm(request.POST, instance=game)# create form with existing data from game
        if form.is_valid():
            new_game = form.save()
            return render(request, 'message.html', {'message': f"Game {new_game.name} updated sucessfully"})
        else:
            return render(request, 'create_game.html', {'form':form})
    else:
    #     # its a GET request
    #     # load a new instance of the GameForm 
    #     # show it to the user
        form = GameEditForm(instance=game)
        return render(request, 'create_game.html', {'form': form})
    

@login_required
def buy_game(request, game_id):
    # get the game (or 404)
    game = get_object_or_404(Game, id=game_id)
    # get the user 
    user = request.user
    # get the users shoping basket
    basket = Basket.objects.filter(user=user, completed=False).first()
    # if no shopping basket exists, create one
    if not basket:
        basket = Basket.objects.create(user=user)
    # create a new instance of GameBasket
    # look for GameBasket objects where
        # basekt = basket
        # game = game
    # we call first because filter returns a list , we only want the first item from that list
    gameBasket = GameBasket.objects.filter(basket=basket, game=game).first()
    if gameBasket is not None:
        gameBasket.quantity+=1 #  already_in_basket.quantity =  already_in_basket.quantity+1
        gameBasket.save()
    else:
        gameBasket = GameBasket.objects.create(game=game, basket=basket, unit_price=game.price)
    # decrease the stock quantity of the game by 1
    game.stock -= 1
    game.save()
    # show some confirmation
    return redirect("/basket")

@login_required
def previous_orders(request):
    user = request.user
    orders = GameUser.objects.filter(user=user)
    return render(request, 'previous_orders.html', {'orders':orders})



@login_required
def basket(request):
    basket = Basket.objects.filter(user=request.user, completed=False).first()
    if basket is None:
        basket = Basket.objects.create(user=request.user)
    # load up all of the basketitems to show
    basketitems = GameBasket.objects.filter(basket=basket)
    total_price = sum([x.total_price() for x in basketitems])
    return render(request, 'basket.html', {'basket':basket, 'basketitems':basketitems, 'total_price': total_price})

@login_required
def checkout(request):
    basket = Basket.objects.filter(user=request.user, completed=False).first()
    if basket is None:
        return redirect("/")
    basket.completed = True
    basketitems = GameBasket.objects.filter(basket=basket)
    total_price = sum([x.total_price() for x in basketitems])
    basket.total_price = total_price
    basket.date_ordered = now()
    basket.save()
    return render(request, 'thanks.html', {'basket':basket, 'basketitems':basketitems})