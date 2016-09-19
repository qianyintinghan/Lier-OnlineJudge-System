# -*- coding:utf-8 -*-
from django import forms
from django.contrib.auth.models import User


class LoginForm(forms.Form):
    username = forms.CharField()
    password = forms.CharField()

class RegisForm(forms.Form):
    email     = forms.EmailField()
    username  = forms.CharField()
    password1 = forms.CharField()
    password2 = forms.CharField()

class RePasswyan(forms.Form):
    email     = forms.EmailField()

class RePassw(forms.Form):
    raw_password = forms.CharField(max_length = 50)
