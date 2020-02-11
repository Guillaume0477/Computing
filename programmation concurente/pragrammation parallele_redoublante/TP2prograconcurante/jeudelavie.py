# -*- coding: utf-8 -*-
"""
Created on Fri May 12 11:24:44 2017

@author: mateo.lopez
"""
def printtableau():
    for i in range(len(tableau)):
        print(tableau[i])
        
def nextgen(tableau):
    nexttableau=tableau
    for x in range(1,len(tableau)-1):
    
        for y in range(1,len(tableau)-1):
            if 1:
                if tableau[y][x]==1:
                    n=combien(y,x,tableau)
                    if n!=2 and n!=3:
                        nexttableau[y][x]=0
                if tableau[y][x]==0:
                    n=combien(y,x,tableau)
                    if n==3:
                        nexttableau[y][x]=1
    return nexttableau                
                    
                    
                    
            
def combien(y,x,tableau):
    n=0
    for i in range(x-1,x+2):
        for j in range (y-1,y+2):
            if tableau[j][i]==1:
                n=n+1
    if tableau[y][x]==1:
        n=n-1
    return n
    
        

N=20
tableau=[]
for x in range(N):
    tableau.append([])
    for y in range(N):
        tableau[x].append(0)
        
        
tableau[10][11]=1
tableau[12][10]=1
tableau[10][9]=1
tableau[11][9]=1
tableau[12][9]=1
tableau[11][11]=1
tableau[12][11]=1

print(combien(12,9,tableau))
for  i in range(0):
    printtableau()
    print("  ")
    tableau = nextgen(tableau)        
    