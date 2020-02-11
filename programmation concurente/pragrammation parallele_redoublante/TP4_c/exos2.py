# -*- coding: utf-8 -*-
"""
Created on Mon May 29 14:11:55 2017

@author: mateo.lopez
"""
import multiprocessing as mp
import random, time, sys


def B(semB,semE):
    print("B: attend A" )
    time.sleep(4)
    
    semB.acquire()
    
    print ("fin processus B")
    semE.release()

def C(semC,semE):
    print("C: attend A" )
    time.sleep(4)
    semC.acquire()
    
    print ("fin processus C")
    semE.release()
    
def D(semD,semF):
    print("D: attend A" )
    time.sleep(3)
    semD.acquire()
    
    print ("fin processus D")
    semF.release()
    
def E(semE,semF):
    print("E: attend B et C" )
    time.sleep(1)
    semE.acquire()
    print("E:1 jeton")
    semE.acquire()
    
    print ("fin processus E")
    semF.release()
    
def F(semE):
    print("F: attend E et D" )
    semF.acquire()
    print("F:1 jeton")
    semF.acquire()
    
    print ("fin processus F")
    
    
    
    
    





semB=mp.Semaphore(0)
semC=mp.Semaphore(0)
semD=mp.Semaphore(0)
semE=mp.Semaphore(0)
semF=mp.Semaphore(0)

ProcessB=mp.Process(target=B, args=(semB,semE))
ProcessC=mp.Process(target=C, args=(semC,semE))
ProcessD=mp.Process(target=D, args=(semD,semF))
ProcessE=mp.Process(target=E, args=(semE,semF))
ProcessF=mp.Process(target=F, args=(semE,))

ProcessB.start()
ProcessC.start()
ProcessD.start()
ProcessE.start()
ProcessF.start()

time.sleep(5)
print ("fin processus A")



semB.release()
semC.release()
semD.release()