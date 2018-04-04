#include <iostream>
#include "Graphe.h"
#include "Calcul.h"
#include "Sommet.h"
#include "Arc.h"
using namespace std;

int main()
{
  Graphe* a;
    a=new Graphe ("prem.txt");
    a->sauvegarde("deux.txt");
    return 1;
}
