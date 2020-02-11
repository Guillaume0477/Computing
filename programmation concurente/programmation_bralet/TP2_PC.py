# -*- coding: utf-8 -*-
"""
Created on Fri May  4 09:17:03 2018

@author: antoine.bralet
"""

#EXERCICE 1

import os
import sys
import time
import random

#EXERCICE1
#if os.fork() != 0:
#    os.execlp("python","python","exercice1.py","12","13")
#else :
#    os.execlp("ls","ls","-l")

##EXERCICE2
#ppid1 = os.getpid()
#for i in range(3):
#    ppid = os.getpid()
#    pid = os.fork()
#    if pid == 0 :
#        print("i:",i,"je suis le processus : ",os.getpid(),"mon pere est :", ppid,"retour :", pid)
#        ppid1 = ppid
#    else:
#        print("i:",i,"je suis le processus : ",os.getpid(),"mon pere est :", ppid1,"retour :", pid)

##EXERCICE4

#commands = [
#    ["who"],
#    ["ps"],
#    ["ls", "-l"],
#["ls", "-l"],["ls", "-l"],["ls", "-l"],["ls", "-l"],["ls", "-l"],["ls", "-l"],
#]
#parallel = False
#
#for k in commands :
#    pid = os.fork()
#    if pid == 0 : 
#        os.execlp(k[0],*k)
#    if parallel == False:
#        os.wait()
#os._exit(0)


#if os.fork() == 0 : 
#    if os.fork() == 0 :
#        os.execlp("who", "who")
#    else:
#        #os.wait()
#        os.execlp("ps","ps")
#else :
#    #os.wait()
#    os.execlp("ls","ls","-l")

##Exercice 5
#l_pid=[]
#for fichier in sys.argv[1:]:
#    l_pid.append(os.fork())    
#    if l_pid[-1] == 0:
##        print("gcc","gcc","-c",str(fichier))
##        break
#        os.execlp("gcc","gcc","-c",str(fichier))
#for i in l_pid :
#    try : os.wait()
#    except : pass
#fic = []
#for fichier in sys.argv[1:] : 
#    fic.append(fichier[: len(fichier)-1]+ "o")
#    #ch = ch + fic + " "
#os.execlp("gcc","gcc","-o","Programme",*fic)
##print("gcc","gcc","-o","Programme",ch)

###EXERCICE 7
#N=sys.argv[1]
#for k in range(int(N)) :
#    if os.fork() == 0 :
#        print("je suis le processus fils :",os.getpid(),"mon papa est :", os.getppid())
#        time.sleep(2*k)
#        print("je suis le processus fils :",os.getpid(), "et je me suis awaken de mon long dodo")
#        os._exit(k)
#        
#for k in range(int(N)) : 
#    pid_fils,statut = os.wait()
#    print(pid_fils,os.WEXITSTATUS(statut))

##EXERCICE 8
#for i in range(4) :
#    if os.fork() != 0 :
#        break
#random.seed()
#delai = random.randint(0,4)
#time.sleep(delai)
#try:
#    os.wait()
#except ChildProcessError:
#    pass
#print("Mon nom est " + chr(ord('A')+i) + " j'ai dormi " + str(delai) + " secondes")
#os._exit(0)

#EXERCICE 9

N = 3
for i in range(N) :
    for k in range(4):
        pid = os.fork()
        if pid == 0 : 
            break
    if pid != 0 :
        os._exit(0)

print("Bonjour")
os._exit(0)

