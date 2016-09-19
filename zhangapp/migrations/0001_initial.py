# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import models, migrations


class Migration(migrations.Migration):

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='Number',
            fields=[
                ('id', models.AutoField(verbose_name='ID', serialize=False, auto_created=True, primary_key=True)),
                ('kind', models.CharField(max_length=500)),
                ('number', models.IntegerField(default=0)),
            ],
        ),
        migrations.CreateModel(
            name='Problem',
            fields=[
                ('id', models.AutoField(verbose_name='ID', serialize=False, auto_created=True, primary_key=True)),
                ('title', models.CharField(max_length=500)),
                ('auth', models.CharField(max_length=500)),
                ('beijing', models.TextField()),
                ('miaoshu', models.TextField()),
                ('in_gs', models.TextField()),
                ('out_gs', models.TextField()),
                ('inone', models.TextField()),
                ('outone', models.TextField()),
                ('intwo', models.TextField()),
                ('outtwo', models.TextField()),
                ('buchong', models.TextField()),
                ('put', models.IntegerField(default=0)),
                ('down', models.IntegerField(default=0)),
            ],
        ),
        migrations.CreateModel(
            name='Tags',
            fields=[
                ('id', models.AutoField(verbose_name='ID', serialize=False, auto_created=True, primary_key=True)),
                ('name', models.CharField(max_length=50)),
            ],
        ),
        migrations.CreateModel(
            name='wiki',
            fields=[
                ('id', models.AutoField(verbose_name='ID', serialize=False, auto_created=True, primary_key=True)),
            ],
        ),
        migrations.AddField(
            model_name='problem',
            name='tags',
            field=models.ManyToManyField(related_name='tag', to='zhangapp.Tags'),
        ),
    ]
