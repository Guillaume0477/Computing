# -*- coding: utf-8 -*-
"""
Created on Mon Oct 16 13:45:32 2017

@author: guillaume.duret
"""
from Tkinter import *
from math import *
import random

def SpaceInvaders(): #Widget principal
    global canevas,x,y,r,alien,fenetre,x0,y0,longueur,hauteur,booll,vaisseau,x1,x2,y1,y2,dx1,dy1,descentealieny,booldestroy,boolmissile,boolgo,nb_alien,nb_alien_max_ligne,nb_alien_max_colonne,nb_alien_max,fenetre
    global alien_valid,num_alien,proba_bomb_min_alien,proba_bomb_min_boss,bomb,nb_bomb,xb1,xb2,yb1,yb2,boolvaisseau,score,score_best,score1,score2,liste_configuration,boss,proba_boss_min,bool_boss,nb_vie_max,nb_vie,vie,xz0,yz0
    global vitesse_boss,longueur,photo_boss,photo_vie,vie,nb_vie_total,photo_vie,photo_alien,dx0,dx,dy,vx,niveau,ecart,nb_element,element,taille_element,xo1,xo2,yo1,yo2,element_valid,nb_obstacle,espace_obstacle,obstacle,bool_god
    global score3
    # Initialisations pour la partie
    booll=False         # Mouvement droite ou gauche des aliens
    booldestroy=False   # Alien detruit
    boolmissile=False   # Missile tire
    boolvaisseau=False  # Vaisseau detruit
    boolgo=False        # Indicateur de missile en marche
    bool_boss=False # Presence du boss
    # Dimensions de la fenetre principale
    hauteur=750
    longueur=1120
    # Pour le positionnement des differents canevas d'affichage
    x0=70
    y0=10
    dx1=0
    dy1=5
    l=longueur/20
    x1=(longueur-l)/2
    y1=hauteur-37
    x2=(longueur+l)/2
    y2=hauteur
    # Vitesse deplacement initiale des aliens en x
    dx0=2
    #Deplacement des aliens en x,y
    dx=dx0
    dy=0
    # Vitesse laterale du vaisseau
    vx=15
    # Rayon moyen des aliens
    r=5
    # Coordonnees de depart des aliens
    x=2*r
    y=2*r+80
    # Ecartement entre aliens
    ecart=35
    # Initialisation du score de la partie
    score=0
    # Lecture du meilleur score dans le fichier de stockage
    fichier=open('config.txt','r')
    liste_configuration=fichier.readlines()        #créé une liste avec comme éléments les lignes du fichier
    fichier.close()
    # Le meilleur score est a la premiere ligne du fichier de conf
    score_best=int(liste_configuration[0])
    # Cheats des lignes dans le fichier config (sauf la premiere reservee au best score)
    # GOD mode (invincibilite = pas de perte de vie)
    bool_god=False
    for i in range(1,len(liste_configuration),1):
        if liste_configuration[i][:3].upper()=='GOD': # les 3 premiers caracteres (a cause du retour chariot)
            bool_god=True
        # On peut ajouter d'autres trucs
        
    # Nombre de vies max
    nb_vie_max=3    # Pour commencer
    nb_vie_total=5  # Le nombre max possible quand on gagne (faut bien des limites sinon ca rentre plus dans l'ecran a un moment pour les cadors)
    nb_vie=nb_vie_max
    # Sensibilite pour la frequence de generation des bombes alien (0 : bombes permanentes, 100 : pas de bombes)
    proba_bomb_min_alien=99
    proba_bomb_min_boss=98
    proba_boss_min=99
    # Vitesse de deplacement du boss (fraction de la vitesse des aliens)
    vitesse_boss=0.5
    # Sensibilite pour la descente des aliens
    descentealieny=10*dx
    # Nombre d'aliens par ligne et par colonne
    nb_alien_max_colonne=8
    nb_alien_max_ligne=6
    # Nombre total d'aliens (ligne x colonne)
    nb_alien_max=nb_alien_max_ligne*nb_alien_max_colonne
    nb_alien=nb_alien_max
    # Nombre d'obstacles
    nb_obstacle=4
    taille_element=20   # Taille du carre d'obstacle
    espace_obstacle=270 # On fait a la main selon le nbre d'obstacles
    # Construction de la fenetre principale (fond noir)
    fenetre = Tk()
    fenetre.title("Space Invaders")
    canevas=Canvas(fenetre,bg="black",height=hauteur,width=longueur)
    canevas.pack(side=BOTTOM)
    # Bouton Quitter
    bouton_quitter = Button(fenetre, text="Quitter",command=fenetre.destroy)
    bouton_quitter.pack(side=RIGHT)
    # Bouton Demarrer (on lance le mouvement des aliens. Le mouvement des aliens controle l'animation du jeu)
    bouton_debut=Button(fenetre,text="Début de partie",command=deplacement_alien)
    bouton_debut.pack(side=LEFT)
    # Bouton recommencer
    bouton_recommencer = Button(fenetre, text="Nouvelle partie",command=recommencer)
    bouton_recommencer.pack(side=BOTTOM)
    # Initialisation des canevas de scoring et le niveau de jeu
    score1=canevas.create_text(x0,y0,text='Score = '+str(score),fill='white',font='Courier 15')
    score2=canevas.create_text(x0+300,y0,text='Meilleur score = '+str(score_best),fill='white',font='Courier 15')
    niveau=1    # Niveau du jeu
    score3=canevas.create_text(x0+600,y0,text='Niveau '+str(niveau),fill='white',font='Courier 15')
    # Canevas des vies (les vaisseaux en haut a droite)
    photo_vie = PhotoImage(file="canon.gif")
    vie=nb_vie_max*[0]
    for i in range(nb_vie_max):
        vie[nb_vie_max-i-1]=canevas.create_image(x0+1020-i*55,y0+6,image=photo_vie)
    # On cree tous les aliens sous forme de tableau de canevas
    alien=[[0]*nb_alien_max_colonne for _ in range(nb_alien_max_ligne)]
    photo_alien=nb_alien_max_ligne*[0]
    for i in range (nb_alien_max_ligne):
        photo_alien[i]=PhotoImage(file='alien'+str(i+1)+'.gif')
    for i in range(nb_alien_max_ligne):
        for j in range (nb_alien_max_colonne):
            alien[i][j]=canevas.create_image(x+2*j*(r+ecart),y+i*(r+ecart),image=photo_alien[i])
    #Pour compter le nombre d'aliens vivants (0 : mort, 1 : vivant)
    alien_valid=[[1]*nb_alien_max_colonne for _ in range(nb_alien_max_ligne)]
    # Le canevas du boss
    photo_boss=PhotoImage(file="boss.gif")
    # On met le boss en dehors du cadre pour commencer
    boss=canevas.create_image(-50,50,image=photo_boss)
    xz0,yz0=-50,50 # les coordonnees du centre du boss
    # Canevas des obstacles
    nb_element=0
    element=nb_obstacle*[0]
    element=[[0]*0 for _ in range(nb_obstacle)]
    element_valid=nb_obstacle*[0]
    element_valid=[[0]*0 for _ in range(nb_obstacle)]
    # Les coordonnees sont stockees par numero d'obstacle et par element
    xo1,xo2,yo1,yo2=nb_obstacle*[0],nb_obstacle*[0],nb_obstacle*[0],nb_obstacle*[0]
    xo1=[[0]*0 for _ in range(nb_obstacle)]
    xo2=[[0]*0 for _ in range(nb_obstacle)]
    yo1=[[0]*0 for _ in range(nb_obstacle)]
    yo2=[[0]*0 for _ in range(nb_obstacle)]
    for i in range(nb_obstacle):
        obstacle(i,100+i*espace_obstacle,600)
    # Canevas des bombes aliens
    bomb=[]
    nb_bomb=0
    xb1,xb2,yb1,yb2=[],[],[],[]
    # Canevas du vaisseau
    photo_vaisseau = PhotoImage(file="canon.gif")
    vaisseau=canevas.create_image((x1+x2)/2,(y1+y2)/2,image=photo_vaisseau)
    # Canevas deplacement vaisseau a droite (fleche droite)
    canevas.bind_all("<Right>",deplacement_vaisseau_droite)
    # Canevas deplacement vaisseau a gauche (fleche gauche)
    canevas.bind_all("<Left>",deplacement_vaisseau_gauche)
    # Canevas controle de tir
    canevas.bind_all("<space>",missile)
    # Boucle principale
    fenetre.mainloop()

