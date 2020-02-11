//high_resolution_clock example
#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>
//TODO Changer l'importation de votre conteneur
#include <string>
#include <fstream>
#include <map>
#include <set>
#include <algorithm>

//TODO changer la valeur de N pour chaque test : 10, 50, 100, 1000, 10000, 100000, 1000000 valeurs
const int N = 10;

float test_ajout(int n, float S);
float test_lecture(int n, float S);
float test_erase(int n, float S);
float test_clean(float S);

float test_copie1(float S);
float test_copie2(float S);


float test_union1(float S);


float test_find(int n, float S);
float test_count(int n, float S);
float test_copie3(float S);
float test_swap(float S);
float test_replace(int n1, int n2, float S);
float test_fill(int n, float S);
float test_remove(int n, float S);
float test_unique(float S);
float test_reverse(float S);
float test_rotate(float S);
float test_random_shuffle(float S);
float test_sort(float S);
float test_min(float S);
float test_max(float S);
float test_min_element(float S);
float test_max_element(float S);
float test_union2(float S);
float test_intersect(float S);



int main ()
{
    int n = 1;
    double S = 0.0f;  
    //write a file storing all the sampled points
    std::ofstream ofs;
    //TODO Changer le nom du conteneur
    std::string conteneur = "set";
    std::string filename = "data"+conteneur+".m";
    ofs.open(filename,std::fstream::app);

    if(ofs.good()==false)
        throw std::exception();

    //Initialisation des données dans le fichier matlab
    if (N == 10){
        ofs << "x" << N << "= [" << N << ","<<std::endl;
    } else {
        ofs << N << ","<<std::endl;
    }
    /***************************
     * Ajout dans le conteneur *
     * ************************/
    //ofs <<"//Calcul du temps d'ajout au début"<<std::endl;
    for (int k = 0; k < n ; k++){
        S = test_ajout(1,S);
    }
    ofs << S/n << ","<<std::endl;
    S = 0.0f;
    //ofs <<"//Calcul du temps d'ajout à la fin"<<std::endl;
    for (int k = 0; k < n ; k++){
        S = test_ajout(N,S);
    }
    ofs << S/n << ","<<std::endl;
    S = 0.0f;

    //ofs <<"//Calcul du temps d'ajout aléatoire"<<std::endl;
    for (int k = 0; k < n ; k++){
        S = test_ajout(N/2,S);
    }    
    ofs << S/n << ","<<std::endl;
    S = 0.0f;

    /***************************
     * Lecture dans le conteneur *
     * ************************/
    //ofs <<"//Calcul du temps d'ajout au début"<<std::endl;
    for (int k = 0; k < n ; k++){
        S = test_lecture(1,S);
    }    
    ofs << S/n << ","<<std::endl;
    S = 0.0f;

    //ofs <<"//Calcul du temps d'ajout à la fin"<<std::endl;
    for (int k = 0; k < n ; k++){
        S = test_lecture(N,S);
    }    
    ofs << S/n << ","<<std::endl;
    S = 0.0f;

    //ofs <<"//Calcul du temps d'ajout aléatoire"<<std::endl;
    for (int k = 0; k < n ; k++){
        S = test_lecture(N/2,S);
    }    
    ofs << S/n << ","<<std::endl;
    S = 0.0f;
    
    if (N >= 1000000){
        ofs << "];";
    } else {
        ofs << ";\n";
    }
    S = 0.0f;



///////////////////////////////////////
    //ofs <<"//Calcul du temps de recherche d'un element"<<std::endl;
    for (int k = 0; k < n ; k++){
        S = test_find(N/2,S);
    }
    ofs << S/n << ","<<std::endl;
    S = 0.0f;

    //ofs<<"//Calcul du temps de count d'un element "<<std::endl;
    for (int k = 0; k < n ; k++){
        S = test_count(N/2,S);
    }
    ofs << S/n << ","<<std::endl;
    S = 0.0f;

    //ofs<<"Calcul du temps de copie3"<<std::endl;
    for (int k = 0; k < n ; k++){
        S = test_copie3(S);}

    ofs << S/n << ","<<std::endl;
    S = 0.0f;

    //ofs<<"Calcul du temps de swap"<<std::endl;
    for (int k = 0; k < n ; k++){
        S = test_swap(S);
    }
    ofs << S/n << ","<<std::endl;
    S = 0.0f;

    //ofs<<"Calcul du temps de replace"<<std::endl;
    for (int k = 0; k < n ; k++){
        S = test_replace(8,800,S);
    }
    ofs << S/n << ","<<std::endl;
    S = 0.0f;

    //ofs<<"Calcul du temps de fill"<<std::endl;
    for (int k = 0; k < n ; k++){
        S = test_fill(N/2,S);
    }
    //TODO BRALET
    ofs << 0 << ","<<std::endl;
    S = 0.0f;

    //ofs<<"Calcul du temps de remove"<<std::endl;
    for (int k = 0; k < n ; k++){
        S = test_remove(N/2,S);
    }
    //TODO BRALET
    ofs << 0 << ","<<std::endl;
    S = 0.0f;

    //ofs<<"Calcul du temps de unique"<<std::endl;
    for (int k = 0; k < n ; k++){
        S = test_unique(S);
    }
    ofs << 0 << ","<<std::endl;
    S = 0.0f;

    //ofs<<"Calcul du temps de reverse"<<std::endl;
    ofs << 0 << ","<<std::endl;

    //ofs<<"Calcul du temps de rotate"<<std::endl;
    ofs << 0 << ","<<std::endl;

    //ofs<<"Calcul du temps de random_shuffle"<<std::endl;
    ofs << 0 << ","<<std::endl;

    //ofs<<"Calcul du temps de sort"<<std::endl;
    ofs << 0 << ","<<std::endl;




    //ofs<<"Calcul du temps de min"<<std::endl;
    for (int k = 0; k < n ; k++){
        S = test_min(S);
    }
    ofs << S/n << ","<<std::endl;
    S = 0.0f;

    //ofs<<"Calcul du temps de max"<<std::endl;
    for (int k = 0; k < n ; k++){
        S = test_max(S);
    }
    ofs << S/n << ","<<std::endl;
    S = 0.0f;

    //ofs<<"Calcul du temps de min_element"<<std::endl;
    for (int k = 0; k < n ; k++){
        S = test_min_element(S);
    }
    ofs << S/n << ","<<std::endl;
    S = 0.0f;


    //ofs<<"Calcul du temps de max_element"<<std::endl;
    for (int k = 0; k < n ; k++){
        S = test_max_element(S);
    }
    ofs << S/n << ","<<std::endl;
    S = 0.0f;


    //ofs<<"//Calcul du temps d'union2"<<std::endl;
    for (int k = 0; k < n ; k++){
        S = test_union2(S);
    }
    ofs << S/n << ","<<std::endl;
    S = 0.0f;

        
    //ofs<<"//Calcul du temps d'inserction"<<std::endl;
    for (int k = 0; k < n ; k++){
        S = test_intersect(S);
    }
    ofs << S/n << ","<<std::endl<<std::endl;
    S = 0.0f;


    ofs.close();


    return 0;

}

