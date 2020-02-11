# -*- coding: utf-8 -*-
"""
Created on Sun Jun 11 11:14:10 2017

@author: lpzma
"""

import random , time
import multiprocessing as mp
import numpy as np
# calculer le nbr de hits dans un cercle unitaire ( utilisé par les différentes méthodes )

def calcul_MultiProcessus_1(nb_iteration,nb_hits,verrou) :
    count = 0
    for i in range(nb_iteration):
        x = random.random()
        y = random.random()
        # si le point est dans l ’ unit circle
        if x*x + y*y <= 1: 
            count += 1
    with verrou:
        nb_hits.value+=count
    return

def calcul_MultiProcessus_2(nb_iteration,total,verrou) :
    count = 0
    for i in range(nb_iteration):
        x = random.random()
        y = random.random()
        # si le point est dans l ’ unit circle
        if x*x + y*y <= 1: 
            count += 1
    with verrou:
        total.value+=count
    return
def calcul_MultiProcessus_3(nb_iteration,q) :
    count = 0
    for i in range(nb_iteration):
        x = random.random()
        y = random.random()
        # si le point est dans l ’ unit circle
        if x*x + y*y <= 1: 
            count += 1
    q.put(count)
    return

def calcul_MonoProcessus(nb_iteration) :
    count = 0
    for i in range(nb_iteration):
        x = random.random()
        y = random.random()
        # si le point est dans l ’ unit circle
        if x*x + y*y <= 1: 
            count += 1
    return count
    
    
def main():    
    mp.freeze_support()    
        
    # Nombre d’essai pour l’estimation
    nb_total_iteration = 10000000
    nb_process=20
    
    
    #calcul monoprocessus
    debut=time.time()
    nb_hits=calcul_MonoProcessus(nb_total_iteration)
    print "Valeur estimée Pi par la méthode Mono−Processus : " , 4 *float(nb_hits)/float(nb_total_iteration)
    fin=time.time()
    
    print "Calculé en ",round(fin-debut,3)*1000,"ms"
    
    
    
    # Calcul par processus mathode 1 n=N/K
    iteration_par_process=int(nb_total_iteration /nb_process)
    reste = nb_total_iteration-iteration_par_process*nb_process
    
    verrou=mp.Semaphore(1)
    nb_hits=mp.Value("i",0)
    
    process=[]
    for i in range(nb_process):
        if i == nb_process-1:
            iteration_par_process += reste        
        process.append(mp.Process(target=calcul_MultiProcessus_1,args=(iteration_par_process,nb_hits,verrou)))
            
    debut=time.time()
    for p in process:
        p.start()
    for p in process:
        p.join()
    print "Valeur estimée Pi par la méthode Multi−Processus 'iteration repartie': " , 4 *float(nb_hits.value)/float(nb_total_iteration)
    fin=time.time()
    print "Calculé en ",round(fin-debut,3)*1000,"ms avec",nb_process,"processus."
    
    
    
    
    # Calcul par processus mathode 2 chacun son quart   
    total=mp.Value("i",0)
    verrou=mp.Semaphore(1)
    
    process=[]
    for i in range(4):
        process.append(mp.Process(target=calcul_MultiProcessus_2,args=(nb_total_iteration,total,verrou)))

    debut=time.time()
    for p in process:
        p.start()
    for p in process:
        p.join()

    print "Valeur estimée Pi par la méthode Multi−Processus 'chacun son quart': " , float(total.value)/float(nb_total_iteration)
    fin=time.time()
    print "Calculé en ",round(fin-debut,3)*1000,"ms avec 4 processus."
          
    
    
    
    # Calcul par processus mathode 3 moyennage   
    q=mp.Queue()
    
    process=[]
    for i in range(nb_process):
        process.append(mp.Process(target=calcul_MultiProcessus_3,args=(nb_total_iteration,q)))

    total = 0   
    debut=time.time()
    for p in process:
        p.start()
    for p in process:
        p.join()
        total+=q.get()
    moyenne = float(total)/nb_process
    print "Valeur estimée Pi par la méthode Multi−Processus 'moyennage': " , 4*moyenne/float(nb_total_iteration)
    fin=time.time()
    print "Calculé en ",round(fin-debut,3)*1000,"ms avec",nb_process,"processus."
        
if __name__ == '__main__':
    main()
