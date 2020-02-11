# -*- coding: utf-8 -*-
"""
Created on Fri May 18 10:27:32 2018

@author: antoine.bralet
"""

import os
import sys
import multiprocessing as mp
import random
import time

#Exercice 1 

#dfr,dfw = multiprocessing.Pipe()
#if os.fork() == 0 :
#    n = 9
#    dfr.close()
#    dfw.send(n)
#    os._exit(0)
#else :
#    dfw.close()
#    n = dfr.recv()
#    print("la valeur de n donnee par le fils est : ", n)

#Exercice 2

#Fichier = sys.argv[1]
#dfr,dfw = multiprocessing.Pipe()
#if os.fork() == 0 : 
#    dfr.close()
#    os.dup2(dfw.fileno(),sys.stdout.fileno())
#    dfw.close()
#    os.execlp("cat","cat", Fichier)
#else : 
#    dfw.close()
#    os.dup2(dfr.fileno(),sys.stdin.fileno())
#    dfr.close()
#    os.execlp("wc","wc","-l")
#sys.exit(0)

#
#dfwsortie = open(sys.argv[2],"w")
#commands = [["sort"],["grep", "chaine"],["tail","-n","5"]]
#(dfr1,dfw1) = multiprocessing.Pipe()
#(dfr2,dfw2) = multiprocessing.Pipe()
#
#if os.fork() == 0 :
#    dfrentree = open(sys.argv[1], "r")
#    os.dup2(dfrentree.fileno(),sys.stdin.fileno())
#    dfrentree.close()
#    dfr1.close()
#    os.dup2(dfw1.fileno(),sys.stdout.fileno())
#    dfw1.close()
#    os.execvp(commands[0][0],commands[0])
#
#if os.fork()==0 :
#    os.dup2(dfr1.fileno(),sys.stdin.fileno())
#    dfr1.close()
#    os.dup2(dfw2.fileno(),sys.stdout.fileno())
#    dfw2.close()
#    os.execvp(commands[1][0],commands[1])
#    
#os.dup2(dfr2.fileno(),sys.stdin.fileno())
#dfr2.close()
#os.dup2(dfwsortie.fileno(),sys.stdout.fileno())
#dfw2.close()
#os.execvp(commands[-1][0],commands[-1])

#Exercice 3

dfrnp,dfwnp = mp.Pipe()
dfrni,dfwni = mp.Pipe()
dfrsp,dfwsp = mp.Pipe()
dfrsi,dfwsi = mp.Pipe()
N = int(sys.argv[1])
#
#def somme(d,o):
#    nombre = int(d.recv())
#    Sp = 0
#    while nombre != -1 :
#        Sp += nombre
#        nombre = int(d.recv())
#    print(Sp)
#    o.send(Sp)
#
def gener(N) :
    for k in range(N) : 
            nombre = random.randint(1,10)
            print(nombre)
            if nombre%2 == 0 : 
                dfwnp.send(nombre)
            else : 
                dfwni.send(nombre)
    dfwnp.send(-1)
    dfwni.send(-1)
    dfwnp.close()
    dfwni.close()
#        
#        
#if os.fork() == 0 :
#    somme(dfrnp,dfwsp)
#
#elif os.fork() == 0 :
#    time.sleep(2)
#    somme(dfrni,dfwsi)
#else :  
#    gener(N)
#    Stot = int(dfrsp.recv())+int(dfrsi.recv())
#    print(Stot)
 

if os.fork() == 0 :
    
    dfrni.close()
    dfwni.close()
    dfwnp.close()
    dfrsp.close()
    dfwsi.close()
    dfrsi.close()
    
    os.dup2(dfrnp.fileno(),sys.stdin.fileno())
    dfrnp.close()
    os.dup2(dfwsp.fileno(),sys.stdout.fileno())
    dfrsp.close()
    
    os.execlp("python3","python3","Somme.py")
    
dfwnp.send("10")
#os.write(dfwnp.fileno(), b"10\n")
#os.write(dfwnp.fileno(), b"10\n")
dfwnp.close()

print("result", os.read(dfrsp.fileno(), 10))

#elif os.fork() == 0 :
#    
#    dfrnp.close()
#    dfwni.close()
#    dfwnp.close()
#    dfrsp.close()
#    dfwsp.close()
#    dfrsi.close()
#    
#    os.dup2(dfrni.fileno(),sys.stdin.fileno())
#    dfrni.close()
#    os.dup2(dfwsi.fileno(),sys.stdout.fileno())
#    dfrsi.close()
#    
#    os.execlp("python3","python3","Somme.py")
#else :  
#    
#    dfrnp.close()
#    dfwsp.close()
#    dfwsi.close()
#    dfrni.close()
#    
#    gener(N)
#    
#    Stot = int(dfrsp.recv())+int(dfrsi.recv())
#    print(Stot)














       