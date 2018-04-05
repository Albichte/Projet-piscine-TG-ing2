#include "Graphe.h"
#include "Sommet.h"
#include "Simulateur.h"
#include "Arc.h"
#include <iostream>
#include <fstream>
#include <vector>

Graphe::Graphe()
{
    m_ordre=0;
    m_nom="";
   // m_sommets=vector<Sommet*>(0);
    //m_arcs=vector<Arc*>(0);
    //cout<<m_sommets.size()<<endl;
    //cout<<m_arcs.size()<<endl;

    //widgets pour allegro
    m_cadre.set_frame(0, 0, 1024, 800);//dimensions du cadre
    m_cadre.set_bg_color(SABLECLAIR);//couleur du cadre

    m_cadre.add_child( m_barreoutil );//bloc barre outils
    m_barreoutil.set_frame(10, 10, 1004, 50);//dimensions barre outil
    m_barreoutil.set_bg_color(BLANC);//couleur barre outil

    m_barreoutil.add_child( m_menu );//bouton menu
    m_menu.set_bg_color(GRISSOMBRE);//couleur menum_menu.set_frame(15, 15, 85, 45);//dimensions
    m_menu.set_frame(16, 5, 125, 40);//dimensions
    m_menu.add_child( m_menu_im );//image dans le bouton
    m_menu_im.set_pic_name("menu.png");// pour charger image

    m_barreoutil.add_child( m_sauvegarder );//bouton sauvegarder
    m_sauvegarder.set_frame(157, 5, 125, 40);//dimensions
    m_sauvegarder.add_child( m_sauvegarder_im );//image dans le bouton
    m_sauvegarder_im.set_pic_name("sauvegarde.png");// pour charger image

    m_barreoutil.add_child( m_connexite );//bouton connexite
    m_connexite.set_frame(298, 5, 125, 40);//dimensions
    m_connexite.add_child( m_connexite_im );//image dans le bouton
    m_connexite_im.set_pic_name("connexe.png");// pour charger image

    m_barreoutil.add_child( m_kconnexite );//bouton kconnexite
    m_kconnexite.set_frame(439, 5, 125, 40);//dimensions
    m_kconnexite.add_child( m_kconnexite_im );//image dans le bouton
    m_kconnexite_im.set_pic_name("kconnexe.png");// pour charger image

    m_barreoutil.add_child( m_simulation );//bouton simulation
    m_simulation.set_frame(580, 5, 125, 40);//dimensions
    m_simulation.add_child( m_simulation_im );//image dans le bouton
    m_simulation_im.set_pic_name("simulation.png");// pour charger image

    m_barreoutil.add_child( m_nouveaus );//bouton simulation
    m_nouveaus.set_frame(721, 5, 125, 40);//dimensions
    m_nouveaus.add_child( m_nouveaus_im );//image dans le bouton
    m_nouveaus_im.set_pic_name("nouveaus.png");// pour charger image

    m_barreoutil.add_child( m_nouveaua );//bouton simulation
    m_nouveaua.set_frame(862, 5, 125, 40);//dimensions
    m_nouveaua.add_child( m_nouveaua_im );//image dans le bouton
    m_nouveaua_im.set_pic_name("nouvela.png");// pour charger image



    for (int i=0;i<m_ordre;i++)
    {
        /// Reprendre la valeur du slider dans la donnée m_value locale
        m_sommets[i]->m_slider.set_value(m_sommets[i]->m_N);
        //m_sommets[i]->m_valeur.set_message( std::to_string( (int)m_sommets[i]->m_N) );
    }


    for(unsigned int i=0;i<m_arcs.size();i++)
    {
        /// Reprendre la valeur du slider dans la donnée m_weight locale
        m_arcs[i]->m_slider.set_value(m_arcs[i]->m_weight);
        //m_arcs[i]->m_valeur.set_message( std::to_string( (int)m_arcs[i]->m_weight)) ;
    }
}