float test_ajout(int n, float S){
    //TODO Ajouter ici la création du conteneur
    std::set<int>test;	
    for (int i=1; i<=N; i++) test.insert(2*i+1);

	std::cout<<"setbaseajout"<<std::endl;
	for(auto const& value: test)
    	std::cout<<value<<" ";
    std::cout<<std::endl;
    
    //TODO bien spécifier le type et la valeur à ajouter

    std::chrono::high_resolution_clock::time_point td1;
    std::chrono::high_resolution_clock::time_point td2;
    //TODO A DECOMMENTER SI IL EXISTE UNE FONCTION PUSH_BACK
    
    if (n == N) {
    	//int max_tab = max(init_tab)
        td1 = std::chrono::high_resolution_clock::now();
        test.insert(2*n+2);
        td2 = std::chrono::high_resolution_clock::now();
        //Calcul du temps ecoule
        std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(td2 - td1);
        double tps_ecoule = time_span.count();    
    
        S += tps_ecoule;

		std::cout<<"ajout fin"<<std::endl;
		for(auto const& value: test)
	    	std::cout<<value<<" ";
	    std::cout<<std::endl;

        return S;
    }
    
    
    //TODO A DECOMMENTER SI IL EXISTE UNE FONCTION PUSH_FRONT
    
    if (n == 1) {
    	//int min_tab = min(init_tab)
        td1 = std::chrono::high_resolution_clock::now();
        test.insert(1);
        td2 = std::chrono::high_resolution_clock::now();
        //Calcul du temps ecoule
        std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(td2 - td1);
        double tps_ecoule = time_span.count();    
    
        S += tps_ecoule;

		std::cout<<"ajout_debut"<<std::endl;
		for(auto const& value: test)
	    	std::cout<<value<<" ";
	    std::cout<<std::endl;

        return S;
    }
    

    if (n == N/2) {
    	//int moy_tab = max(init_tab)-min(init_tab)
        td1 = std::chrono::high_resolution_clock::now();
        test.insert(2*n);
        td2 = std::chrono::high_resolution_clock::now();
        //Calcul du temps ecoule
        std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(td2 - td1);
        double tps_ecoule = time_span.count();    
    
        S += tps_ecoule;

		std::cout<<"ajout milieu"<<std::endl;
		for(auto const& value: test)
	    	std::cout<<value<<" ";
	    std::cout<<std::endl;

        return S;
    }
    
    //TODO A DECOMMENTER SI L'OPERATEUR [] EXISTE
    
    //Permet d'obtenir le temps de départ avec la meilleure précision
    //td1 = std::chrono::high_resolution_clock::now();
    //Ajout d'une variable
    //test.insert(a);
    //Permet d'obtenir le teps à la fin du code avec la meilleure précision
    //td2 = std::chrono::high_resolution_clock::now();
    
    /*
    //TODO A DECOMMENTER SI L'OPERATEUR [] N'EXISTE PAS
    if (n==0){
        td1 = std::chrono::high_resolution_clock::now();
        *test.begin() = a;
        td2 = std::chrono::high_resolution_clock::now();
    } else {
        td1 = std::chrono::high_resolution_clock::now();
        auto it = test.begin();
        for (int k=0; k<n; k++){
            it++;
        }
        *it = a;
        td2 = std::chrono::high_resolution_clock::now();
    }
    */
    //Calcul du temps ecoule
    //std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(td2 - td1);
    //double tps_ecoule = time_span.count();    
    
    // on réalise plusieurs fois l'opéraration et on fait la moyenne ensuite des temps
   // S += tps_ecoule;
    return S;
}

