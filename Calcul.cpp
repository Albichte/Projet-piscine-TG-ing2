#include "Graphe.h"
#include <queue>

void Graphe:: evol_n1_gene(int tps, Graphe* graphique)
{

    for(int i=0; i<graphique->m_ordre; i++)
    {
        graphique->m_sommets[i]->m_N_histo.clear();
        for(int j=0;j<tps;j++)
        {
            graphique->m_sommets[i]->evol_n1_som();

        }
    }
}

void Graphe::marq_vois(Sommet* s)
{
    for(unsigned int i=0; i<s->m_succe.size(); i++)
    {
        s->m_succe[i]->m_marque=true;
    }
}

bool Graphe:: compo_con_inv(Graphe* graphique, Sommet* s_deb, Sommet* s_atrouv)
{
    // fonction qui permet de savoir si il existe un chemin d'un sommet
    // à un autre
    //on garde les anciencs marquages en mémoire
    vector<int> histo_marquage;
    for(unsigned int i=0; i<graphique->m_sommets.size(); i++)
    {
        if(graphique->m_sommets[i]->m_marque)
        {
            histo_marquage.push_back(1);
        }
        else
        {
            histo_marquage.push_back(0);
        }
    }
    // on reset les marquages pour pouvoir faire le BFS sur le graph
    graphique->reset_marquages_som();

    //variables qui sont nescessaires au BFS
    queue<Sommet*> queue_som;
    queue_som.push(s_deb);
    queue_som.front()->m_marque=true;
    while (queue_som.size()!=0 and queue_som.front()!=s_atrouv)
    {
        for(unsigned int i=0; i<queue_som.front()->m_succe.size(); i++)
        {
            if(queue_som.front()->m_succe[i]->m_marque==false)
            {
                queue_som.front()->m_succe[i]->m_marque=true;
                queue_som.push(queue_som.front()->m_succe[i]);
            }
        }
        queue_som.pop();
    }
    for(unsigned int i=0; i<m_sommets.size();i++)
    {
        if(histo_marquage[i])
        {
            m_sommets[i]->m_marque=true;
        }
        else
        {
            m_sommets[i]->m_marque=false;
        }
    }


    if(queue_som.size()==0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

vector<Sommet*>  Graphe::compo_f_con_som(Graphe* graphique, Sommet* s1)
{
    //Reset des marquages
    graphique->reset_marquages_som();
    //on déclare la file d'attente et le vecteur pour la composante
    // fortement connexe
    vector<Sommet*> compo_f_con;
    queue<Sommet*> file_attente;
    file_attente.push(s1);
    compo_f_con.push_back(s1);
    while(file_attente.size()!=0)
    {
        for(unsigned int i=0; i<file_attente.front()->m_succe.size(); i++)
        {
            if(file_attente.front()->m_succe[i]->m_marque==false)
            {
                file_attente.front()->m_succe[i]->m_marque=true;
                file_attente.push(file_attente.front()->m_succe[i]);
            }
        }
        if(file_attente.front()!=s1)
        {
            if(compo_con_inv(graphique, file_attente.front(),s1))
            {
                compo_f_con.push_back(file_attente.front());
            }
        }
        file_attente.pop();
    }

    return compo_f_con;
}


// debeuguer demain. 2/3 de chances que ça déconne.
//fonction retournant toutes les composantes connexes
vector<vector<Sommet *>> Graphe:: forte_connex(Graphe* graphique)
{
    vector<vector<Sommet*>> tt_compo_con;
    for(unsigned int i=0; i<graphique->m_sommets.size(); i++)
    {
        if(compo_f_con_som(graphique,graphique->m_sommets[i]).size()>1)
        {
        tt_compo_con.push_back(compo_f_con_som(graphique,graphique->m_sommets[i]));
        }
    }

    // On doit trier les vecteurs pour ensuite faire un unique (de notre propre cru également)
    //0n déclare un autre vecteur pour trier

    Sommet* som_temp;
    for(unsigned int i=0; i<tt_compo_con.size(); i++)
    {int erreur=1;
        while(erreur)
        {
            erreur=0;
            for(unsigned int j=0; j<tt_compo_con[i].size()-1; j++)
            {
                if(tt_compo_con[i][j]>tt_compo_con[i][j+1])
                {
                    som_temp=tt_compo_con[i][j];
                    tt_compo_con[i][j]=tt_compo_con[i][j+1];
                    tt_compo_con[i][j+1]=som_temp;
                    erreur++;
                }
            }
        }
    }



    // On vérifie maintenant l'unicité des vecteurs
    unsigned int i=0,j=0;
    while(i!=tt_compo_con.size() && i<tt_compo_con.size())
    {
        j=i;
        while(j!=tt_compo_con.size() && j<tt_compo_con.size())
        {
            if(tt_compo_con[i].size()==tt_compo_con[j].size())
            {
                if(tt_compo_con[i][1]==tt_compo_con[j][1])
                {
                    tt_compo_con.erase(tt_compo_con.begin()+j);
                }
            }
            j++;
        }
        i++;
    }


    graphique->reset_marquages_som();
    return tt_compo_con;

}
bool Graphe::connexe(Graphe* graphique)
{
    //sauvegarde des marquages des sommets
    vector<bool> histo_marq;
    for(unsigned int i=0; i<graphique->m_sommets.size(); i++)
    {
        histo_marq.push_back(graphique->m_sommets[i]->m_marque);
    }
    graphique->reset_marquages_som();
    // on effectue un bfs pour savoir si le graphe est connexe
    queue <Sommet*> file_attente;
    file_attente.push(graphique->m_sommets[0]);
    graphique->m_sommets[0]->m_marque=true;
    while(file_attente.size())
    {
        for(unsigned int i=0; i<file_attente.front()->m_succe.size(); i++)
        {
            if(!file_attente.front()->m_succe[i]->m_marque && file_attente.front()->m_succe[i]->m_actif==true )
            {
                file_attente.front()->m_succe[i]->m_marque=true;
                file_attente.push(file_attente.front()->m_succe[i]);
            }
        }
        int compt_erreur=0;
        for(unsigned int i=0; i<file_attente.front()->m_prede.size(); i++)
        {
            compt_erreur=0;
            for(unsigned int j=0;j<file_attente.front()->m_succe.size();j++)
            {
                if(file_attente.front()->m_prede[i]==file_attente.front()->m_succe[j])
                {
                    compt_erreur++;
                }
            }

            if(!file_attente.front()->m_prede[i]->m_marque &&compt_erreur==0 &&file_attente.front()->m_prede[i]->m_actif==true)
            {
                file_attente.front()->m_prede[i]->m_marque=true;
                file_attente.push(file_attente.front()->m_prede[i]);
            }
        }
        file_attente.pop();
    }
    unsigned int count_actif=0;
    unsigned int count_marque=0;
    for(unsigned int i =0; i<graphique->m_sommets.size(); i++)
    {
        if(graphique->m_sommets[i]->m_marque==true&&graphique->m_sommets[i]->m_actif==true)
        {
            count_marque++;
        }
        if(graphique->m_sommets[i]->m_actif==true)
        {
            count_actif++;
        }
    }



    bool resultat;
      if(count_marque==count_actif)
    {
        resultat=true;
    }
    else
    {
        resultat=false;
    }

    //remise à l'identique des marquages des sommets
    graphique->reset_marquages_som();
    for(unsigned int i=0; i<graphique->m_sommets.size(); i++)
    {
        graphique->m_sommets[i]->m_marque=histo_marq[i];
    }
    return resultat;

}


bool Graphe::tt_possi(Graphe* graphique, int i)
{
    bool test=true;
    for(unsigned int j=0; j<graphique->m_sommets.size(); j++)
    {
        graphique->m_sommets[j]->m_actif=false;
        cout<<graphique->m_sommets[j]->m_num_sommet<<"  est désactivé"<<endl;
        cout<<"le graphe est connexe 1 ou 0 : "<<connexe(graphique)<<endl;
        if(i>0)
        {cout<<"totoestkoul    "<<i<<endl;
            test=tt_possi(graphique,i-1);

        }
        else
        {
           test=connexe(graphique);
        }
        if(test==false)
        {
            return false;
        }
        graphique->m_sommets[j]->m_actif=true;
    }
    return true;
}


int Graphe::k_con(Graphe* graphique)
{
    int retour=0;
    int i=0;
    bool test=true;
    if(connexe(graphique))
    {cout<<"coucou"<<endl;
        while(test)
        {
            test=tt_possi(graphique, i);

            cout<<i<<"    ninxeixe"<<endl;
            i++;
        }
        retour= i;
    }
    else
    {
        retour= 0;
    }

    graphique->reset_actif_som();
    graphique->reset_marquages_som();
    graphique->reset_actif_arc();
    graphique->reset_marquages_arc();

    return retour;

}



