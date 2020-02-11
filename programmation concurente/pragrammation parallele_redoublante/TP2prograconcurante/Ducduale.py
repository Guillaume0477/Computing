# -*- coding: utf-8 -*-
"""
Created on Thu May  4 10:34:38 2017

@author: mateo.lopez
"""
import os

for i in range(3):
    id=os.fork()
    print (i," je suis le processus :",os.getpid(), "mon père est ",os.getppid())
    
