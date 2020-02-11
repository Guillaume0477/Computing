# -*- coding: utf-8 -*-
"""
Created on Thu May  4 09:18:38 2017

@author: mateo.lopez
"""

import os

a=7
b=20
c=15
id=os.fork()
if id==0:
    os.execlp("python3.4","python3.4","moyenne.py",str(a),str(b),str(c))
else:
    os.execlp("python3.4","python3.4","moyenne.py",str(a),str(b))
    