Graphe::Graphe(string nom_fich)
{

    //variables temporaires pour les constructeurs
    //ligne sert aux conversions
    string titre,ligne,nimage;
    int ordre,nbarcs,num,degre,x,y,k,n,s1,s2;
    float poids,r;

    //ouverture du fichier en mode lecture
    ifstream fichier (nom_fich,ios::in);
    //si fichier trouv�
    if(fichier)
    {
        //lecture des informations en tete de fichier
        getline (fichier,titre);
        m_nom=titre;
        //conversions
        getline (fichier,ligne);
        ordre=atoi(ligne.c_str());
        getline (fichier,ligne);
        nbarcs=atoi(ligne.c_str());
        m_ordre=ordre;
        //boucle qui parcourt les sommets
        for(int i=0; i<ordre; i++)
        {
            //et qui lit les information ligne par ligne
            //en effectuant ensuite la conversion necessaire
            getline (fichier,nimage);
            getline (fichier,ligne);
            num=atoi(ligne.c_str());
            getline (fichier,ligne);
            degre=atoi(ligne.c_str());
            getline (fichier,ligne);
            x=atoi(ligne.c_str());
            getline (fichier,ligne);
            y=atoi(ligne.c_str());
            getline (fichier,ligne);
            k=atoi(ligne.c_str());
            getline (fichier,ligne);
            n=atoi(ligne.c_str());
            getline (fichier,ligne);
            r=atof(ligne.c_str());
            m_sommets.push_back(new Sommet(nimage,num,degre,x,y,k,n,r,this));
        }

        //boucle qui parcourt les sommets



        for(int i=0; i<nbarcs; i++)
        {
            //et qui lit les information ligne par ligne
            //en effectuant ensuite la conversion necessaire
            getline (fichier,ligne);
            s1=atoi(ligne.c_str());
            getline (fichier,ligne);
            s2=atoi(ligne.c_str());
            getline (fichier,ligne);
            poids=atof(ligne.c_str());
            //identification des sommets
            for(int i=0;i<m_ordre;i++)
            {
                if(s1==m_sommets[i]->m_num_sommet)
                    s1=i;
                if(s2==m_sommets[i]->m_num_sommet)
                    s2=i;
            }
            m_arcs.push_back(new Arc(m_sommets[s1],m_sommets[s2],poids,i,this));
        }
    }

    else
        cerr<<"Probleme de fichier"<<endl;
    fichier.close();


    //widgets pour allegro
    m_cadre.set_frame(0, 0, 1024, 800);//dimensions du cadre
    m_cadre.set_bg_color(SABLECLAIR);//couleur du cadre

    m_cadre.add_child( m_barreoutil );//bloc barre outils
    m_barreoutil.set_frame(10, 10, 1004, 50);//dimensions barre outil
    m_barreoutil.set_bg_color(BLANC);//couleur barre outil

    m_barreoutil.add_child( m_menu );//bouton menu
    m_menu.set_bg_color(GRISSOMBRE);//couleur menum_menu.set_frame(15, 15, 85, 45);//dimensions
    m_menu.set_frame(16, 5, 125, 40);//dimensions
    m_menu.add_child( m_menu_im );//image dans le bouton
    m_menu_im.set_pic_name("menu.png");// pour charger image

    m_barreoutil.add_child( m_sauvegarder );//bouton sauvegarder
    m_sauvegarder.set_frame(157, 5, 125, 40);//dimensions
    m_sauvegarder.add_child( m_sauvegarder_im );//image dans le bouton
    m_sauvegarder_im.set_pic_name("sauvegarde.png");// pour charger image

    m_barreoutil.add_child( m_connexite );//bouton connexite
    m_connexite.set_frame(298, 5, 125, 40);//dimensions
    m_connexite.add_child( m_connexite_im );//image dans le bouton
    m_connexite_im.set_pic_name("connexe.png");// pour charger image

    m_barreoutil.add_child( m_kconnexite );//bouton kconnexite
    m_kconnexite.set_frame(439, 5, 125, 40);//dimensions
    m_kconnexite.add_child( m_kconnexite_im );//image dans le bouton
    m_kconnexite_im.set_pic_name("kconnexe.png");// pour charger image

    m_barreoutil.add_child( m_simulation );//bouton simulation
    m_simulation.set_frame(580, 5, 125, 40);//dimensions
    m_simulation.add_child( m_simulation_im );//image dans le bouton
    m_simulation_im.set_pic_name("simulation.png");// pour charger image

    m_barreoutil.add_child( m_nouveaus );//bouton simulation
    m_nouveaus.set_frame(721, 5, 125, 40);//dimensions
    m_nouveaus.add_child( m_nouveaus_im );//image dans le bouton
    m_nouveaus_im.set_pic_name("nouveaus.png");// pour charger image

    m_barreoutil.add_child( m_nouveaua );//bouton simulation
    m_nouveaua.set_frame(862, 5, 125, 40);//dimensions
    m_nouveaua.add_child( m_nouveaua_im );//image dans le bouton
    m_nouveaua_im.set_pic_name("nouvela.png");// pour charger image



    for (int i=0;i<ordre;i++)
    {
        /// Reprendre la valeur du slider dans la donnée m_value locale
        m_sommets[i]->m_slider.set_value(m_sommets[i]->m_N);
        //m_sommets[i]->m_valeur.set_message( std::to_string( (int)m_sommets[i]->m_N) );
    }


    for(int i=0;i<nbarcs;i++)
    {
        /// Reprendre la valeur du slider dans la donnée m_weight locale
        m_arcs[i]->m_slider.set_value(m_arcs[i]->m_weight);
        //m_arcs[i]->m_valeur.set_message( std::to_string( (int)m_arcs[i]->m_weight)) ;
    }
}

