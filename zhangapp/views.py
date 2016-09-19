# -*- coding:utf-8 -*-
from django.shortcuts import render
from .forms import LoginForm
from .forms import RegisForm
from .models import Problem
from .models import Number
from django.shortcuts import render_to_response,render,get_object_or_404
from django.http import HttpResponse, HttpResponseRedirect
from django.contrib.auth.models import Group, Permission
from django.contrib.auth.models import User
from django.contrib import auth
from django.contrib import messages
from django.template.context import RequestContext
from django.core.exceptions import ObjectDoesNotExist
from django.core.paginator import Paginator
from django.core.paginator import EmptyPage
from django.core.paginator import PageNotAnInteger
import os
import Gseting
import Gothers
import codecs

from PIL import Image
# Create your views here.

def index(request):
    quanxian = False
    if request.user.id in Gseting.SuperManeger:
        quanxian = True
    return render_to_response('index.html',RequestContext(request,{'qx':quanxian,}))

def login(request):
    auth.logout(request)
    if request.method == "GET":
        form = LoginForm()
        return render(request,'login.html')
    else:
        error = list()
        form = LoginForm(request.POST)
        if form.is_valid():
            username = request.POST.get('username').strip()
            password = request.POST.get('password').strip()
            if username == None:
                error.append('namenone')
            user = auth.authenticate(username=username, password=password)
            if user is not None and user.is_active:
                auth.login(request, user)
                return HttpResponseRedirect('/')
            else:
                error.append('Invalid')
                return render_to_response('login.html',RequestContext(request,{'error':error,}))
        else:
            error.append('novalid')
            return render_to_response('login.html', RequestContext(request, {'error':error,}))

def registered(request): # registered
    auth.logout(request)
    if request.method == "GET":
        form = RegisForm()
        return render_to_response('registered.html',RequestContext(request,{}))#render(request, 'registered.html')
    else:
        form = RegisForm(request.POST)
        if form.is_valid():
            email     = request.POST.get('email').strip()
            username  = request.POST.get('username').strip()
            password1 = request.POST.get('password1').strip()
            password2 = request.POST.get('password2').strip()
            #print email,username,password1
            error = list()
            sucess = True
            """
            if username in Gseting.noregistered:
                error.append('qnmlgb')
                sucess = False
                sucess = False
                sucess = False
            """
            if username.find('sb') >-1 or username.find('Gengxin') >-1 or username.find('syy') > -1 or username.find('fuck') > -1:
                error.append('qnmlgb')
                sucess = False
                sucess = False
                sucess = False
            if email != None:
                try:
                    User.objects.get(email=email)
                    error.append('email')# email error
                    sucess = False
                except ObjectDoesNotExist:
                    pass
            else:
                error.append('emailnone')
                sucess = False
            if username != None:
                try:
                    User.objects.get(username__exact=username)
                    error.append('name')
                    sucess = False
                except ObjectDoesNotExist:
                    pass
            else:
                error.append('namenone')
                sucess = False
            if password1 != None:
                if password1 != password2:
                    error.append('pass2')
                    sucess = False
            else:
                error.append('passnone')
                sucess = False

            if sucess:
                # No Problems
                # Create User
                try:
                    user = User.objects.create_user(username,email,password1)
                    user.save()
                    #print "teset"
                    Gothers.copy_avatar(user.id)#Gothers.make_avatar(user.username,'static/image/user-avatar/'+str(user.id)+".jpg")
                    #print "test"
                    user = auth.authenticate(username=username, password=password1)
                    auth.login(request, user)
                    return render_to_response('registered.html',RequestContext(request, {'success':True,}))
                except:
                    return render_to_response('registered.html',RequestContext(request, {'error':['wtf'],}))
            else:
                return render_to_response('registered.html',RequestContext(request, {'error':error,}))
        else:
            return render(request, 'registered.html')

def logout(request):
    auth.logout(request)
    return HttpResponseRedirect('/')

#def repassw(request):
#    if request.method == "GET":


def mine(request):
    return render_to_response('mine.html', RequestContext(request, {'other':False,}))

def userinfo(request, user_id):
    if not request.user.is_authenticated():
        return render_to_response('mine.html', RequestContext(request, {'other':True,'nologin':True,}))
    if user_id == None:
        return render_to_response('mine.html', RequestContext(request, {'other':True,'wantuser':request.user,}))
    else:
        try: #best to use filter
            user = User.objects.get(id = user_id)
            return render_to_response('mine.html', RequestContext(request, {'other':True,'wantuser':user,}))
        except:
            return render_to_response('mine.html', RequestContext(request, {'other':True,'none':True}))

def gmaneger(request):
    if request.user.id in Gseting.SuperManeger:
        userlist = User.objects.all()
        #userlist = list()
        #for user in ul:
        #    profile = user.get_profile()
        #    userlist.append([user.id, user.username, user.email, user.last_login, user.date_joined, user.is_superuser, ])
        return render_to_response('Gmanege.html', RequestContext(request, {'userlist':userlist,}))
    else:
        return render_to_response('Gmanege.html', RequestContext(request, {'nopurview':True,}))

def problemlist(request):
    raw_page = request.GET.get('page',1)
    try:
        page = int(raw_page)
    except:
        return HttpResponseRedirect('/problemlist/?page=1')
    page_count = (Number.objects.get(kind="Problem").number+1)/20+1
    if page > page_count or page < 1 :
        return HttpResponseRedirect('/problemlist/?page=1')
    pl = Problem.objects.all()[(page-1)*20:page*20]
    if page <= page_count:
        pnext = page
    else:
        pnext = page+1
    if page >= 1:
        pup = page
    else:
        pup = page-1
    return render_to_response('problemlist.html', RequestContext(request, {"pl":pl, 'activepage':page, 'pagerange':range(1,page_count+1),'pup':pup,'pnext':pnext,'page_count':page_count,}))

