#include "magasin.h"
#include <iostream>
#include <algorithm>
#include <random>

namespace vente {
	Magasin::Magasin(){}

	void Magasin::addProduct(Produit produit){
		m_products.push_back(produit);
	}

	void Magasin::displayAllProducts() const {
		for (int i=0; i<75;i++){
			std::cout<<"-";
		}
		std::cout<<std::endl;
		std::cout<<"|Produits";
		for (int i=0; i<65 ;i++){
			std::cout<<" ";
		}
		std::cout<<"|"<<std::endl;
		std::cout<<"|";
		for (int i=0; i<73;i++){
			std::cout<<"-";
		}
		std::cout<<"|"<<std::endl;
		std::cout<<"|Name             Description                       Quantity      Price   |"<<std::endl;

		std::cout<<"|";
		for (int i=0; i<73;i++){
			std::cout<<"-";
		}
		std::cout<<"|"<<std::endl;
		for(int i=0; i<int(m_products.size());i++){
			std::cout<<"|";
			std::cout<<m_products.at(i);
			std::cout<<"|";
			std::cout<<std::endl;
		}
		for (int i=0; i<75;i++){
			std::cout<<"-";
		}
		std::cout<<std::endl;
	}

	void Magasin::displayProduct(std::string name){
		auto it = m_products.begin();
 			it = std::find_if(it, m_products.end(),
 			[name](const Produit produit) {
 				return produit.getName()==name;
 			});
 		int index = std::distance(m_products.begin(), it);
 		for (int i=0; i<75;i++){
			std::cout<<"-";
		}
		std::cout<<std::endl;
		std::cout<<"|Details du produit";
		for (int i=0; i<55 ;i++){
			std::cout<<" ";
		}
		std::cout<<"|"<<std::endl;
		std::cout<<"|";
		for (int i=0; i<73;i++){
			std::cout<<"-";
		}
		std::cout<<"|"<<std::endl;
		std::cout<<"|Name             Description                       Quantity      Price   |"<<std::endl;

		std::cout<<"|";
		for (int i=0; i<73;i++){
			std::cout<<"-";
		}
		std::cout<<"|"<<std::endl;
			std::cout<<"|";
			std::cout<<m_products.at(index);
			std::cout<<"|";
			std::cout<<std::endl;

		for (int i=0; i<75;i++){
			std::cout<<"-";
		}
		std::cout<<std::endl;
	}

	void Magasin::updateQuantity(std::string prodname, int quantity){
		auto it = m_products.begin();
 			it = std::find_if(it, m_products.end(),
 			[prodname](const Produit produit) {
 				return produit.getName()==prodname;
 			});
 		int index = std::distance(m_products.begin(), it);
 		m_products.at(index).setQuantity(quantity);
	}

	bool Magasin::checkUids(int testnb){
		auto it = std::find(m_uids.begin(), m_uids.end(), testnb);
		if (it != m_uids.end()){
			return true;
		}

			return false;
	}


	void Magasin::addCustomer(std::string prenom, std::string nom){
		int uid=rand();
		while(checkUids(uid)==true){
			uid=rand();
		}
		vente::Client client(uid,nom,prenom);
		m_uids.push_back(uid);
		m_clients.push_back(client);
	}


	void Magasin::displayCustomers(){
		for (int i=0; i<75;i++){
			std::cout<<"-";
		}
		std::cout<<std::endl;
		std::cout<<"|Clients";
		for (int i=0; i<66 ;i++){
			std::cout<<" ";
		}
		std::cout<<"|"<<std::endl;
		std::cout<<"|";
		for (int i=0; i<73;i++){
			std::cout<<"-";
		}
		std::cout<<"|"<<std::endl;
		std::cout<<"|ID            Full name                                                  |"<<std::endl;
		for(int i=0; i<int(m_clients.size());i++){
			std::cout<<"|";
			std::cout<<m_clients.at(i);
			std::cout<<"|";
			std::cout<<std::endl;
		}
		for (int i=0; i<75;i++){
			std::cout<<"-";
		}
		std::cout<<std::endl;
	}