Graphe::~Graphe(){}

void Graphe:: reset_marquages_som()
{
    for(unsigned int i=0; i<m_sommets.size(); i++)
    {
        m_sommets[i]->m_marque=false;
    }

}

void Graphe:: reset_actif_som()
{
    for(unsigned int i=0; i<m_sommets.size(); i++)
    {
        m_sommets[i]->m_actif=true;
    }
}

void Graphe:: reset_marquages_arc()
{
    for(unsigned int i=0; i<m_arcs.size(); i++)
    {
        m_arcs[i]->m_marque=false;
    }
}

void Graphe:: reset_actif_arc()
{
    for(unsigned int i=0; i<m_arcs.size(); i++)
    {
        m_arcs[i]->m_marque=true;
    }
}

void Graphe::sauvegarde(string nom_fich)
{
    for(int i=0;i<m_ordre;i++)
    {
       m_sommets[i]->m_x=m_sommets[i]->m_case.m_frame.pos.x;
       m_sommets[i]->m_y=m_sommets[i]->m_case.m_frame.pos.y;
    }

    //ouverture du fichier en mode ecriture en effacant le contenu
    ofstream fichier(m_nom,ios::out|ios::trunc);
    //si fichier trouv�
    if(fichier)
    {
        //ecriture des informations en tete de fichier
        //nom du graphe ordre et nombre d'arcs
        fichier<<m_nom<<endl;
        fichier<<m_ordre<<endl;
        fichier<<m_arcs.size()<<endl;

        //boucle qui parcourt les sommets
        for (int i=0 ; i<m_ordre; i++)
        {
            //et qui ecrit chaque information ligne par ligne
            fichier<<m_sommets[i]->m_nom_im<<endl;
            fichier<<m_sommets[i]->m_num_sommet<<endl;
            fichier<<m_sommets[i]->m_deg<<endl;
            fichier<<m_sommets[i]->m_x<<endl;
            fichier<<m_sommets[i]->m_y<<endl;
            fichier<<m_sommets[i]->m_stable<<endl;
            fichier<<m_sommets[i]->m_N<<endl;
            fichier<<m_sommets[i]->m_rythme<<endl;
        }
        //boucle qui parcourt les arcs
        for (unsigned int i=0 ; i<m_arcs.size(); i++)
        {
            //et qui ecrit chaque information ligne par ligne
            fichier<<m_arcs[i]->m_som_debut->m_num_sommet<<endl;
            fichier<<m_arcs[i]->m_som_fin->m_num_sommet<<endl;
            fichier<<m_arcs[i]->m_weight<<endl;

        }
    }
    //en cas d'erreur
    else
        cerr<<"Probleme fichier"<<endl;
    //fermeture du fichier
    fichier.close();

    cout <<"##########################"<<endl;
    cout <<"Votre graphe a ete enregistre"<<endl;
    cout <<"##########################"<<endl;
}

