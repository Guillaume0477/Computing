# -*- coding: utf-8 -*-
"""
Created on Fri Jun  8 08:40:37 2018

@author: antoine.bralet
"""

import multiprocessing as mp
# Ici, chaque process incrémente la valeur de SA case
def count3_on_travaille_dans_un_array(nb_iterations):
    global tableau_partage
    for i in range(nb_iterations):
        mon_indice = mp.current_process().pid % 2
        tableau_partage[mon_indice]+=1 # donnera 0 / 1 selon le process
#−−−−−−−−−−−−−−−−−−−−−−−−−−Avec Array−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
tableau_partage = mp.Array('i', 2) # tableau de 2 entiers
# Initialisation des array :
tableau_partage[0]=0; tableau_partage[1]=0; # Initialisation de l’arra
# Ou via
tableau_partage[:]= [0 for _ in range(2) ]# IL FAUT les [:] sinon, ne marche pas
# ATTENTION : NE PAS INITIALISER comme ceci : tableau_partage= [0 for _ in range(2) ]
# Cette écriture redéfinira notre Array comme une liste ! (principe de la prog. fonctionnelle)
# Egalement, sans [:], print dennera le type de l’Array, pas son contenu
print("le contenu du tableau_partage AVANT les incrémentations : ", tableau_partage[:])
# On crée 2 process
nb_iterations = 5000
pid1=mp.Process(target=count3_on_travaille_dans_un_array, args=(nb_iterations,)); pid1.start()
pid2=mp.Process(target=count3_on_travaille_dans_un_array, args=(nb_iterations,)); pid2.start()
pid1.join(); pid2.join()
print(tableau_partage[0], " et " , tableau_partage[1])
print("la somme du tableau partage APRES les incrémentations : %d (doit etre %d)"\
    %(sum(tableau_partage),nb_iterations*2) )