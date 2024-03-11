from .models import *
from django import forms
from django.contrib.auth.forms import UserCreationForm, AuthenticationForm
from django.forms import ModelForm, ModelChoiceField
from django.db import transaction


class GameForm(forms.ModelForm):
    class Meta:
        model = Game
        fields = ['name', 'description', 'platform', 'genre', 'price', 'stock']
        widgets = {
            'name': forms.TextInput(attrs={'class': 'form-control'}),
            'description': forms.Textarea(attrs={'class': 'form-control'}),
            'platform': forms.Textarea(attrs={'class': 'form-control'}),
            'genre': forms.Textarea(attrs={'class': 'form-control'}),
            'price': forms.NumberInput(attrs={'class': 'form-control'}),
            'stock': forms.NumberInput(attrs={'class': 'form-control'}),
        }

    def clean(self):
        data = self.cleaned_data
        name = data['name']
        description = data['description']
        platform = data['platform']
        genre = data['genre']
        price = data['price']
        stock = data['stock']
        game_exists = Game.objects.filter(name=name).exists()
        if game_exists:
            raise forms.ValidationError(f"The game {name} already exists in the database")
        return data
    
class GameEditForm(forms.ModelForm):
    class Meta:
        model = Game
        fields = ['name', 'description', 'platform', 'genre', 'price', 'stock']

    def clean(self):
        data = self.cleaned_data
        name = data['name']
        description = data['description']
        platform = data['platform']
        genre = data['genre']
        price = data['price']
        stock = data['stock']
        return data

class UserSignupForm(UserCreationForm):
    class Meta(UserCreationForm.Meta):
        model = User
        fields = ['email', 'password1', 'password2']

    @transaction.atomic
    def save(self):
        user = super().save(commit=False)
        user.is_admin = False
        user.email = self.cleaned_data['email']
        user.username = user.email
        user.save()
        return user


class UserLoginForm(AuthenticationForm):
    def __init__(self, *args, **kwargs):
        super(UserLoginForm, self).__init__(*args, **kwargs)
    