	void Magasin::displayCustomer(int uid){
		if (checkUids(uid)==true){
		auto it = m_clients.begin();
 			it = std::find_if(it, m_clients.end(),
 			[uid](const Client client) {
 				return client.getID()==uid;
 			});
 		int index = std::distance(m_clients.begin(), it);
 		
 		for (int i=0; i<75;i++){
			std::cout<<"-";
		}
		std::cout<<std::endl;
		std::cout<<"|Client";
		for (int i=0; i<67 ;i++){
			std::cout<<" ";
		}
		std::cout<<"|"<<std::endl;
		std::cout<<"|";
		for (int i=0; i<73;i++){
			std::cout<<"-";
		}
		std::cout<<"|"<<std::endl;
		std::cout<<"|ID            Full name                                                  |"<<std::endl;
		
			std::cout<<"|";
			std::cout<<m_clients.at(index);
			std::cout<<"|";
			std::cout<<std::endl;
		
		for (int i=0; i<75;i++){
			std::cout<<"-";
		}
	}

	else{
		std::cout<<"Client non trouvé!"<<std::endl;
	}
	}

	bool Magasin::checkOrderNum(int testnb){
		auto it = std::find(orders_num.begin(), orders_num.end(), testnb);
		if (it != orders_num.end()){
			return true;
		}

			return false;
	}

	void Magasin::addOrder(std::string prenom, std::string nom){
		
		int num=rand();
		while(checkOrderNum(num)==true){
			num=rand();
		}
		auto it = m_clients.begin();
 			it = std::find_if(it, m_clients.end(),
 			[nom,prenom](const Client client) {
 				return (client.getName()==nom && client.getFirstName()==prenom);
 			});
 		int index = std::distance(m_clients.begin(), it);
 		Commande order(num,m_clients.at(index));
		m_orders.push_back(order);
	}

	void Magasin::validateCommande(int orderNum){
			auto it = m_orders.begin();
 			it = std::find_if(it, m_orders.end(),
 			[orderNum](const Commande order) {
 				return (order.getNumero()==orderNum);
 			});
 		int index = std::distance(m_orders.begin(), it);
			m_orders.at(index).setStatut(Commande::Statut::Valide);
		}

	void Magasin::switchStatuts(int orderNum, Commande::Statut s){
		auto it = m_orders.begin();
 			it = std::find_if(it, m_orders.end(),
 			[orderNum](const Commande order) {
 				return (order.getNumero()==orderNum);
 			});
 		int index = std::distance(m_orders.begin(), it);
			m_orders.at(index).setStatut(s);
		}

	void Magasin::displayOrders(){
		for (int i=0; i<75;i++){
			std::cout<<"-";
		}
		std::cout<<std::endl;
		std::cout<<"|Commande";
		for (int i=0; i<65 ;i++){
			std::cout<<" ";
		}
		std::cout<<"|"<<std::endl;
		std::cout<<"|";
		for (int i=0; i<73;i++){
			std::cout<<"-";
		}
		std::cout<<"|"<<std::endl;
		std::cout<<"|Numero      Client                   Statut          Produits            |"<<std::endl;
		for(int i=0;i<int(m_orders.size());i++){
			std::cout<<"|";
			std::cout<<m_orders.at(i);
			
			std::cout<<std::endl;
		}
		for (int i=0; i<75;i++){
			std::cout<<"-";
		}
	}


