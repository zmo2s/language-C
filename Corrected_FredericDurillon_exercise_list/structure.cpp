je disais ça à cause de ta phrase «une structure est un tableau de variables pouvant être de differents type». Quand tu as quelquechose du genre :
Code:
struct personne {
  char* prenom;
  char* nom;
  int age;
};
prenom, nom et age ne sont pas des variables, ce sont des champs (même si age vien après int).
struct personne est un type que tu peux instancier (=créer une variable de ce type) en faisant :
Code:
struct personne Kwariz;
Kwariz sera une variable de type struct personne possèdant plusieurs champs ...