def initialisation(): # Reinitialise un nouveau tableau de jeu
    global nb_bomb,bomb,xb1,xb2,yb1,yb2,boss,photo_boss,alien_valid,nb_vie,photo_vie,vie,nb_alien,nb_alien_max,nb_vie_total,photo_vie,photo_alien,x1,x2,x,y,r,dx,element_valid
    global boolmissile,boolgo,niveau,ecart,nb_obstacle,xo1,xo2,yo1,yo2,obstacle,espace_obstacle,dx,element,xz0,yz0,score3
    # On ajoute une vie (jusqu'a 5 max)
    if nb_vie<nb_vie_total:
        for i in range(nb_vie):
            canevas.delete(vie[i])
        nb_vie+=1
        vie=nb_vie*[0]
        for i in range(nb_vie):
            vie[nb_vie-i-1]=canevas.create_image(x0+1020-i*55,y0+6,image=photo_vie)
    # On met le boss en dehors du cadre
    canevas.delete(boss)
    xz0,yz0=-50,50 # les coordonnees du centre du boss
    boss=canevas.create_image(-50,50,image=photo_boss)
    # On met a jour le caneavs du niveau
    canevas.delete(score3)
    score3=canevas.create_text(x0+600,y0,text='Niveau '+str(niveau),fill='white',font='Courier 15')
    # Coordonnees de depart des aliens
    x=2*r
    y=2*r+80
    # On remet des aliens
    nb_alien=nb_alien_max
    for i in range(nb_alien_max_ligne):
        for j in range(nb_alien_max_colonne):
            canevas.delete(alien[i][j])
            alien[i][j]=canevas.create_image(x+2*j*(r+ecart),y+i*(r+ecart), image=photo_alien[i])          
    #Pour compter le nombre d'aliens vivants (0 : mort, 1 : vivant)
    alien_valid=[[1]*nb_alien_max_colonne for _ in range(nb_alien_max_ligne)]
    xo1=[[0]*0 for _ in range(nb_obstacle)]
    xo2=[[0]*0 for _ in range(nb_obstacle)]
    yo1=[[0]*0 for _ in range(nb_obstacle)]
    yo2=[[0]*0 for _ in range(nb_obstacle)]
    # Effacement des elements d'obstacles restants
    for k in range(nb_obstacle):
        for j in range(len(element_valid[k])-1,-1,-1):
            canevas.delete(element[k][j])
    # On purge tous les tableaux (en cas d'init). On peut garder le nbre d'obstacle car il ne change pas
    element=[[0]*0 for _ in range(nb_obstacle)]
    element_valid=[[0]*0 for _ in range(nb_obstacle)]
    for k in range(nb_obstacle):
        obstacle(k,100+k*espace_obstacle,600)
    # Reinitialisation canevas de controle de tir
    boolmissile=False
    boolgo=False

