# -*- coding: utf-8 -*-
"""
Created on Fri Jun  1 11:09:43 2018

@author: antoine.bralet
"""
import multiprocessing as mp
import sys
import os
import time 

assiette = mp.Semaphore(0)

def Travail1():
    print("J'ai faim")
    miam = 0
    mange = 0
    while miam == 0 : 
        time.sleep(1)
        mange += 1
        print("Je suis a ", mange, "assiettes salies")
        if mange == 3 : 
            miam = 1
    print ("J'ai bien mange")
    assiette.release()
    time.sleep(7)
    print("Quand est ce qu'on mange ?")
    

def Travail2():
    print("Quand puis je faire la vaisselle ?")
    assiette.acquire()
    print("C'est pas trop tot !")
    laver = 3
    while laver != 0 :
        time.sleep(3)
        print ("Encore ", laver, "assiettes a laver")
        laver -= 1
    print("Punaise ceci m'a epuise, je vais peut etre manger un bout")

P1 = mp.Process(target = Travail1, args=())
P2 = mp.Process(target = Travail2, args=())

P1.start()
P2.start()
        