float test_lecture(int n, float S){
    //TODO Ajouter ici la création du conteneur
    std::set<int>test;	
    for (int i=1; i<=N; i++) test.insert(2*i+1);

	std::cout<<"avant_lecture"<<std::endl;
	for(auto const& value: test)
    	std::cout<<value<<" ";
    std::cout<<std::endl;

    
    //TODO Bien spécifier le type de la variable présente dans votre conteneur
    int a;
    std::chrono::high_resolution_clock::time_point td1;
    std::chrono::high_resolution_clock::time_point td2;
    //TODO A DECOMMENTER SI IL N'EXISTE PAS DE FONCTION BACK, FRONT et AT MAIS QUE L'OPERATEUR [] EST DEFINI
    /*
    //Permet d'obtenir le temps de départ avec la meilleure précision
    td1 = std::chrono::high_resolution_clock::now();
    //Lecture d'une variable
    a = test[n];
    //Permet d'obtenir le teps à la fin du code avec la meilleure précision
    td2 = std::chrono::high_resolution_clock::now();
    */
    
    //TODO A DECOMMENTER SI IL N'EXISTE PAS DE FONCTION BACK, FRONT et AT  ET QUE L'OPERATEUR [] N'EST PAS DEFINI
      
    if (n==0) {
            td1 = std::chrono::high_resolution_clock::now();
            a = *(test.begin());
            td2 = std::chrono::high_resolution_clock::now();
            std::cout<<a<<std::endl;
    } else {
            td1 = std::chrono::high_resolution_clock::now();
            auto it1 = test.rbegin();
            for (int k=N ; k != n; k--){
                it1++;
            }
            a = *it1;
            td2 = std::chrono::high_resolution_clock::now();
            std::cout<<a<<std::endl;
    }     
    
    
    
    //ligne pour eviter une erreur de variable unused
    a+=1;
    
    //Calcul du temps ecoule
    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(td2 - td1);
    double tps_ecoule = time_span.count();  
    
    S += tps_ecoule;
    return S;
}