def recommencer():
    global fenetre
    # On ferme la fenetre du jeu
    fenetre.destroy()
    # On relance le jeu (ca marche tout le temps et ca reinitialise tomissile_avanceut comme il faut!)
    SpaceInvaders()

def deplacement_alien(): #Déplace l'alien
    global canevas,N,fenetre,x,y,booll,descentealieny,booldestroy,boolgo,nb_alien_max,nb_alien,nb_alien_max_ligne,nb_alien_max_colonne,alien_valid,y1,boolvaisseau,liste_configuration,score_best,boss,photo_vie
    global proba_bomb_min_boss,proba_bomb_min_alien,bool_boss,vie,nb_vie,nb_vie_max,xz0,yz0,vitesse_boss,longueur,xb1,xb2,yb1,yb2,bomb,nb_bomb,dx,dy,ecart,nb_obstacle,element,element_valid,bool_god,niveau
    # Uniquement si le nombre de vie est non nul, on commence les deplacements
    if nb_vie>0:
        # Si les aliens atteignent le vaisseau ou si le vaisseau est touche par une bombe, on a perdu
        # Si le nombre d'alien est nul, on a gagne la manche...
        if nb_alien==0:
            boolgo=True
            # On supprime les bombes
            for i in range(nb_bomb):
                canevas.delete(bomb[i])
            xb1,xb2,yb1,yb2=[],[],[],[]
            bomb=[]
            nb_bomb=0
            # On repart au niveau suivant
            niveau+=1
            initialisation()
        # S'il reste des aliens et qu'ils ont soit touche le vaisseau ou le vaisseau a ete touche par une bombe, on a perdu la manche ou la partie suivant le nombre de vies restantes...
        elif yvalid(y)+r>=y1 or boolvaisseau==True :
            # On perd une vie (sauf en god mode)
            if not bool_god:
                for i in range(nb_vie):
                    # On supprime les canevas de vie
                    canevas.delete(vie[len(vie)-nb_vie])
                # On decremente le compteur
                nb_vie-=1
            # On supprime les bombes existantes
            for i in range(nb_bomb):
                canevas.delete(bomb[i])
            xb1,xb2,yb1,yb2=[],[],[],[]
            bomb=[]
            nb_bomb=0
            # Si les aliens sont en bas et god mode active, on redemarre au meme niveau
            if not boolvaisseau and bool_god:
                initialisation()
            boolvaisseau=False
            # Plus de vie...
            if nb_vie==0:
                # Effacement du vaisseau
                canevas.delete(vaisseau)
                # Effacement des aliens
                canevas.delete(boss)
                for i in range (nb_alien_max_ligne):
                    for j in range(nb_alien_max_colonne):
                        canevas.delete(alien[i][j])
                # Effacement des bombes
                for i in range (len(bomb)):
                    canevas.delete(bomb[i])
                # Effacement des elements d'obstacles restants
                for k in range(nb_obstacle):
                    for j in range(len(element_valid[k])-1,-1,-1):
                        canevas.delete(element[k][j])
                # Message Game over
                canevas.create_text(550,400,text='Game Over !',fill='orange',font='Courier 45')
                boolgo=True
                # Mise a jour du fichier de configuration avec eventuellement la mise a jour du meilleur score
                fichier=open('config.txt','w') # Ouverture en ecriture avec effacement complet du fichier
                # Ecriture ligne a ligne de liste_configuration dans le fichier
                liste_configuration[0]=str(score_best)
                for i in range (0,len(liste_configuration)) :
                    fichier.write(liste_configuration[i]+'\n')
                fichier.close()
                # On peut mettre un message ou une tempo avant de redemarrer

                return
        # Sinon, la partie continue
        else:
            # Calcul de l'alien le plus a droite
            rang_droite=nb_alien_max_colonne-1
            for j in range(nb_alien_max_colonne-1,-1,-1):
                for i in range(nb_alien_max_ligne):
                    flag=False
                    if alien_valid[i][j]:
                        rang_droite=j
                        flag=True
                        break
                if flag:
                    break
            # Mouvement de gauche a droite des aliens
            if x+2*(r+ecart)*rang_droite<=longueur-r and booll==False:
                for i in range(nb_alien_max_ligne):
                    for j in range(nb_alien_max_colonne):
                        if alien_valid[i][j]:
                            canevas.move(alien[i][j],dx,dy) 
                x,y=x+dx,y+dy
            else:
                booll=True # Flag pour declencher le retour de droite a gauche
            # Calcul de l'alien le plus a gauche
            rang_gauche=0
            for j in range(nb_alien_max_colonne):
                for i in range(nb_alien_max_ligne):
                    flag=False
                    if alien_valid[i][j]:
                        rang_gauche=j
                        flag=True
                        break
                if flag:
                    break
            # On recale x des qu'il est trop petit (pour que le test ==r d'apres puisse fonctionner)
            if x+2*(r+ecart)*rang_gauche<=r:
                x=r-2*(r+ecart)*rang_gauche
                for i in range(nb_alien_max_ligne):
                    for j in range(nb_alien_max_colonne):
                        if alien_valid[i][j]:
                            canevas.delete(alien[i][j])
                            alien[i][j]=canevas.create_image(x+2*j*(r+ecart),y+i*(r+ecart),image=photo_alien[i])
            # Mouvement retour de droite a gauche
            if x+2*(r+ecart)*rang_gauche>r and booll==True:
                for i in range(nb_alien_max_ligne):
                    for j in range(nb_alien_max_colonne):
                        if alien_valid[i][j]:
                            canevas.move(alien[i][j],-dx,dy)
                x,y=x-dx,y+dy
            # Mouvement de descente des aliens (une fois revenus au bord gauche)
            elif x+2*(r+ecart)*rang_gauche==r:
                for i in range(nb_alien_max_ligne):
                    for j in range(nb_alien_max_colonne):
                        if alien_valid[i][j]:
                            canevas.move(alien[i][j],(r-(x+2*(r+ecart)*rang_gauche)),descentealieny)
                x,y=x,y+descentealieny
                booll=False
            # Generation bombe des aliens
            bombe()
            # Deplacement du boss (deplacement_boss gere aussi les bombes du boss)
            deplacement_boss()
        # Mouvement alien
        fenetre.after(5,deplacement_alien)

