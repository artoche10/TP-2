#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include <vector>
#include "produit.h"

namespace vente{

    class Client{

      public :
      //Constructeurs de la classe Client
      Client(int id);
      Client(int id, std::string name, std::string firstName);

      //Accesseurs des attrbuts du de la classe Client
      void setName(std::string name);
      void setFirstName(std::string firstName);

      int getID() const;
      std::string getName() const;
      std::string getFirstName() const;
      std::vector<Produit> getProducts() const;
      std::vector<int> getProductsQuantity() const;

      //Méthode d'ajout d'un produit "product" dans le panier
      void add(Produit product);
      //Méthode qui vide le panier
      void clearProducts();
      //Méthode qui modifie la quantité d'un produit du panier
      void modifyQuantity(Produit product, int quantity);
      //Méthode qui supprime un élément du panier
      void deleteProduct(Produit product);

      //Surcharge de l'opérateur << pour l'affichage
      friend std::ostream& operator << (std::ostream &flux, const Client& c);

      private :
      //Identifiant du client
      int _id;
      //Nom du client
      std::string _name;
      //Prénom du client
      std::string _firstName;
      //Panier de client (liste de produit)
      std::vector<Produit> m_products;
      //Quantité d'un même produit dans le panier du client
      std::vector<int> _productQuantity;

      //fonction d'affichage pour la surcharge d'opérateur
      std::string display() const;
    };
}
#endif
