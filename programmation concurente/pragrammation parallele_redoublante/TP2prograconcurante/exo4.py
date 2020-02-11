# -*- coding: utf-8 -*-
"""
Created on Fri May 12 08:04:22 2017

@author: mateo.lopez
"""

import os, sys
import multiprocessing as mp


def who():
    os.execlp('who','who')
    
    
def ps():
    os.execlp('ps','ps')
    
    
def ls():
    os.execlp('ls','ls','-l')
    
liste=[who,ps,ls]
proc=[mp.Process(target=i) for i in liste]
for i in proc:
    i.start()

    i.join()
    