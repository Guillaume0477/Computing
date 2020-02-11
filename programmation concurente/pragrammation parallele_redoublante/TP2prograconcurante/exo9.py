# -*- coding: utf-8 -*-
"""
Created on Fri May 12 11:11:03 2017

@author: mateo.lopez
"""
import os,sys,time
N = 3
for i in range(N) :
    #__________debut des ajouts_________
    for n in range(3):
        pid=os.fork()
        if pid == 0:
            break
    # __________fin des ajouts__________ 
print ("Bonjour" )
os._exit(0)