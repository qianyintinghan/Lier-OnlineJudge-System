# -*- coding:utf-8 -*-
from __future__ import unicode_literals
from django.db import models
from django.contrib.auth.models import AbstractUser
from django.contrib.auth.models import User
from django.db.models.signals import post_save
# Create your models here.


class Tags(models.Model):
    name = models.CharField(max_length = 50)
    def __unicode__(self):
        return self.name

class Problem(models.Model):
    # Problems……
    title   = models.CharField(max_length = 500)
    auth    = models.IntegerField(default = 1)
    beijing = models.TextField()
    miaoshu = models.TextField()
    in_gs   = models.TextField()
    out_gs  = models.TextField()
    inone   = models.TextField()
    outone  = models.TextField()
    intwo   = models.TextField()
    outtwo  = models.TextField()
    buchong = models.TextField()
    put     = models.IntegerField(default = 0)
    down    = models.IntegerField(default = 0)
    #tag
    def __unicode__(self):
        return self.title

class Number(models.Model):
    kind   = models.CharField(max_length = 500)
    number = models.IntegerField(default = 0)
    def __unicode__(self):
        return self.kind

class ReData(models.Model):
    tid    = models.CharField(max_length = 50)
    token  = models.CharField(max_length = 50)
    def __unicode__(self):
        return self.tid

class match(object):
    name   = models.CharField(max_length = 50)
    begin  = models.TimeField()
    end    = models.TimeField()
