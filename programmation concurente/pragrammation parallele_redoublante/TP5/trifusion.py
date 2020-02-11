# -*- coding: utf-8 -*-
"""
Created on Mon Jun 12 14:38:08 2017

@author: mateo.lopez Matthieu Couriol

"""
import multiprocessing as mp
import time,sys,random
from array import array
import SharedArray as sa

def insert(liste,obj,here):
    c = liste[obj]    
    for i in range(obj,here,-1):
        liste[i]=liste[i-1]
    liste[here]=c
        

def merge(liste,dl1,fl1,dl2,fl2):
    
    if dl1==fl1 and dl2==fl2:
        #print(dl1,dl2)
        if liste[dl1] > liste[dl2]:
            liste[dl1],liste[dl2]=liste[dl2],liste[dl1]
            
        else:
            pass
        return
            
    if dl1==fl1:
        for i in range(dl2,fl2+1):
            if liste[dl1] > liste[i]:
                liste[dl1],liste[i]=liste[i],liste[dl1]
                
            else:
                pass
        return
                
    if dl2==fl2:
        for i in range(dl1,fl1+1):
            if liste[i] > liste[dl2]:
                liste[i],liste[dl2]=liste[dl2],liste[i]
                
            else:
                pass
        return
    else:
        c=0
        for i in range(dl2,fl2+1):
            for j in range(dl1,fl1+1+c):
                if liste[i]<liste[j]:
                    
                    dl1=j
                    c+=1
                    insert(liste,i,j)
        return
            
    return
    

def trisurplace(liste,debut,fin):
    taille=fin-debut+1
    if taille <=1:
        return
        
    dl2=taille//2 +debut
    fl2=fin  
    dl1=debut
    fl1=dl2-1
    
    trisurplace(liste,dl1,fl1)
    trisurplace(liste,dl2,fl2)
    return merge(liste,dl1,fl1,dl2,fl2)

def trisurplacemulti(liste,debut,fin,verrou):
    taille=fin-debut+1
    if taille <=1:
        return
        
    dl2=taille//2 +debut
    fl2=fin  
    dl1=debut
    fl1=dl2-1
    
    
    p=mp.Process(target=trisurplacemulti,args=(liste,dl2,fl2))
    p.start()
    trisurplacemulti(liste,dl1,fl1)
    p.join()
    
    merge(liste,dl1,fl1,dl2,fl2)
    
    return


N=10
nb_process = 8


l =[]
for i in range(N):
    l.append(random.randint(0,999))

liste=array('i',l)

#print (liste)
t0=time.time()
trisurplace(liste,0,N-1)
t1=time.time()
#print(liste)
print(t1-t0)



liste2=sa.create("shm://liste2",l)

liste1=mp.Array('i',l)

#print(liste1[:])
t0=time.time()
trisurplacemulti(liste1,0,N-1)
t1=time.time()
print(liste2[:])
print(t1-t0)
