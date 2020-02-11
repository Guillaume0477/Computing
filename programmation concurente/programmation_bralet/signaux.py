# -*- coding: utf-8 -*-
"""
Created on Fri Jun  1 08:12:43 2018

@author: antoine.bralet
"""

import multiprocessing as mp
import os
import sys
import signal
import time

#global fin

#fin = True
#
def Arret(s,frame): 
    global fin
    print("Coucou")
    #fin = False
    sys.exit(0)
#
#signal.signal(signal.SIGINT,Arret)
#
#while fin : 
#    time.sleep(2)
#    print("Bijour")

#Exercice 4 
pid = os.fork()
if pid == 0 :
    signal.signal(signal.SIGINT,Arret)
    while True : 
        time.sleep(1)
        print("Bijour")
else : 
    for k in range(3):
        time.sleep(1)
        print("Ingride")
    
    print("Papa tue son fils")
    os.kill(pid, signal.SIGINT)
    os.wait()
    #os.execlp("kill","kill","-9", str(pid))