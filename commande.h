#ifndef COMMANDE_H
<<<<<<< Updated upstream
#define COMMANDE_H

#include "produit.h"
#include "client.h"
namespace vente{

	class Commande
	{
	public:
		enum Status{
			Pending,
			Done,
			Cancelled
		};

		Commande(Client client, Produit produit, Status status);
	private:
		 Client _customer;
		 std::vector<Produit> bought_products;
		
		
	};
}



#endif
=======
#define  COMMANDE_H

#include <iostream>
#include <string>
#include <vector>
#include "client.h"
#include "produit.h"

namespace vente{

  class Commande{

    public:
      //Enumération des différents statuts possible pour une commande
      enum Statut{
        Valide, EnAttente, Refuse
      };
      //Constructeur
      Commande(int numero,Client client);

      //Accesseurs
      void setStatut(Statut s);

      Statut getStatut() const;
      Client getClient() const;
      int getNumero() const;
      std::vector<Produit> getProducts() const;

    private:
      //Numéro de commande
      int _numero;
      //Client qui à passé la Commande
      Client _client;
      //Produit(s) acheté par le client
      std::vector<Produit> m_products;
      //Statut de la commande
      Statut _statut;

      //fonction d'affichage pour la surcharge d'opérateur
      std::string display() const;
  };

}

#endif
>>>>>>> Stashed changes
