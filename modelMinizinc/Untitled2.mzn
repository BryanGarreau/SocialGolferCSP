include "globals.mzn";

int :nb_semaine=3;
int :nb_groupe=3;
int :nb_joueur=nb_groupe*nb_semaine;
int :taille_groupe=nb_semaine;
set of int:all_joueur = 1..nb_joueur;
array [1..nb_semaine,1..nb_groupe] of var set of all_joueur: ladder;
array [1..nb_semaine,1..nb_groupe,1..nb_joueur] of var all_joueur: test_h;


constraint forall(i in 1..nb_semaine)(forall(j in 1..nb_groupe)(card(ladder[i,j])==taille_groupe ));

constraint forall(i in 1..nb_semaine)(forall(k,l in 1..nb_groupe where k!=l)(ladder[i,k] intersect ladder[i,l] == {}));

constraint forall(i,j in 1..nb_semaine where i!=j)(forall(k,l in 1..nb_groupe where k!=l)(card(ladder[i,l] intersect ladder[j,k]) == 1));

constraint lex_lesseq( array1d(ladder) , [ ladder[i,j] | i in 1..nb_semaine, j in 1..nb_groupe ] );
constraint lex_lesseq( array1d(ladder) , [ ladder[i,j] | i in reverse(1..nb_semaine), j in 1..nb_groupe ] );
constraint lex_lesseq( array1d(ladder) , [ ladder[i,j] | i in 1..nb_semaine, j in reverse(1..nb_groupe) ] );
constraint lex_lesseq( array1d(ladder) , [ ladder[i,j] | i in reverse(1..nb_semaine), j in reverse(1..nb_groupe) ] );

constraint forall(i in 1..nb_semaine)( lex_lesseq( [ ladder[i,j] | j in 1..nb_groupe ] , [ ladder[i,j] |j in reverse( 1..nb_groupe ) ] ));

solve satisfy;

output["Réponses : "++show(ladder)]