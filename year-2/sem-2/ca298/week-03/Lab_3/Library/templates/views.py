from django.http import HttpResponse
from django.shortcuts import render
from .models import *
from django.shortcuts import get_object_or_404
from django.shortcuts import get_list_or_404


def index(request):
    return render(request, 'index.html')


def view_all_books(request):
    all_books = Book.objects.all()
    return render(request, 'all_books.html', {'books': all_books})


def view_single_book(request, bookid):
    single_book = get_object_or_404(Book, id=bookid)
    return render(request, 'single_book.html', {'book': single_book})


def view_books_by_year(request, year):
    books_by_year = get_list_or_404(Book, year=year)
    return render(request, 'books_by_year.html', {'books': books_by_year, 'year': year})


def view_books_by_catergory(request, category):
    books_by_category = get_list_or_404(Book, category=category)
    return render(request, 'books_by_category.html', {'books': books_by_category, 'category': category})


def view_books_by_year_and_category(request, year, category):
    books_by_year_and_category = get_list_or_404(
        Book, category=category, year=year)
    return render(request, 'books_by_year_and_category.html', {'books': books_by_year_and_category, 'category': category, 'year': year})