void Graphe:: supr_arc(Arc* a)
{
    a->m_som_debut->m_deg--;
    // on commence par supprimer les arètes des sommets adjacent.
    // s_fin en premier
    unsigned int i=0;

    while(a->m_som_fin != a->m_som_debut->m_succe[i]&& i<a->m_som_debut->m_succe.size())
    {
        i++;
    }


    if(a->m_som_debut->m_succe.size() &&i<a->m_som_debut->m_succe.size())
    {
    a->m_som_debut->m_succe.erase(a->m_som_debut->m_succe.begin()+i);
    }

    // s_debut en deuxième
    i=0;
    while(a->m_som_debut!=a->m_som_fin->m_prede[i]&& i<a->m_som_fin->m_succe.size())
    {

        i++;
    }

    if(a->m_som_fin->m_prede.size()&& i<a->m_som_fin->m_prede.size())
       {
        a->m_som_fin->m_prede.erase(a->m_som_fin->m_prede.begin()+i);
       }


    //il faut maintenant effacer des arètes ajdacentes dans le sommet.
    //sommet de début en premier
    i=0;
    while(a->m_som_debut->m_arc_adj[i]!=a and i<a->m_som_debut->m_arc_adj.size())
    {
        i++;
    }
    if(a->m_som_debut->m_arc_adj.size() &&a->m_som_debut->m_arc_adj.size()>i)
    {
    a->m_som_debut->m_arc_adj.erase(a->m_som_debut->m_arc_adj.begin()+i);
    }

    //sommet de fin ensuite
     i=0;
    while(a->m_som_fin->m_arc_adj[i]!=a and i<a->m_som_fin->m_arc_adj.size())
    {
        i++;
    }
    if(a->m_som_fin->m_arc_adj.size() &&a->m_som_fin->m_arc_adj.size()>i)
    {
    a->m_som_fin->m_arc_adj.erase(a->m_som_fin->m_arc_adj.begin()+i);
    }




    //on le vire l'arète du vecteur d'arètes du graphe

    i=0;
    while(m_arcs[i]!= a && i<m_arcs.size())
    {

        i++;
    }
    cout<<m_arcs.size()<<endl;
    if(m_arcs.size()&&i<m_arcs.size())
    {
    m_arcs.erase(m_arcs.begin()+i);
    }
    cout<<m_arcs.size()<<endl;

    m_cadre.remove_child(a->m_arc);


}


//Fonctions d'ajout et suppression de sommet et arcs

void Graphe:: ajout_som()
{
    string nom_im;
    int num, k;
    float r;
    cout <<"##########################"<<endl;

    cout<<"Inserez Numero du sommet"<<endl;
    if(m_sommets.size()!=0)
        cout<<"Le Numero du sommet doit etre superieur a "<<m_sommets[m_sommets.size()-1]->m_num_sommet<<endl;

    cin>>num;
    cout<<"Adresse de l'image dans le dossier images"<<endl;
    cin>>nom_im;
    cout<<"Rythme de croissance"<<m_sommets.size()<<endl;
    cin>>r;
    cout<<"Capacite de l'environnement"<<m_sommets.size()<<endl;
    cin>>k;
    cout <<"##########################"<<endl;


    m_sommets.push_back( new Sommet(nom_im, num,0, 500, 400, k, 0, r,this));
    this->m_ordre++;
}

void Graphe:: supr_som(Sommet* s)
{
    int var_temp=s->m_arc_adj.size();
    unsigned int i=0;
    int j=0;
    while(j!=var_temp)
    {
        supr_arc(s->m_arc_adj.front());

        j++;
    }

    m_ordre--;


    while(m_sommets[i]!=s and i<m_sommets.size())
    {
        i++;
    }
    //appel surp ar pour les arètes adjacentes avec un for
    if(m_sommets.size()&&i<m_sommets.size())
    {

        m_sommets.erase(m_sommets.begin()+i-1);
    }

    m_cadre.remove_child(s->m_case);



}



void Graphe:: ajout_arc()
{
    Sommet* s1;
    Sommet* s2;
    int num;
    int ss1,ss2;

    cout <<"##########################"<<endl;
    cout <<"Inserez le numero de l'arc"<<endl;
    if(m_arcs.size()!=0)
        cout<<"Le numero de l'arc doit etre superieur a "<<m_arcs[m_arcs.size()-1]->m_num_arc<<endl;
    cin>>num;

    cout<<"Quel est l'indice du sommet de depart"<<endl;
    cin>>ss1;
    cout<<"Quel est l'indice du sommet d'arrivee"<<endl;
    cin>>ss2;
    cout <<"##########################"<<endl;
    for(int i=0;i<m_ordre;i++)
    {
        if(ss1==m_sommets[i]->m_num_sommet)
            s1=m_sommets[i];
        if(ss2==m_sommets[i]->m_num_sommet)
            s2=m_sommets[i];
    }

    m_arcs.push_back( new Arc(s1, s2,  0, num,this));

}


