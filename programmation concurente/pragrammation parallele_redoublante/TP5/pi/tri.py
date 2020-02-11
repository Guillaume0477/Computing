# -*- coding: utf-8 -*-
"""
Created on Sun Jun 11 16:32:31 2017

@author: lpzma
"""

import math, random
import numpy as np
from numpy import array
import time
import multiprocessing as mp

def merge (T,left, right):
    tableau = array([])#tableau vide qui reçoit les résultats
    while len(left)>0 and len(right)>0:
        if left[0] < right[0] : 
            print left
            np.append(tableau,left[0])
            np.delete(left,[0])
            print left
        else: 
            np.append(tableau,right[0])
            np.delete(right,[0])
    
    T = np.concatenate(tableau,left,right)
    return 
    
def merge_sort (Tableau) :
    length_Tableau = len(Tableau)
    if length_Tableau <= 1: return Tableau
    mid = length_Tableau//2
    merge_sort(Tableau[0:mid])
    merge_sort(Tableau[mid:])
    merge(Tableau,Tableau[0:mid],Tableau[mid:])
    print Tableau
    return
    
    
def test(tab,debut,fin):
    print tab[debut:fin]
    tab[debut:fin][0]=1515
    print tab[0]
    return
    
def version_multi_proc(N,tab,nb_process):
    print"Avant : ",tab
    n=int(N/nb_process)
    reste=N-n*nb_process
    
    debut=0
    fin=n
    
    #creation process
    process=[]
    for i in range(nb_process):
        if i == nb_process-1:
            fin = fin + reste
        process.append(mp.Process(target=test,args=(tab,debut,fin) ))
        debut=fin
        fin=fin+n
           
    #Demarrage process       
    for p in process:
        p.start()
    for p in process:
        p.join()    
    
  
    print"Après : ",tab
    


def main():
    mp.freeze_support()
    
    #sans processus parallele
    N=10
    nb_process=4
    Tab = array([random.randint(0,2*N)for _ in range(N)])
   # version_de_base(N,Tab)
    version_multi_proc(N,Tab,nb_process)
    
    #

if __name__ == "__main__":
    main()
    