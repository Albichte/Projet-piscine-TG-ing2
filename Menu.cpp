#include "Menu.h"
#include <iostream>
#include "Graphe.h"


Menup::Menup()
{
    m_cadre.set_frame(0, 0, 1024, 800);//dimensions du cadre
    m_cadre.add_child( m_imagefond );//imge de fond
    m_imagefond.set_pic_name("terre.bmp");//adresse fichier

    m_cadre.add_child( m_graphe1 );//ajout bouton
    m_graphe1.set_frame(700, 70, 240,50);//dimensions du bouton
    m_graphe1.add_child( m_graphe1_im );//imge de fond
    m_graphe1_im.set_pic_name("graphe1.png");//adresse fichier

    m_cadre.add_child( m_graphe2 );//ajout bouton
    m_graphe2.set_frame(700, 190, 240,50);//dimensions du bouton
    m_graphe2.add_child( m_graphe2_im );//imge de fond
    m_graphe2_im.set_pic_name("graphe2.png");//adresse fichier

    m_cadre.add_child( m_graphe3 );//ajout bouton
    m_graphe3.set_frame(700, 310, 240,50);//dimensions du bouton
    m_graphe3.add_child( m_graphe3_im );//imge de fond
    m_graphe3_im.set_pic_name("graphe3.png");//adresse fichier

    m_cadre.add_child( m_nouveau );//ajout bouton
    m_nouveau.set_frame(700, 430,240,50);//dimensions du bouton
    m_nouveau.add_child( m_nouveau_im );//imge de fond
    m_nouveau_im.set_pic_name("nouveau.png");//adresse fichier

    m_cadre.add_child( m_charger );//ajout bouton
    m_charger.set_frame(700, 550,240,50);//dimensions du bouton
    m_charger.add_child( m_charger_im );//imge de fond
    m_charger_im.set_pic_name("charger.png");//adresse fichier

    m_cadre.add_child( m_quittertout );//ajout bouton
    m_quittertout.set_frame(700, 670,240,50);//dimensions du bouton
    m_quittertout.add_child( m_quittertout_im );//imge de fond
    m_quittertout_im.set_pic_name("quitter.png");//adresse fichier

}


Menup::~Menup(){}

int Menup::update()
{
    int sortie=0;

    m_cadre.update();

    if (m_graphe1.clicked())
        sortie=1;
    else if (m_graphe2.clicked())
        sortie=2;

        else if (m_graphe3.clicked())
            sortie=3;

            else if (m_nouveau.clicked())
                sortie=4;

                else if (m_charger.clicked())
                    sortie=5;

                    else if (m_quittertout.clicked())
                        sortie=9;

                        else sortie=0;
    return sortie;

}
void Menup::menuprincipal()
{
    //boucle d'affichage du menu
    //9= utilisateur clique sur quitter
    while (m_fin!=9)
    {

        // fin prend la valeur du bouton sur lequel on clique
        m_fin=update();

        // Mise à jour générale (clavier/souris/buffer etc...)
        grman::mettre_a_jour();


        //reinitialser l'attribut qui stocke la sortie de graphe
        //pour que l'on puisse reouvrir differents graphes successivement
        m_quitter=0;

        //une fois le graphe choisi
        // on recupere le nom associé
        switch(m_fin)
        {
            case 1:
                m_nomsource="un.txt";
            break;
            case 2:
                m_nomsource="deux.txt";
            break;
            case 3:
                m_nomsource="trois.txt";
            break;
            case 4://nouveau graphe
                cout<<"Veuillez inscrire le nom de votre nouveau graphe"<<endl;
                cin>>m_nomsource;
            break;
            case 5://charger graphe
                cout<<"Veuillez inscrire l'adresse du fichier de votre graphe"<<endl;
                cin>>m_nomsource;
        }
        //si un graphe a ete choisi et son nom recupere
        if (m_fin!=9&&m_fin !=0)
        {//si l'utilisateur créé un nouveau graphe
            //on cree un objet graphe vide
            if(m_fin==4)
            {
                Graphe* objet;
                objet= new Graphe();
                objet->m_nom=m_nomsource;
                while ( m_quitter!=9)
                {
                    /// Il faut appeler les méthodes d'update des objets qui comportent des widgets
                    m_quitter=objet->update();

                    /// Mise à jour générale (clavier/souris/buffer etc...)
                    grman::mettre_a_jour();
                }
            }

            //si l'utilisateur chosit un graphe existant on le charge
            else
            {
                Graphe* objet;
                objet=new Graphe (m_nomsource);
                while ( m_quitter!=9)
                {
                    /// Il faut appeler les méthodes d'update des objets qui comportent des widgets
                    m_quitter=objet->update();
                    //objet->supr_som(objet->m_sommets[3]);

                    /// Mise à jour générale (clavier/souris/buffer etc...)
                    grman::mettre_a_jour();
                }
                delete objet;
            }
        }
    }

}
