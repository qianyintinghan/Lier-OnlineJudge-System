# -*- coding:utf-8 -*-
from celery import task
from urllib import urlopen
import re

@task()
def add(x,y):
    return x+y

def get_html(url):
    return urlopen(url).read()

def rep(html, r):
    rr = re.compile(r,re.S)
    html = re.findall(rr,html)
    return html

def get_weather():
    url = "https://weather.com/zh-CN/weather/today/l/36.67,117.00"
    r = r'<div class=\"today_nowcard-section today_nowcard-condition\">.+?<div class=\"today_nowcard-temp\">,+?<span data-ng-if=\"hasValue\" class.+?>(.+?)</span>'
    html = rep(get_html(url),r)
    print html

get_weather()


"""
    <div class="today_nowcard-section today_nowcard-condition">
            <div class="condition-icon wx-weather-icon vector" data-ng-style="{&quot;background-color&quot;:&quot;rgba(255, 255, 255, 0.2)&quot;}" data-vector-optimized="true" data-wxicon="" data-sky-code="::todayWxcardVm.obs.icon" aria-hidden="true" alt="mostly cloudy-night"><div class="svg-icon"><!-- ngInclude: undefined --><ng-include src="getIconUrl('vector', true)"><svg xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" viewBox="0 0 200 200" class="svg-mostly-cloudy-night svg-night">
  <defs>
    <mask id="svg-cloud-mask-mostly-cloudy-night">
      <rect x="0" y="0" width="100%" height="100%" fill="#FFF"></rect>
      <use xlink:href="/sites/all/modules/custom/angularmods/app/shared/wxicon/svgz/symbols.svgz#svg-cloud" transform="scale(0.55128) translate(59, -27) " fill="#000" stroke-width="10" stroke="#000"></use>
    </mask>
  </defs>
  <path class="svg-cloud" d="M197.4,81.1c-2.4-8.8-11.3-14-20.1-11.7c0,0-0.6,0.2-1.8,0.5c-2.8-10.4-12.3-18.1-23.6-18.1 c-7.5,0-14.1,3.4-18.6,8.7c3.2,3.7,5.8,7.9,7.9,12.4c1.6-0.2,3.3-0.3,5-0.3c16.9,0,31.8,11.4,36.2,27.8c0.1,0.5,0.2,1,0.3,1.5 c1-0.1,2.2-0.2,3-0.4C194.6,99,199.8,89.9,197.4,81.1z"></path>
  <use class="svg-moon" xlink:href="/sites/all/modules/custom/angularmods/app/shared/wxicon/svgz/symbols.svgz#svg-moon" transform="scale(1.56) translate(-28, 17)" mask="url(#svg-cloud-mask-mostly-cloudy-night)"></use>
  <use class="svg-cloud" xlink:href="/sites/all/modules/custom/angularmods/app/shared/wxicon/svgz/symbols.svgz#svg-cloud" transform="scale(0.86) translate(8, 4)"></use>
</svg>
</ng-include></div></div>
            <div class="today_nowcard-temp">
                <span data-gm-wx-temperature="::todayWxcardVm.obs.temperature" data-text-to-replace="23"><!-- ngIf: tempPrefix --> <!-- ngIf: hasValue --><span data-ng-if="hasValue" class="dir-ltr" data-ng-bind="temp | safeDisplay">23</span><!-- end ngIf: hasValue --><!-- ngIf: hasValue --><sup data-ng-if="hasValue" class="deg dir-ltr">°</sup><!-- end ngIf: hasValue --><!-- ngIf: showTempUnit -->
<!-- ngIf: !hasValue --></span>
            </div>
            <div class="today_nowcard-phrase" data-ng-bind="::todayWxcardVm.obs.phrase">大部多雲</div>
            <div class="today_nowcard-feels">
                <span class="btn-text" data-ng-bind="::'feels like' | pfTranslate: {context: 'today_nowcard'}">体感温度</span>
                <span class="deg-feels" data-gm-wx-temperature="::todayWxcardVm.obs.feelsLike" data-text-to-replace="23"><!-- ngIf: tempPrefix --> <!-- ngIf: hasValue --><span data-ng-if="hasValue" class="dir-ltr" data-ng-bind="temp | safeDisplay">23</span><!-- end ngIf: hasValue --><!-- ngIf: hasValue --><sup data-ng-if="hasValue" class="deg dir-ltr">°</sup><!-- end ngIf: hasValue --><!-- ngIf: showTempUnit -->
<!-- ngIf: !hasValue --></span>
            </div>
            <div class="today_nowcard-hilo">
                <span class="btn-text" data-ng-bind="::'H' | pfTranslate: {context: 'today_nowcard'}">高温</span>
                <span class="deg-hilo-nowcard" data-gm-wx-temperature="::todayWxcardVm.forecast.items[0].day.daytemp" data-text-to-replace=""><!-- ngIf: tempPrefix --> <!-- ngIf: hasValue --><!-- ngIf: hasValue --><!-- ngIf: showTempUnit -->
<!-- ngIf: !hasValue --><span data-ng-if="!hasValue" data-ng-bind="text | safeDisplay">-</span><!-- end ngIf: !hasValue --></span>
                <!-- ngIf: ::todayWxcardVm.forecast.items[0].day.daytemp -->
                <span class="btn-text" data-ng-bind="::'L' | pfTranslate: {context: 'today_nowcard'}">低温</span>
                <span class="deg-hilo-nowcard" data-gm-wx-temperature="::todayWxcardVm.forecast.items[0].day.nighttemp" data-text-to-replace="18"><!-- ngIf: tempPrefix --> <!-- ngIf: hasValue --><span data-ng-if="hasValue" class="dir-ltr" data-ng-bind="temp | safeDisplay">18</span><!-- end ngIf: hasValue --><!-- ngIf: hasValue --><sup data-ng-if="hasValue" class="deg dir-ltr">°</sup><!-- end ngIf: hasValue --><!-- ngIf: showTempUnit -->
<!-- ngIf: !hasValue --></span>
                <div>
                    <span class="btn-text" data-ng-bind="::('UV Index' | pfTranslate: { context: 'weather_terms'})">紫外线指数</span>
                    <span data-ng-bind="output() | safeDisplay" data-gm-wx-uv-index="::todayWxcardVm.obs.uvIndex">0（最大值10）</span>
                </div>
            </div>
        </div>
    """