float test_erase(int n, float S){

	std::set<int>test; 
    for (int i=1; i<=N; i++) test.insert(i);

    std::chrono::high_resolution_clock::time_point td1;
    std::chrono::high_resolution_clock::time_point td2;

    td1 = std::chrono::high_resolution_clock::now();

    	test.erase(n);

	td2 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(td2 - td1);
    double tps_ecoule = time_span.count();  
    
    S += tps_ecoule;

	std::cout<<"erase"<<std::endl;
	for(auto const& value: test)
    	std::cout<<value<<" ";
    std::cout<<std::endl;

    return S;

}


float test_clean(float S){

	std::set<int>test; 
    for (int i=1; i<=N; i++) test.insert(i);

    std::chrono::high_resolution_clock::time_point td1;
    std::chrono::high_resolution_clock::time_point td2;

    td1 = std::chrono::high_resolution_clock::now();

    	test.clear();

	td2 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(td2 - td1);
    double tps_ecoule = time_span.count();  
    
    S += tps_ecoule;

	std::cout<<"clean"<<std::endl;
	for(auto const& value: test)
    	std::cout<<value<<" ";
    std::cout<<std::endl;

    return S;

}



float test_find(int n, float S){

	std::set<int>test; 
    for (int i=1; i<=N; i++) test.insert(i);

    std::chrono::high_resolution_clock::time_point td1;
    std::chrono::high_resolution_clock::time_point td2;

    std::cout<<"find"<<std::endl;

    td1 = std::chrono::high_resolution_clock::now();

    	std::set<int>::iterator it = test.find(n);
    	std::cout<<*it<<std::endl;
  

	td2 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(td2 - td1);
    double tps_ecoule = time_span.count();  
    
    S += tps_ecoule;
    return S;

}



float test_swap(float S){

	std::set<int>test; 
    for (int i=1; i<=N; i++) test.insert(i);

    std::cout<<"swap01"<<std::endl;
	for(auto const& value: test)
    	std::cout<<value<<" ";
    std::cout<<std::endl;


    std::set<int>test2; 
    for (int i=1; i<=N; i++) test2.insert(i+N);

    std::cout<<"swap02"<<std::endl;
	for(auto const& value: test2)
    	std::cout<<value<<" ";
    std::cout<<std::endl;

    std::chrono::high_resolution_clock::time_point td1;
    std::chrono::high_resolution_clock::time_point td2;

    std::cout<<"swap"<<std::endl;

    td1 = std::chrono::high_resolution_clock::now();

 		test.swap(test2);

	td2 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(td2 - td1);
    double tps_ecoule = time_span.count();  
    
    S += tps_ecoule;

        std::cout<<"swap1"<<std::endl;
	for(auto const& value: test)
    	std::cout<<value<<" ";
    std::cout<<std::endl;

        std::cout<<"swapq2"<<std::endl;
	for(auto const& value: test2)
    	std::cout<<value<<" ";
    std::cout<<std::endl;

    return S;

}

// ne marche pas
float test_replace(int n1,int n2,float S){

	std::set<int>test; 
    for (int i=1; i<=N; i++) test.insert(i);

    std::cout<<"replace1"<<std::endl;
	for(auto const& value: test)
    	std::cout<<value<<" ";
    std::cout<<std::endl;

    std::chrono::high_resolution_clock::time_point td1;
    std::chrono::high_resolution_clock::time_point td2;


    td1 = std::chrono::high_resolution_clock::now();

    	//std::replace(test.begin(),test.end(),n1,n2);

	td2 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(td2 - td1);
    double tps_ecoule = time_span.count();  
    
    S += tps_ecoule;

	std::cout<<"replace2"<<std::endl;
	for(auto const& value: test)
    	std::cout<<value<<" ";
    std::cout<<std::endl;

    return S;

}

