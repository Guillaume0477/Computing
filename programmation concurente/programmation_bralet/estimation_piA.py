# -*- coding: utf-8 -*-
"""
Created on Fri Jun  8 09:21:29 2018

@author: antoine.bralet

Group : A
Authors : METEYER Paul & BRALET Antoine
Date : 08/06/2018
Content: Estimation de pi par un cercle unitaire (méthode de Monte-Carlo)
"""

import time
import os
import multiprocessing as mp
import sys
import random
from math import *

# calculer le nbr de hits dans un cercle unitaire (utilisé par les différentes méthodes)
def calcul_MonoProcessus(nb_iteration):
    count = 0
    for i in range(nb_iteration):
        x = random.random()
        y = random.random()
        # si le point est dans l’unit circle
        if x*x + y*y <= 1: 
            count += 1
    return count

def calcul_PluriProcessus(nb_iteration):
    count = 0
    for i in range(nb_iteration):
        x = random.random()
        y = random.random()
        # si le point est dans l’unit circle
        if x*x + y*y <= 1: 
            count += 1
    Sem.acquire()
    count_protect.value+=count
    Sem.release()

def calcul_Variante_PluriProcessus(nb_iteration,quartx,quarty):
    count = 0
    for i in range(nb_iteration):
        x = quartx*random.random()
        y = quarty*random.random()
        # si le point est dans l’unit circle
        if x*x + y*y <= 1: 
            count += 1
    Sem.acquire()
    pifin.value+=count
    Sem.release()

# Nombre d’essaipour l’estimation
nb_total_iteration = 10000001
td = time.time()
nb_hits=calcul_MonoProcessus(nb_total_iteration)
tf = time.time()
print("Valeur estimée Pi par la méthode Mono−Processus : ", 4*nb_hits / nb_total_iteration, "et j'ai mis ", tf-td,"secondes")


#Methode Pluri-Process
Sem = mp.Lock()
count_protect = mp.Value('i',0)
nb_proc = 10
liste_pid = []
td2 = time.time()
for k in range(1,nb_proc): 
    liste_pid.append(mp.Process(target = calcul_PluriProcessus,args = (floor(nb_total_iteration/nb_proc),)))
    liste_pid[-1].start()

liste_pid.append(mp.Process(target = calcul_PluriProcessus, args = (nb_total_iteration- floor((nb_total_iteration*(nb_proc-1)/nb_proc)),)))
liste_pid[-1].start()

for k in liste_pid:
    k.join()

tf2 = time.time()

print("Valeur estimée Pi par la méthode Pluri−Processus : ", 4*count_protect.value / nb_total_iteration, "et j'ai mis ", tf2-td2,"secondes")


#Methode variante : un process/quart

Semv = mp.Lock()
pifin = mp.Value('i',0)
td3 = time.time()
pid1 = mp.Process(target = calcul_Variante_PluriProcessus, args = (nb_total_iteration,1,1))
pid2 = mp.Process(target = calcul_Variante_PluriProcessus, args = (nb_total_iteration,-1,1))
pid3 = mp.Process(target = calcul_Variante_PluriProcessus, args = (nb_total_iteration,-1,-1))
pid4 = mp.Process(target = calcul_Variante_PluriProcessus, args = (nb_total_iteration,1,-1))

pid1.start()
pid2.start()
pid3.start()
pid4.start()

pid1.join()
pid2.join()
pid3.join()
pid4.join()

tf3 = time.time()
print("Valeur estimée Pi par la méthode variante Pluri−Processus : ", pifin.value / (nb_total_iteration), "et j'ai mis ", tf3-td3,"secondes")
























