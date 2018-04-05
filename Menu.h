#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "grman/grman.h"
#include <iostream>
#include <string>

using namespace std;

class Menup
{

     private:

         //fin totale par l'utilisateur
        int m_fin=0;
        // quitter le graphe par l'utilisateur
        int m_quitter=0;
        //recuperation du nom du fichier
        string m_nomsource;

         //widgets pour le menu principal
        grman::WidgetBox m_cadre;
        grman::WidgetImage m_imagefond;
        grman::WidgetButton m_graphe1;
        grman::WidgetImage m_graphe1_im;
        grman::WidgetButton m_graphe2;
        grman::WidgetImage m_graphe2_im;
        grman::WidgetButton m_graphe3;
        grman::WidgetImage m_graphe3_im;
        grman::WidgetButton m_nouveau;
        grman::WidgetImage m_nouveau_im;
        grman::WidgetButton m_charger;
        grman::WidgetImage m_charger_im;
        grman::WidgetButton m_quittertout;
        grman::WidgetImage m_quittertout_im;

     public:
        Menup();
        ~Menup();
        int update();
        void menuprincipal();
};


#endif // MENU_H_INCLUDED
