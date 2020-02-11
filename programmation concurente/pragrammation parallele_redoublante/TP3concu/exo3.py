# -*- coding: utf-8 -*-
"""
Created on Mon May 15 15:53:35 2017

@author: mateo.lopez
"""

import os,sys,time
import random as r

nbpairr,nbpairw = os.pipe()
nbipairr,nbipairw = os.pipe()

spairr,spairw=os.pipe()
sipairr,sipairw=os.pipe()

N=int(input("donne N : "))

pid = os.fork() 
if pid == 0: #Filtre pair
    os.close(nbpairw)
    os.close(nbipairw)
    os.close(nbipairr)
    os.close(spairr)
    os.close(sipairw)
    os.close(sipairr)
    
    n= os.read(nbpairr,4)
    print (n)
    #print ("sortie du tube NBPair : ",n)
    #print("nb decodé : ",n.decode())
    s=0
    while n.decode() != "0":
        #print("nb decodé : ",int(n.decode()))
        s=s+int(n.decode())
        n=os.read(nbpairr,4)
    os.write(spairw,str(s).encode())
    sys.exit(0)
        


pid = os.fork() 
if pid == 0: #Filtre impair
    os.close(nbpairw)
    os.close(nbpairr)
    os.close(nbipairw)
    os.close(spairr)
    os.close(spairw)
    os.close(sipairr)
    
    n= os.read(nbipairr,4)
    print (n)
    s=0
    while n.decode() != "0":
        #print(int(n.decode()))
        s=s+int(n.decode())
        n=os.read(nbipairr,4)
    os.write(sipairw,str(s).encode())
    sys.exit(0)
    
    
 # dans le générateur   
for i in range(N):
    a= r.randint(1,999)
    print ("nb généré : ", a)
    if a%2 == 0:
        #abytes = str(a).encode()
        abytes=bytes([a])
        os.write(nbpairw, abytes)
    else:
        #abytes = str(a).encode()
        abytes=bytes([a])
        os.write(nbipairw, abytes)


endstr = str(0).encode()
os.write(nbpairw,endstr)
os.write(nbipairw,endstr)


        

        
    