//actualiser tous les widgets
int Graphe::update()
{
    int sortie=0;
    for (int i=0;i<m_ordre;i++)
    {
        //le nombre d'individus evolue en fonction du slider
        m_sommets[i]->m_N = m_sommets[i]->m_slider.get_value();
        //affichage du nombre dans le widget texte sous le slider
        m_sommets[i]->m_valeur.set_message( std::to_string( (int)m_sommets[i]->m_N) );
    }


    for(unsigned int i=0;i<m_arcs.size();i++)
    {
        //le poids evolue en fonction du slider
        m_arcs[i]->m_weight = m_arcs[i]->m_slider.get_value();
        //affichage du poids dans le widget texte sous le slider
        m_arcs[i]->m_valeur.set_message( std::to_string( (int)m_arcs[i]->m_weight)) ;
    }

    m_cadre.update();

    if ( m_sauvegarder.clicked() )//pour l'activation des boutons
    {
        sauvegarde(m_nom);
    }
    if (m_menu.clicked())
    {
        cout <<"##########################"<<endl;
        cout<<"Voulez-vous vraiment quitter ?"<<endl;
        string yes;
        cin>>yes;
        cout <<"##########################"<<endl;
        if (yes[0]=='y'||yes[0]=='Y'||yes[0]=='o'||yes[0]=='O')
            sortie=9;
    }
    else sortie=0;

    if(m_connexite.clicked())
    {
        vector<vector<Sommet *>> infos;
        infos=forte_connex(this);
        unsigned int maxi=infos.size();

        cout <<"##########################"<<endl;
        cout <<"La fonction de forte connexite a ete executee"<<endl;
        cout<<"il ya "<<maxi<<" composantes connexes"<<endl;

        for(unsigned int i=0;i<maxi;i++)
        {
            cout<<"composante connexe "<<i+1<<endl;
            for(unsigned int j=0;j<infos[i].size();j++)
            {
                cout <<"--sommet"<<infos[i][j]->m_num_sommet<<endl;
            }
        }
        cout <<"##########################"<<endl;
    }

    if(m_kconnexite.clicked())
    {
        int x;
        x=k_con(this);
        cout <<"##########################"<<endl;
        cout <<"La fonction de k-connexite a ete executee"<<endl;
        cout <<"Afin de rendre ce graphe non connexe il faut enlever "<<x<<" sommets au minimum"<<endl;
        cout <<"##########################"<<endl;
    }

    if(m_simulation.clicked())
    {
        int temps;
        Sommet* s;
        bool stop=false;
        int num;

        cout <<"##########################"<<endl;
        cout<<"L'unite de temps est le mois"<<endl;
        cout<<"Quelle sera la duree de la simulation ?"<<endl;
        cin>>temps;
        cout<<"Quel l'index du sommet sur lequel l'evolution est analysee ?"<<endl;
        cin>>num;
        cout <<"##########################"<<endl;
        evol_n1_gene(temps,this);
        for(int i=0;i<m_ordre;i++)
        {
            if(num==m_sommets[i]->m_num_sommet)
                s=m_sommets[i];
        }
        Simulateur* fenetre;
        fenetre= new Simulateur(s,temps);
        while ( stop==false)
                {
                    /// Il faut appeler les méthodes d'update des objets qui comportent des widgets
                    stop=fenetre->update();

                    /// Mise à jour générale (clavier/souris/buffer etc...)
                    grman::mettre_a_jour();
                }

    }

    if(m_nouveaus.clicked())
        ajout_som();

    if(m_nouveaua.clicked())
        ajout_arc();

    for(int i=0; i<m_ordre;i++)
    {
        if (m_sommets[i]->m_supprimer.clicked())
        {
            supr_som(m_sommets[i]);
        }
    }
    for(unsigned int j=0; j<m_arcs.size();j++)
    {
        if (m_arcs[j]->m_supprimer.clicked())
        {
            supr_arc(m_arcs[j]);
        }
    }

    return sortie;
}
