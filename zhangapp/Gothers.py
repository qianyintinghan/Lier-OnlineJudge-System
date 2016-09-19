# -*- coding:utf-8 -*-
import urllib
from PIL import Image, ImageFont, ImageDraw
import re
import jieba
import random
import time
from Gseting import colors

def make_avatar(username,addr):
    color = colors[random.randint(0,len(colors)-1)]
    image = Image.new('RGB',[100,100],color)
    avatar = ImageDraw.Draw(image)
    font = ImageFont.truetype("msyhbd.ttc",90)
    avatar.text([16, -12],username[0].upper(), font = font)
    image.save(addr)

"""
colors:
purple:    #9B26AF
           #6200EA
blue grey: #607D8B
    -900   #263238
grey:      #9E9E9E
    -900   #212121
brown:     #795548
deep orange#FF5722
    -A400  #DD2C00
TEAL:      #009688
BLUE:      #01579B
           #0D47A1
"""
