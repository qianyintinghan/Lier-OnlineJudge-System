from django.conf.urls import include, url
from django.contrib import admin
from zhangapp import views

urlpatterns = [
    # Examples:
    # url(r'^$', 'lieroj.views.home', name='home'),
    # url(r'^blog/', include('blog.urls')),

    url(r'^admin/', include(admin.site.urls)),
    url(r'^$', views.index),
    url(r'^login/', views.login),
    url(r'^registered/', views.registered),
    url(r'^logout/', views.logout),
    url(r'^mine/', views.mine),
    url(r'^user/(?P<user_id>[a-z0-9]+)/', views.userinfo),
    url(r'^gmaneger/', views.gmaneger),
    url(r'^problemlist/', views.problemlist),
    url(r'^problem/', views.problem),
    url(r'^post/', views.post),
    url(r'^newproblem/', views.newproblem),
    url(r'^reproblem/', views.reproblem),
    url(r'^seting/', views.seting)
]
