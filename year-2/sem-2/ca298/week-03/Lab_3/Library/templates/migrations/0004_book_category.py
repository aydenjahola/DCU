# Generated by Django 4.2.7 on 2024-01-29 12:26

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('templates', '0003_alter_book_synopsis'),
    ]

    operations = [
        migrations.AddField(
            model_name='book',
            name='category',
            field=models.CharField(default='General', max_length=25),
        ),
    ]