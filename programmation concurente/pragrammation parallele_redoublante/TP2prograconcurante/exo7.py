# -*- coding: utf-8 -*-
"""
Created on Fri May 12 10:23:24 2017

@author: mateo.lopez
"""

import os,sys,time

N = sys.argv[1]

for i in range(int(N)):
    pid = os.fork()
    if pid == 0:
        time.sleep(2*i)
        print("fils",os.getpid()," pere", os.getppid())
        sys.exit(i)
        
for i in range(int(N)):    
    etat = os.wait()
    print(etat)