float test_fill(int n, float S){

	std::multiset<int>test; 
    for (int i=1; i<=N; i++) test.insert(i);

    std::cout<<"replace1"<<std::endl;
	for(auto const& value: test)
    	std::cout<<value<<" ";
    std::cout<<std::endl;

    std::chrono::high_resolution_clock::time_point td1;
    std::chrono::high_resolution_clock::time_point td2;

    td1 = std::chrono::high_resolution_clock::now();
		//std::fill(test.begin(),&test.end(),n);
	td2 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(td2 - td1);
    double tps_ecoule = time_span.count();  
    
    S += tps_ecoule;

	std::cout<<"replace2"<<std::endl;
	for(auto const& value: test)
    	std::cout<<value<<" ";
    std::cout<<std::endl;

    return S;

}

float test_remove(int n, float S){

	std::set<int>test; 
    for (int i=1; i<=N; i++) test.insert(i);

    std::cout<<"remove1"<<std::endl;
	for(auto const& value: test)
    	std::cout<<value<<" ";
    std::cout<<std::endl;

    std::chrono::high_resolution_clock::time_point td1;
    std::chrono::high_resolution_clock::time_point td2;

    td1 = std::chrono::high_resolution_clock::now();

    	//std::remove(test.begin(),test.end(),n);
	td2 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(td2 - td1);
    double tps_ecoule = time_span.count();  
    
    S += tps_ecoule;

	std::cout<<"remove2"<<std::endl;
	for(auto const& value: test)
    	std::cout<<value<<" ";
    std::cout<<std::endl;

    return S;

}


float test_unique(float S){

	std::multiset<int>test; 
    for (int i=1; i<=N; i++) test.insert(i);
    	test.insert(N/2);
        test.insert(N/2);

    std::cout<<"unique1"<<std::endl;
	for(auto const& value: test)
    	std::cout<<value<<" ";
    std::cout<<std::endl;

    std::chrono::high_resolution_clock::time_point td1;
    std::chrono::high_resolution_clock::time_point td2;

    td1 = std::chrono::high_resolution_clock::now();

    	//std::unique(test.begin(),test.end());
	td2 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(td2 - td1);
    double tps_ecoule = time_span.count();  
    
    S += tps_ecoule;

	std::cout<<"unique2"<<std::endl;
	for(auto const& value: test)
    	std::cout<<value<<" ";
    std::cout<<std::endl;

    return S;

}


float test_min_element(float S){

	std::set<int>test; 
    for (int i=1; i<=N; i++) test.insert(i);

    std::cout<<"min_ele1"<<std::endl;
	for(auto const& value: test)
    	std::cout<<value<<" ";
    std::cout<<std::endl;

    std::chrono::high_resolution_clock::time_point td1;
    std::chrono::high_resolution_clock::time_point td2;

    td1 = std::chrono::high_resolution_clock::now();

    	std::cout << *(std::min_element(test.begin(),test.end())) <<std::endl;

	td2 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(td2 - td1);
    double tps_ecoule = time_span.count();  
    
    S += tps_ecoule;
    return S;

}

float test_max_element(float S){

	std::set<int>test; 
    for (int i=1; i<=N; i++) test.insert(i);

    std::cout<<"max_ele1"<<std::endl;
	for(auto const& value: test)
    	std::cout<<value<<" ";
    std::cout<<std::endl;

    std::chrono::high_resolution_clock::time_point td1;
    std::chrono::high_resolution_clock::time_point td2;

    td1 = std::chrono::high_resolution_clock::now();

    	std::cout << *(std::max_element(test.begin(),test.end())) <<std::endl;

	td2 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(td2 - td1);
    double tps_ecoule = time_span.count();  
    
    S += tps_ecoule;


    return S;

}


