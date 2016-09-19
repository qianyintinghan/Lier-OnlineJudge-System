# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import models, migrations


class Migration(migrations.Migration):

    dependencies = [
        ('zhangapp', '0002_auto_20160909_1810'),
    ]

    operations = [
        migrations.AlterField(
            model_name='problem',
            name='auth',
            field=models.IntegerField(default=1),
        ),
    ]
