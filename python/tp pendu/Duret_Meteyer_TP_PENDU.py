# -*- coding: utf-8 -*-
"""
Created on Mon Oct  2 13:41:37 2017

@author: guillaume.duret
"""

#Guillaume Duret et Paul Meteyer, 02/10/2017, programmation jeu du pendu
from random import *
#Cette fonction choisit aleatoirement un mot présent dans un fichier texte


def MotAleatoire():
    fichier=open('mots.txt','r') #Ouvre un fichier texte contenant des mots et qui s'appelle ('mots.txt')
    mots=fichier.readlines() #créé une liste avec comme éléments les lignes du fichier
    mot=choice(mots) #Choisit aléatoirement un mot présent dans cette liste créée ci dessus
    if mot=='\n':
        return(MotAleatoire())
    mot.replace('\n','')#Supprime les retours a la ligne
    return(mot)


#Cette fonction vérifie si un caractère est deja présent dans une liste
def VerifAppel(caractere,L):
    Bool=False #On initialise un booléen a False
    for i in range(len(L)):
        if caractere==L[i]: #Si le caractere qu'on rentre est déja présent dans la liste qui affiche les caractères utilisés
            Bool=True #On met le bool a True et donc on a déja essayé de rentrer ce caractère
    return(Bool)

    
def newChaineCourante(ChaineCourante,i,caractere) : #remplace les caracteres trouvés dans chainecourante
    deb=ChaineCourante[0:i] #On prend les (i-1) premiers termes dans la chaineCourante qu'on stocke
    fin=ChaineCourante[(i+1):] #On prend les termes présents a partir de la i+1-ieme position dans la ChaineCourente qu'on stocke
    ChaineCourante=deb+caractere+fin #On concatène les listes en remplacant le caractere a la i-ieme position
    return(ChaineCourante)
            
    
def CreeChaineCourante(motrandom,Z,n):#
    ChaineCourante='' #Affichage du mot en question
    for i in range(0,n-1):
        if motrandom[0]==motrandom[i]: #Test si la premiere lettre est présente plusieurs fois dans le mot
            ChaineCourante+=motrandom[i] # Si elle est présente, on l'ajoute dans notre chaine courante
            Z=Z+1 #On incrémente le compteur de nombre de caractères trouvés (si la premiere lettre est X fois, le compteur Z sera déja a X)
        else:
            ChaineCourante+='*'#On initialise la chaine courante avec L étoiles
    return(ChaineCourante,Z)




#Ce programme simule le jeu du pendu connu par tous (PROGRAMME PRINCIPAL !!)
def pendu():
    global score
    score=8
    Z=0 #Z représente le nombre de caractères trouvé
    C=8 #Compteur du nombre de coups restants
    motrandom=MotAleatoire()#Appel de la fonction MotAleatoire qui génère le mot
    n=len(motrandom)
    ChaineCourante,Z=CreeChaineCourante(motrandom,Z,n)
    L=[motrandom[0]]#Liste qui va recueillir les caracères pour vérifier si l'utilisateur ne marque pas plusieurs fois le meme caractère (fonction VerifAppel)
    while C!=0:
        print('Nombre de coups restants : ',C) #On affiche a chaque essai le nombre de coups restants
        print(ChaineCourante) #On affiche la chaine courante a chaque essai 
        caractere=str(raw_input('Caractere a tester : ')) #Entrer un caractere et on va tester si il est présent
        trouver=False #On initialise un booléen qui va nous dire, lorsqu'on rentre un caractere, si le caractère est présent dans le mot recherché
        if VerifAppel(caractere,L)==False: #verifie si le caractere appelé a deja ete appele avant
            L=L+[caractere] #le caractere appele se rejoute à la liste
            for i in range(0,n):
                if caractere==motrandom[i]: #Si le caractere demandé apparait dans le mot recherché
                    ChaineCourante=newChaineCourante(ChaineCourante,i,caractere)#On change le terme de ChaineCourante présent a la i-ieme postion par le caractere
                    trouver=True #Le booléen nous dit que le caractere demandé est présent dans le mot recherché
                    Z=Z+1 #On incrémente le compteur des lettres trouvées
        else: #Si la fonction VerifAppel vaut True, c'est a dire voir si le caractere recherché a déja été demandé
            print('Vous avez deja demande ce caractere')
            C=C+1
        if Z==(n-1):
            print(ChaineCourante)
            print('Vous avez gagne et il vous restait',C,'coups')
            if C>score:
                score=C
            print('votre meilleur score etait qu il vous restait:',score,'essai(s)')
            choix=raw_input('try again ? : o/n :')
            if choix == 'o':
                return(pendu())
            elif choix=='n':
                return('merci d avoir jouer')
            else:
                return('reponse non valide, bonne journee')
        if trouver==False: #Si le caractère proposé n'est pas trouvé dans le mot, on décrémente le compteur du nombre de coups restants
            C=C-1
        if C==0: #Si le compteur du nombre de coups restants atteint 0, on perd
            print('Vous avez perdu : le mot a trouver etait', motrandom.replace('\n',''))
            print('votre meilleur score etait qu il vous restait:',score,'essai(s)')
            choix=raw_input('try again ? : o/n :')
            if choix == 'o':
                return(pendu())
            elif choix=='n':
                return('merci d avoir jouer')
            else:
                return('reponse non valide, bonne journee')        