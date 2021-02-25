import matplotlib.pyplot as plt
from create_sat_sg import *
import os
import sys

print ('Probleme configuration:', str(sys.argv))

semaine = -1
nb_groupe = -1
taille_groupe = -1
name = "null"

if(len(sys.argv) <4):
    print("pour executer : test_sat.py semaine groupe taille_groupe [opt nom_fichier_cnf]")
    exit(0)
if(len(sys.argv) == 4):
    semaine = int(sys.argv[1])
    nb_groupe = int(sys.argv[2])
    taille_groupe = int(sys.argv[3])
    date = datetime.datetime.now().strftime("%m_%d_%Y_%H_%M_%S")
    name = "golf_s" + str(semaine) + "_g" + str(nb_groupe) + "_" + date + "v" + ".cnf"
if(len(sys.argv) == 5):
    semaine = int(sys.argv[1])
    nb_groupe = int(sys.argv[2])
    taille_groupe = int(sys.argv[3])
    name = sys.argv[4]

#p=7
#s=4
"""
liste_noms_ensembles = [str(ss) + "_" + str(pp) for pp in range(p) for ss in range(s)]
print(liste_noms_ensembles)

date = datetime.datetime.now().strftime("%m_%d_%Y_%H_%M_%S")
semaine = 2
nb_groupe = 3
taille_groupe = 2

name = "golf_s" + str(semaine) + "_g" + str(nb_groupe) +"_"+date+"v"+ ".cnf"
"""
#name = "mouais.cnf"
h = create_sat()
h.create(semaine,nb_groupe,taille_groupe,name)

os.system("./execmini.sh "+name)

f = open("solution.txt", "r")
c = f.read()

t = c.split("\n")
t=t[1]
t = t.split(" ")
t = np.array([int(i)for i in t])

print(t)

xg = ["G"+str(i) for i in range(1,nb_groupe+1)]
yg = ["Joueur "+str(1+(i %(nb_groupe*taille_groupe))) for i in range(0,nb_groupe*taille_groupe*semaine)]
#print(yg,np.shape(yg))

ml = 0
k = 0
affich = ""+yg[ml]+" : "
for i in range(len(t)-1):
    if k%nb_groupe == 0 and k!=t[-1]:
        ml+=1
        affich += "\n"+yg[ml]+" : "
        #affich += "\\\\ \n \hline\n"+yg[ml]+" & "

    if t[i]<0:
        affich += "X "
        #affich +=str(i+1)+ " & "
    else :
        affich += "O "
        #affich += str(i + 1) + " & "
    k+=1
affich+="\nGroupe : "
for g in xg:
    affich+=g+" "
print(affich)