def deplacement_boss(): # Le deplacement du boss est aleatoire de gauche a droite en haut de fenetre
    global canevas,N,fenetre,x,y,booll,descentealieny,booldestroy,boolgo,nb_alien,nb_alien_max,alien_valid,y1,boolvaisseau,liste_configuration,score_best,proba_boss_min
    global bool_boss,xz0,yz0,vitesse_boss,longueur,proba_bomb_min_boss,dx,ecart,element_valid
    # Choisit si le boss doit apparaitre ou pas
    proba_boss=random.randrange(1,101,1)
    if proba_boss>proba_boss_min:
        bool_boss=True
    if bool_boss:
        # Mouvement de gauche a droite du boss
        canevas.move(boss,vitesse_boss*dx,0)
        xz0+=vitesse_boss*dx
        # Quand le boss est sorti de la fenetre par la droite, on arrete
        if xz0>longueur+50:
            # On delete le canevas et on le repositionne a gauche
            canevas.move(boss,-xz0-50,0)
            xz0=-50
            bool_boss=False
        bombe_boss()

def deplacement_vaisseau_droite(event): # Mouvement vaisseau a droite
    global x1,x2,vx
    if x2<=1120-vx:
        x1,x2=x1+vx,x2+vx
        canevas.move(vaisseau,vx,0)
    