def problem(request):
    pid = request.GET.get('pid')
    if pid == None:
        return HttpResponseRedirect('/problemlist/?page=1')
    try:
        problem = Problem.objects.get(id = pid)
        t_auth = User.objects.filter(id = problem.auth)
        if t_auth:
            auth = t_auth[0]
        else:
            auth = None
        return render_to_response('problem.html', RequestContext(request, {'problem':problem,'auth':auth,}))
    except:
        return render_to_response('problem.html', RequestContext(request, {'none':True,}))
#莫名其妙
def newproblem(request):
    if not request.user.id in Gseting.SuperManeger:
        return render_to_response('newproblem.html', RequestContext(request, {'no':True,}))
    if request.method == "GET":
        return render_to_response('newproblem.html', RequestContext(request, {}))
    else:
        title   = request.POST.get('title').strip()
        auth    = request.user.id
        beijing = request.POST.get('beijing').strip()
        miaoshu = request.POST.get('miaoshu').strip()
        in_gs   = request.POST.get('in_gs').strip()
        out_gs  = request.POST.get('out_gs').strip()
        inone   = request.POST.get('inone')
        outone  = request.POST.get('outone')
        buchong = request.POST.get('buchong').strip()
        problem = Problem()
        problem.title = title
        problem.auth  = auth
        if beijing == "":
            problem.beijing = None
        else:
            problem.beijing = beijing
        problem.miaoshu = miaoshu
        problem.in_gs = in_gs
        problem.out_gs = out_gs
        problem.inone = inone
        problem.outone = outone
        problem.buchong = buchong
        problem.save()
        try:
            num = Number.objects.get(kind = "Problem")
            num.number += 1;
            num.save()
        except:
            num = Number(kind="Problem")
            num.number = 1
            num.save()
        return render_to_response('newproblem.html', RequestContext(request, {'sucess':problem.id}))

def reproblem(request):
    pid = request.GET.get('pid')
    if pid == None:
        return HttpResponseRedirect('/')
    else:
        if request.method == "GET":
            problem = Problem.objects.filter(id = pid)
            if problem:
                problem = problem[0]
                auth = User.objects.filter(id = problem.auth)[0]
                if not request.user.id in Gseting.SuperManeger:
                    if auth.id != request.user.id:
                        return render_to_response('reproblem.html', RequestContext(request,{'no':True}))
            else:
                return render_to_response('reproblem.html', RequestContext(request,{'no':True}))
            return render_to_response('reproblem.html', RequestContext(request, {'problem':problem}))
        else:
            problem = Problem.objects.filter(id = pid)
            if problem:
                problem = problem[0]
                auth = User.objects.filter(id = problem.auth)[0]
                if not auth.id in Gseting.SuperManeger:
                    if auth.id != request.user.id:
                        return render_to_response('reproblem.html', RequestContext(request,{'no':True}))
            else:
                return render_to_response('reproblem.html', RequestContext(request, {'no':True}))
            title   = request.POST.get('title').strip()
            beijing = request.POST.get('beijing').strip()
            miaoshu = request.POST.get('miaoshu').strip()
            in_gs   = request.POST.get('in_gs').strip()
            out_gs  = request.POST.get('out_gs').strip()
            inone   = request.POST.get('inone')
            outone  = request.POST.get('outone')
            buchong = request.POST.get('buchong').strip()
            problem.title = title
            if beijing == "":
                problem.beijing = None
            else:
                problem.beijing = beijing
            problem.miaoshu = miaoshu
            problem.in_gs = in_gs
            problem.out_gs = out_gs
            problem.inone = inone
            problem.outone = outone
            problem.buchong = buchong
            problem.save()
            return render_to_response('reproblem.html', RequestContext(request, {'sucess':problem.id}))

# glyphicon glyphicon-duplicate copy
def seting(request):
    if not request.user.is_authenticated():
        return HttpResponseRedirect('/')
    if request.method == "POST":
        try:
            reqfile = request.FILES.get("avatar")
            if not reqfile:
                print "funny"
                render_to_response('seting.html',RequestContext(request, {'OK':False}))
            tempname = 'static/image/temp/'+str(request.user.id)+reqfile.name
            print tempname
            destination = open(tempname, 'wb+')
            for chunk in reqfile.chunks():
                destination.write(chunk)
            destination.close()
            img = Image.open(tempname)
            img.thumbnail((250,250),Image.ANTIALIAS)
            img.save("static/image/user-avatar/"+str(request.user.id)+".jpg")
            return render_to_response('seting.html',RequestContext(request,{'OK':True}))
        except:
            print "wtf"
            return render_to_response('seting.html',RequestContext(request,{'OK':False}))
    return render_to_response('seting.html',RequestContext(request,{'new':True}))

def repassword(request):

    pass

def post(request):
    if not request.user.is_authenticated():
        return HttpResponseRedirect('/')
    pid = request.GET.get('pid')
    if pid == None or int(pid) > Number.objects.get(kind="Problem").number:
        return HttpResponseRedirect('/')
    problem = Problem.objects.get(id = pid)
    if request.method == "GET":
        return render_to_response('post.html', RequestContext(request, {'problem':problem}))
    if request.method == "POST":
        uid = request.user.id
        if not os.path.isdir("post/"+str(pid)):
            os.mkdir("post/"+str(pid))
        f = codecs.open("post/"+str(pid)+"/"+str(uid)+".cpp","wb",'gb2312')
        f.write(request.POST.get("code"))
        f.close()
        problem.put+=1
        problem.save()
        return render_to_response('post.html', RequestContext(request, {'success':True,'pid':pid}))