float test_max(float S){

	std::set<int>test; 
    for (int i=1; i<=N; i++) test.insert(i);
    	test.insert(2*N+1);

    std::cout<<"max01"<<std::endl;
	for(auto const& value: test)
    	std::cout<<value<<" ";
    std::cout<<std::endl;

    std::set<int>test2; 
    for (int i=1; i<=N; i++) test2.insert(i+N);


    std::cout<<"max11"<<std::endl;
	for(auto const& value: test2)
    	std::cout<<value<<" ";
    std::cout<<std::endl;

    std::chrono::high_resolution_clock::time_point td1;
    std::chrono::high_resolution_clock::time_point td2;

    td1 = std::chrono::high_resolution_clock::now();

    	auto m=max(test,test2);


	td2 = std::chrono::high_resolution_clock::now();


	std::cout<<"max"<<std::endl;
	for(auto const& value: m)
    	std::cout<<value<<" ";
    std::cout<<std::endl;

    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(td2 - td1);
    double tps_ecoule = time_span.count();  
    
    S += tps_ecoule;
    return S;

}


float test_min(float S){

	std::set<int>test; 
    for (int i=1; i<=N; i++) test.insert(i);
    	test.insert(N+1);

    std::cout<<"min01"<<std::endl;
	for(auto const& value: test)
    	std::cout<<value<<" ";
    std::cout<<std::endl;

    std::set<int>test2; 
    for (int i=1; i<=N; i++) test2.insert(i+N);
    	    	test2.insert(0);

    std::cout<<"min11"<<std::endl;
	for(auto const& value: test2)
    	std::cout<<value<<" ";
    std::cout<<std::endl;

    std::chrono::high_resolution_clock::time_point td1;
    std::chrono::high_resolution_clock::time_point td2;

    td1 = std::chrono::high_resolution_clock::now();

    	auto m = min(test,test2);
	td2 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(td2 - td1);
    double tps_ecoule = time_span.count();  

    std::cout<<"min"<<std::endl;
	for(auto const& value: m)
    	std::cout<<value<<" ";
    std::cout<<std::endl;
    
    S += tps_ecoule;
    return S;

}


float test_copie1(float S){

	std::set<int>test; 
    for (int i=1; i<=N; i++) test.insert(i);

    std::chrono::high_resolution_clock::time_point td1;
    std::chrono::high_resolution_clock::time_point td2;

    td1 = std::chrono::high_resolution_clock::now();

    	std::set<int> test2 (test) ;

	td2 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(td2 - td1);
    double tps_ecoule = time_span.count();  
    
    S += tps_ecoule;

	std::cout<<"copie1"<<std::endl;
	for(auto const& value: test2)
    	std::cout<<value<<" ";
    std::cout<<std::endl;

    return S;

}




float test_copie2(float S){

	std::set<int>test; 
    for (int i=1; i<=N; i++) test.insert(i);

    std::chrono::high_resolution_clock::time_point td1;
    std::chrono::high_resolution_clock::time_point td2;

    td1 = std::chrono::high_resolution_clock::now();

    	std::set<int> test2 (test.begin(),test.end());

	td2 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(td2 - td1);
    double tps_ecoule = time_span.count();  
    
    S += tps_ecoule;

	std::cout<<"copie2"<<std::endl;
	for(auto const& value: test2)
    	std::cout<<value<<" ";
    std::cout<<std::endl;

    return S;

}

float test_copie3(float S){

    std::set<int> test; 
    for (int i=1; i<=N; i++) test.insert(i);

    std::chrono::high_resolution_clock::time_point td1;
    std::chrono::high_resolution_clock::time_point td2;

    std::set<int> test_copie; 

    td1 = std::chrono::high_resolution_clock::now();

        std::copy (test.begin(),test.end(),std::inserter(test_copie,test_copie.begin()));

    td2 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(td2 - td1);
    double tps_ecoule = time_span.count();  
    
    S += tps_ecoule;

    std::cout<<"copie3"<<std::endl;
    for(auto const& value: test_copie)
        std::cout<<value<<" ";
    std::cout<<std::endl;

    return S;

}

