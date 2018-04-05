#ifndef SIMULATEUR_H_INCLUDED
#define SIMULATEUR_H_INCLUDED
#include "grman/grman.h"
#include<vector>

using namespace std;
class Sommet;

class Simulateur
{
    private:
        int m_mx;
        int m_my;
        grman::WidgetBox m_fond;//fond
        grman::WidgetButton m_bouton;//cadre graphe simulation
        grman::WidgetButton m_cadresimu;//arret de l'affichage de la simulation
        vector<grman::WidgetBox*> m_elements;//points de la courbe
        vector<grman::WidgetEdge*> m_liens;
        grman::WidgetBox m_casx;
        grman::WidgetBox m_casy;
        grman::WidgetText m_x;
        grman::WidgetText m_y;
    public:
        Simulateur(Sommet*s,int temps);
        ~Simulateur();
        bool update();
};



#endif // SIMULATEUR_H_INCLUDED
