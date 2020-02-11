# -*- coding: utf-8 -*-
"""
Created on Fri Jun  1 11:53:36 2018

@author: antoine.bralet
"""

import multiprocessing as mp
import sys
import os
import time 
import random

patates = mp.Semaphore(0)
fromage = mp.Semaphore(0)
menage = mp.Semaphore(0)

def rdv1():
    print("Je suis la ca y est")
    fromage.release()
    menage.release()
    patates.acquire()
    patates.acquire()
    print("Il faut que j'aille chercher des patates pour la raclette")
    time.sleep(4)
    
def rdv2(): 
    print("Je suis la ca y est")
    patates.release()
    menage.release()
    fromage.acquire()
    fromage.acquire()
    print("Moi je vais chercher le fromage et c'est partit")
    time.sleep(2)
   
def rdv3(): 
    print("Je suis la ca y est")
    fromage.release()
    patates.release()
    menage.acquire()
    menage.acquire()
    print("Moi je vais chercher le fromage et c'est partit")
    time.sleep(3)

def fonc1() : 
    print("Vite au supermarche pour la raclette de ce soir il manque la charcuterie")
    time.sleep(3)
    print("c'est bon la charcuterie est la")
    rdv1()
    print("On va se peter le bide ce soir")

def fonc2():
    print("ou est ce que j'ai range l'appareil a raclette ?")
    time.sleep(1)
    print("Nickel le voila")
    rdv2()
    print("Je suis sur que Duret sera encore saoul")
    
def fonc3():
    print("Trop de menage a faire pour ce soir")
    time.sleep(1)
    print("Bon il ne reste plus que l'aspirateur a passer")
    rdv3()
    print("Je vous previens, personne ne degueule sur mon tapis")

P1 = mp.Process(target = fonc1, args = ())
P2 = mp.Process(target = fonc2, args = ())
P3 = mp.Process(target = fonc3, args = ())

P1.start()
P2.start()
P3.start()