# -*- coding: utf-8 -*-
"""
Created on Mon May 29 15:54:31 2017

@author: mateo.lopez
"""

import multiprocessing as mp
import time


def rdv1():
    print("aaaaaaaa")
def rdv2():
    print("bbbbbbbb")
def rdv3():
    print("cccccccc")


def P1(sem1,sem2,sem3):
    print("P1 commence")
    time.sleep(2)
    print("P1 fini")
    sem1.release()
    sem1.release()
    sem2.acquire()
    sem3.acquire()
    
    rdv1()
    
def P2(sem1,sem2,sem3):
    print("P2 commence")
    
    time.sleep(3)
    print("P2 fini")
    sem2.release()
    sem2.release()
    sem1.acquire()
    sem3.acquire()
    
    rdv2()
    
def P3(sem1,sem2,sem3):
    print("P3 commence")
    
    time.sleep(1)
    print("P3 fini")
    sem3.release()
    sem3.release()
    sem1.acquire()
    sem2.acquire()
    
    rdv3()




sem1=mp.Semaphore(0)

sem2=mp.Semaphore(0)
sem3=mp.Semaphore(0)

p1=mp.Process(target=P1,args=(sem1,sem2,sem3))
p2=mp.Process(target=P2,args=(sem1,sem2,sem3))
p3=mp.Process(target=P3,args=(sem1,sem2,sem3))


p1.start()
p2.start()
p3.start()