def deplacement_vaisseau_gauche(event): # Mouvement vaisseau a gauche
    global x1,x2,vx
    if x1>=vx:
        x1,x2=x1-vx,x2-vx
        canevas.move(vaisseau,-vx,0)

def obstacle(k,x,y): # Creation d'un obstacle a des coodonnees precises (centre de l'obstacle)
    global nb_obstacle,nb_element,element,element_valid,taille_element,xo1,xo2,yo1,yo2,forme
    # Les coordonnees de chacun des elements d'obstacle sont stockees dans des listes. Les elements sont des rectangles.
    # x,y sont les coordonnees de l'element 0,0 du tableau
    # La forme des obstacles est donnee par les listes suivantes (0 pas d'element et 1 un element d'obstacle)
    forme=4*[0]
    forme[0]=[0,1,1,1,0]
    forme[1]=[1,1,1,1,1]
    forme[2]=[1,1,1,1,1]
    forme[3]=[1,0,0,0,1]
    # On cree l'element d'obstacle (un carre)
    for i in range(len(forme)):
        for j in range(len(forme[i])):
            if forme[i][j]==1:
                xo1[k].append(x+j*taille_element)
                xo2[k].append(x+(j+1)*taille_element)
                yo1[k].append(y+i*taille_element)
                yo2[k].append(y+(i+1)*taille_element)
                element_valid[k].append(1)
                element[k].append(canevas.create_rectangle(xo1[k][nb_element],yo1[k][nb_element],xo2[k][nb_element],yo2[k][nb_element],fill='green'))
                nb_element+=1
    nb_element=0
    
def missile(event): # Cree un missile en appuyant sur la touche <space>
    global xv1,xv2,tir,yv1,yv2,x1,x2,y1,y2,boolmissile,boolgo,element,element_valid
    if boolmissile==False and boolgo==False:
        xv1=x1+((x2-x1)/2)-2
        yv1=y1+17+(y1-y2)/2-5
        xv2=x1+((x2-x1)/2)+2
        yv2=y1+5
        boolmissile=True
        tir=canevas.create_rectangle(xv1,yv1,xv2,yv2,fill='green')
        booldestroy=False
        missile_avance()

