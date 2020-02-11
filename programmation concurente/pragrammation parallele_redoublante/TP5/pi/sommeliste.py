# -*- coding: utf-8 -*-
"""
Created on Sat Jun 10 23:57:29 2017

@author: lpzma
"""
import time,sys
import multiprocessing as mp
from random import randint
from array import array




def sommeliste(liste):
    somme=0
    for i in range(len(liste)):
        somme = somme + liste[i]
    return somme
    


def sommepartiel(liste,somme,lock):
    s=0
    for i in range(len(liste)):
        s = s + liste[i]
        
    with lock:
        somme.value=somme.value+s
        
    sys.exit(0)
    
    

def main():
    
    mp.freeze_support()


    #Definition liste
    N=10000000
    liste=[]
    for i in range(N):
        liste.append(randint(0,9999))
    liste = array('i',liste)
   
    #Somme sans processus
    debut_temps=time.time()
    somme=sommeliste(liste)
    fin_temps = time.time()
    
    print"La somme de la liste est",somme,"."
    print"Calcul effectué sans processus en parallèle en ", int(round(fin_temps-debut_temps,3)*1000),"ms."
    
    
    
    nb_process=4
    #Somme avec processus
    
          #decoupage liste
    N=len(liste)
    n=N//nb_process
    reste=N%nb_process
    
    debut=0
    fin=n
    
    somme=mp.Value("d",0.0)
    lock=mp.Semaphore(1)
    #creation process
    process=[]
    for i in range(nb_process):
        if i == nb_process-1:
            fin = fin + reste
        process.append(mp.Process(target=sommepartiel,args=(liste[debut:fin],somme,lock) ))
        debut=fin
        fin=fin+n
           
    #Demarrage process       
    debut_temps=time.time()
    
    temp_start=0
    debut_start=time.time()
    for p in process:
        p.start()
    fin_start=time.time()
    
    print "Temps de demarrage de tout les processus" ,int(round(fin_start-debut_start,3)*1000),"ms."
    for p in process:
        p.join()      

    fin_temps=time.time()    
    
    
    print"La somme de la liste est",somme.value,"."
    print"Calcul effectué avec processus en parallèle en ", int(round(fin_temps-debut_temps,3)*1000),"ms."

if __name__ == "__main__":
    main()