# -*- coding: utf-8 -*-
"""
Created on Mon May 15 14:10:19 2017

@author: mateo.lopez
"""

import os,sys,time
import multiprocessing as mp


def cat(dfw):
    
    os.dup2(dfw,1)
    #os.close()
    os.execlp("cat","cat","exo1.py")

(dfr,dfw) = os.pipe()

p=mp.Process(target=cat,args=(dfw,))

p.start()
os.close(dfw)

os.dup2(dfr,0)


os.execlp("wc","wc") 