def missile_avance(): # Controle du mouvement du missile
    global tir,y1,dy1,xv1,xv2,x,y,r,yv2,yv1,booldestroy,boolmissile,nb_alien,nb_alien_max,alien_valid,score,score_best,score1,score2,liste_configuration,xz0,yz0,ecart,xo1,xo2,yo1,yo2,element,element_valid,nb_obstacle
    canevas.move(tir,0,-dy1)
    yv1,yv2=yv1-dy1,yv2-dy1
    # Sortie du missile par le haut de la fenetre
    if yv1<15:
        xv1,yv1,xv2,yv2=x1+((x2-x1)/2)-3,y1+17+(y1-y2)/2,x1+((x2-x1)/2)+3,y1
        canevas.delete(tir)
        boolmissile=False
        return
    # Verification si le tir touche un obstacle
    for k in range(nb_obstacle):
        for j in range(len(element_valid[k])-1,-1,-1):
            if element_valid[k][j]:
                if yv1>=yo2[k][j]:
                    if xv2>=xo1[k][j] and xv1<=xo2[k][j]:
                        canevas.delete(tir)
                        # On efface le canevas de l'element 
                        canevas.delete(element[k][j])
                        element_valid[k][j]=0
                        boolmissile=False
                        return
    # Verification si le tir touche un alien
    for i in range(nb_alien_max_ligne-1,-1,-1): # On commence par la ligne d'aliens la plus proche du vaisseau
        for j in range(nb_alien_max_colonne):
           if alien_valid[i][j]:
               if (sqrt((((xv1+xv2)/2)-(x+2*j*(r+ecart)))**2+(((yv1+yv2)/2)-(y+i*(r+ecart)))**2))<2*r+20:
                   canevas.delete(tir)
                   canevas.delete(alien[i][j])
                   # On memorise la destruction de l'alien
                   alien_valid[i][j]=0
                   booldestroy=True
                   boolmissile=False
                   # On decremente le compteur d'aliens
                   nb_alien=nb_alien-1
                   # On ajoute les points
                   score+=10*(nb_alien_max_ligne-i)
                   # On verifie par rapport au meilleur score
                   if score>score_best:
                       # Mise a jour du score dans la liste 
                       score_best=score
                       canevas.delete(score2) #On efface le texte
                       score2=canevas.create_text(x0+300,y0,text='Meilleur score = '+str(score_best),fill='white',font='Courier 15')
                   # On efface le texte
                   canevas.delete(score1)
                   score1=canevas.create_text(x0,y0,text='Score = '+str(score),fill='white',font='Courier 15')
                   return
    # Verification si le tir a touche le boss
    if (sqrt(((xv1+(xv2-xv1)/2)-(xz0))**2+((yv2+(yv1- yv2)/2)-(yz0))**2))<50:
        canevas.delete(tir)
        # On replace le boss au debut
        canevas.move(boss,-xz0-50,0)
        xz0=-50
        # On ajoute les points
        score+=80
        # On verifie par rapport au meilleur score
        if score>score_best:
            # Mise a jour du score dans la liste 
            score_best=score
            canevas.delete(score2) #On efface le texte
            score2=canevas.create_text(x0+300,y0,text='Meilleur score = '+str(score_best),fill='white',font='Courier 15')
        # On efface le texte
        canevas.delete(score1)
        score1=canevas.create_text(x0,y0,text='Score = '+str(score),fill='white',font='Courier 15')
    # Poursuite du mouvement du missile (toutes les 1 ms)
    fenetre.after(1,missile_avance)

def bombe(): # Cree une bombe pour un alien vivant de facon aleatoire
    global nb_alien_max,nb_alien_max_ligne,nb_alien_max_colonne,alien_valid,num_alien,x,y,r,xb1,xb2,yb1,yb2,bomb,nb_bomb,y1,proba_bomb_min_alien,ecart,element,element_valid
    # Choisit si une bombe doit etre cree ou non et l'alien vivant qui va la lacher
    proba_bomb=random.randrange(1,101,1)
    if proba_bomb>proba_bomb_min_alien:
        # On tire un alien aleatoirement dans la liste des aliens encore vivants
        aleatoire()
        # Coordonnees de l'alien qui lache la bombe
        xb1.append(x+2*(r+ecart)*(num_alien%nb_alien_max_colonne)-2)
        xb2.append(x+2*(r+ecart)*(num_alien%nb_alien_max_colonne)+2)
        yb1.append(y+(r+ecart)*(num_alien/nb_alien_max_colonne)-4)
        yb2.append(y+(r+ecart)*(num_alien/nb_alien_max_colonne)+4)
        # Creation d'une bombe (dans la liste des bombes existantes)
        bomb.append(canevas.create_rectangle(xb1[nb_bomb],yb1[nb_bomb],xb2[nb_bomb],yb2[nb_bomb],fill='white'))
        nb_bomb+=1
        # Gestion du mouvement des bombes
        bombe_avance()