float test_count(int n,float S){

	std::set<int>test; 
    for (int i=1; i<=N; i++) test.insert(i);

    std::chrono::high_resolution_clock::time_point td1;
    std::chrono::high_resolution_clock::time_point td2;


    std::cout << n;
    td1 = std::chrono::high_resolution_clock::now();

    	if (test.count(n)!=0)
      		std::cout << " is an element of myset.\n";
    	else
      		std::cout << " is not an element of myset.\n";

	td2 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(td2 - td1);
    double tps_ecoule = time_span.count();  
    
    S += tps_ecoule;

	std::cout<<"count"<<std::endl;
	for(auto const& value: test)
    	std::cout<<value<<" ";
    std::cout<<std::endl;

    return S;

}

// equivalent insert pour les sets
float test_union1(float S){

	std::set<int>test; 
    for (int i=1; i<N/2; i++) test.insert(i);

    std::set<int>test2; 
    for (int i=1; i<3*N/4+1; i++) test2.insert(i+N/4+1);

    std::chrono::high_resolution_clock::time_point td1;
    std::chrono::high_resolution_clock::time_point td2;

    std::cout<<"union11"<<std::endl;
	for(auto const& value: test)
    	std::cout<<value<<" ";
    std::cout<<std::endl;


    td1 = std::chrono::high_resolution_clock::now();

    	test.insert(test2.begin(),test2.end()) ;

	td2 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(td2 - td1);
    double tps_ecoule = time_span.count();  
    
    S += tps_ecoule;



	std::cout<<"union12"<<std::endl;
	for(auto const& value: test2)
    	std::cout<<value<<" ";
    std::cout<<std::endl;

	std::cout<<"union13"<<std::endl;
	for(auto const& value: test)
    	std::cout<<value<<" ";
    std::cout<<std::endl;

    return S;

}

// equivalent insert pour les sets
float test_union2(float S){

	std::set<int>test; 
    for (int i=1; i<N/2; i++) test.insert(i);

    std::set<int>test2; 
    for (int i=1; i<3*N/4+1; i++) test2.insert(i+N/4+1);

    std::chrono::high_resolution_clock::time_point td1;
    std::chrono::high_resolution_clock::time_point td2;

    std::cout<<"union21"<<std::endl;
	for(auto const& value: test)
    	std::cout<<value<<" ";
    std::cout<<std::endl;

    std::set<int>test_union;

    td1 = std::chrono::high_resolution_clock::now();

    	set_union(test.begin(),test.end(),test2.begin(),test2.end(),
    		std::inserter(test_union,test_union.begin())) ;

	td2 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(td2 - td1);
    double tps_ecoule = time_span.count();  
    
    S += tps_ecoule;



	std::cout<<"union22"<<std::endl;
	for(auto const& value: test2)
    	std::cout<<value<<" ";
    std::cout<<std::endl;

	std::cout<<"union23"<<std::endl;
	for(auto const& value: test_union)
    	std::cout<<value<<" ";
    std::cout<<std::endl;

    return S;

}

// equivalent insert pour les sets
float test_intersect(float S){

	std::set<int>test; 
    for (int i=1; i<N/2; i++) test.insert(i);

    std::set<int>test2; 
    for (int i=1; i<3*N/4+1; i++) test2.insert(i+N/4+1);

    std::chrono::high_resolution_clock::time_point td1;
    std::chrono::high_resolution_clock::time_point td2;

    std::cout<<"inter1"<<std::endl;
	for(auto const& value: test)
    	std::cout<<value<<" ";
    std::cout<<std::endl;

    std::set<int>test_inter;


    td1 = std::chrono::high_resolution_clock::now();

    	set_intersection(test.begin(),test.end(),test2.begin(),test2.end(),
                  std::inserter(test_inter,test_inter.begin()));

	td2 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(td2 - td1);
    double tps_ecoule = time_span.count();  
    
    S += tps_ecoule;



	std::cout<<"inter1"<<std::endl;
	for(auto const& value: test2)
    	std::cout<<value<<" ";
    std::cout<<std::endl;

	std::cout<<"inter2"<<std::endl;
	for(auto const& value: test_inter)
    	std::cout<<value<<" ";
    std::cout<<std::endl;

    return S;

}