	void Magasin::displayCustomer(std::string prenom, std::string nom){
		auto it = m_clients.begin();
 			it = std::find_if(it, m_clients.end(),
 			[nom,prenom](const Client client) {
 				return (client.getName()==nom && client.getFirstName()==prenom);
 			});
 		int index = std::distance(m_clients.begin(), it);

 		for (int i=0; i<75;i++){
			std::cout<<"-";
		}
		std::cout<<std::endl;
		std::cout<<"|Client";
		for (int i=0; i<67 ;i++){
			std::cout<<" ";
		}
		std::cout<<"|"<<std::endl;
		std::cout<<"|";
		for (int i=0; i<73;i++){
			std::cout<<"-";
		}
		std::cout<<"|"<<std::endl;
		std::cout<<"|ID            Full name                                                  |"<<std::endl;
		
			std::cout<<"|";
			std::cout<<m_clients.at(index);
			std::cout<<"|";
			std::cout<<std::endl;
		
		for (int i=0; i<75;i++){
			std::cout<<"-";
		}
		std::cout<<std::endl;
	}

	void Magasin::addProductCart(std::string nproduit, std::string prenom, std::string nom){
		auto itC = m_clients.begin();
 			itC = std::find_if(itC, m_clients.end(),
 			[nom,prenom](const Client client) {
 				return (client.getName()==nom && client.getFirstName()==prenom);
 			});
 		int indexClient = std::distance(m_clients.begin(), itC);

 		auto itP = m_products.begin();
 			itP = std::find_if(itP, m_products.end(),
 			[nproduit](const Produit produit) {
 				return produit.getName()==nproduit;
 			});
 		int indexproduct = std::distance(m_products.begin(), itP);

 		m_clients.at(indexClient).add(m_products.at(indexproduct));


	}

	void Magasin::addProductCart(std::string nproduit,int uid){
		auto itC = m_clients.begin();
 			itC = std::find_if(itC, m_clients.end(),
 			[uid](const Client client) {
 				return client.getID()==uid;
 			});
 		int indexC = std::distance(m_clients.begin(), itC);

 		auto itP = m_products.begin();
 			itP = std::find_if(itP, m_products.end(),
 			[nproduit](const Produit produit) {
 				return produit.getName()==nproduit;
 			});
 		int indexproduct = std::distance(m_products.begin(), itP);

 		m_clients.at(indexC).add(m_products.at(indexproduct));


	}
	void Magasin::updateProductQuantityCart(std::string nproduit,int quantity ,std::string prenom, std::string nom){
		auto itC = m_clients.begin();
 			itC = std::find_if(itC, m_clients.end(),
 			[nom,prenom](const Client client) {
 				return (client.getName()==nom && client.getFirstName()==prenom);
 			});
 		int indexClient = std::distance(m_clients.begin(), itC);

 		auto itP = m_products.begin();
 			itP = std::find_if(itP, m_products.end(),
 			[nproduit](const Produit produit) {
 				return produit.getName()==nproduit;
 			});
 		int indexproduct = std::distance(m_products.begin(), itP);
 		m_clients.at(indexClient).modifyQuantity(m_products.at(indexproduct),quantity);

	}

	void Magasin::removeProductCart(std::string nproduit, std::string prenom, std::string nom){
			auto itC = m_clients.begin();
 			itC = std::find_if(itC, m_clients.end(),
 			[nom,prenom](const Client client) {
 				return (client.getName()==nom && client.getFirstName()==prenom);
 			});
 		int indexClient = std::distance(m_clients.begin(), itC);

 		auto itP = m_products.begin();
 			itP = std::find_if(itP, m_products.end(),
 			[nproduit](const Produit produit) {
 				return produit.getName()==nproduit;
 			});
 		int indexproduct = std::distance(m_products.begin(), itP);
 		m_clients.at(indexClient).deleteProduct(m_products.at(indexproduct));
	}

	void Magasin::clearCart(std::string prenom, std::string nom){
		auto itC = m_clients.begin();
 			itC = std::find_if(itC, m_clients.end(),
 			[nom,prenom](const Client client) {
 				return (client.getName()==nom && client.getFirstName()==prenom);
 			});
 		int indexClient = std::distance(m_clients.begin(), itC);
 		m_clients.at(indexClient).clearProducts();

	}
}