def bombe_boss(): # Cree une bombe pour le boss de facon aleatoire
    global xz0,yz0r,xb1,xb2,yb1,yb2,bomb,nb_bomb,proba_bomb_min_boss,element,element_valid
    # Choisit si une bombe doit etre cree ou non
    proba_bomb=random.randrange(1,101,1)
    if proba_bomb>proba_bomb_min_boss:
        # Coordonnees de l'alien qui lache la bombe (celle du boss)
        xb1.append(xz0-3)
        xb2.append(xz0+3)
        yb1.append(yz0-3)
        yb2.append(yz0+3)
        # Creation d'une bombe (dans la liste des bombes existantes)
        bomb.append(canevas.create_rectangle(xb1[nb_bomb],yb1[nb_bomb],xb2[nb_bomb],yb2[nb_bomb],fill='white'))
        nb_bomb+=1
        # Gestion du mouvement des bombes
        bombe_avance()

def bombe_avance(): # Controle du mouvement de toutes les bombres crees
    global xb1,xb2,yb1,yb2,dy1,bomb,nb_bomb,y1,x1,x2,nb_alien,boolvaisseau,xo1,xo2,yo1,yo2,nb_obstacle,element,element_valid
    for i in range(nb_bomb):
        canevas.move(bomb[i],0,2)
        yb1[i],yb2[i]=yb1[i]+2,yb2[i]+2
        # Verification de l'atteinte d'un obstacle (on teste obstacle par obstacle)
        boolbomb=False
        for k in range(nb_obstacle):
            # Dans l'ordre, les rangs les plus bas etant les obstacles les plus en haut
            for j in range(len(element_valid[k])):
                if element_valid[k][j]:
                    if yb2[i]>=yo1[k][j]:
                        if xb2[i]>=xo1[k][j] and xb1[i]<=xo2[k][j]:
                            # On efface le canevas de l'element
                            canevas.delete(element[k][j])
                            # on invalide l'element
                            element_valid[k][j]=0
                            # On ferme le canevas de la bombe
                            canevas.delete(bomb[i])
                            # On purge les liste de bombes (pour eviter de saturer la memoire et augmenter le temps de calcul
                            bomb.pop(i)
                            xb1.pop(i)
                            xb2.pop(i)
                            yb1.pop(i)
                            yb2.pop(i)
                            # On decremente le compteur de bombes vivantes
                            nb_bomb-=1
                            return
        # Verification de l'atteinte du vaisseau
        if yb2[i]>=y1:
            # Si le vaisseau est touche on met le boolen a true et on sort (l'arret est gere par le mouvement des aliens)
            if xb2[i]>=x1 and xb1[i]<=x2:
                boolvaisseau=True
                return
            # Sortie du missile par le bas de la fenetre
            else :  
                # On ferme le canevas
                canevas.delete(bomb[i])
                # On purge les liste de bombes (pour eviter de saturer la memoire et augmenter le temps de calcul
                bomb.pop(i)
                xb1.pop(i)
                xb2.pop(i)
                yb1.pop(i)
                yb2.pop(i)
                # On decremente le compteur de bombes vivantes
                nb_bomb-=1
                return
    fenetre.after(100,bombe_avance)

def aleatoire() : # Choisit un numero d'alien vivant de facon aleatoire
    global nb_alien_max_ligne,nb_alien_max_colonne,nb_alien_max,alien_valid,num_alien,element_valid
    # Choix aleatoire d'un alien
    num_alien=random.randrange(0,nb_alien_max,1)
    # Verification que l'alien choisit est vivant, sinon on recommence
    if alien_valid[num_alien/nb_alien_max_colonne][num_alien%nb_alien_max_colonne]==0 :
        aleatoire()

def yvalid(yy): # Recale le y en fonction de la derniere ligne d'alien vivante
    global alien_valid,nb_alien_max_ligne,nb_amien_max_colonne,ecart,element_valid,dx0,dx,descentealieny,niveau
    # On cherche la derniere ligne ou il reste au moins un alien vivant
    for i in range(nb_alien_max_ligne-1,-1,-1):
        flag=False
        for j in range(nb_alien_max_colonne):
            if alien_valid[i][j]==1:
                flag=True
                yy+=i*(r+ecart)
                break
        if flag:
            # On modifie la vitesse des aliens (de 20% quand une ligne d'alien du bas disparait)
            dx=int(dx0*1.2**(nb_alien_max_ligne-i-1)*1.2**(niveau-1))
            descentealieny=10*dx
            break
    return yy

SpaceInvaders()
