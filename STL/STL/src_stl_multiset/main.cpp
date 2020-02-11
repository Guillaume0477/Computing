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
const int N = 100000;

float test_ajout(int n, float S);
float test_lecture(int n, float S);
float test_erase(int n, float S);
float test_clean(float S);

float test_copie1(float S);
float test_copie2(float S);


float test_union1(float S);

float test_ajout(int n, float S);
float test_lecture(int n, float S);
float test_erase(int n, float S);
float test_clean(float S);
float test_size(float S);
float test_find(int n, float S);
float test_copie1(float S);
float test_copie2(float S);
float test_copie3(float S);
float test_count(int n, float S);
float test_union1(float S);
float test_union2(float S);
float test_intersect(float S);


int main ()
{
    int n = 50;
    double S = 0.0f;
    //write a file storing all the sampled points
    std::ofstream ofs;
    //TODO Changer le nom du conteneur
    std::string conteneur = "multiset";
    std::string filename = "data"+conteneur+".m";
    ofs.open(filename,std::fstream::app);

    if(ofs.good()==false)
        throw std::exception();

    //Initialisation des données dans le fichier matlab
    if (N == 10){
        ofs << "x" << N << "= [" << N << ",";
    } else {
        ofs << N << ",";
    }
//    /***************************
//     * Ajout dans le conteneur *
//     * ************************/
//    //Calcul du temps d'ajout au début
//    for (int k = 0; k < n ; k++){
//        S = test_ajout(1,S);
//    }
//    ofs << S/n << ",";
//    S = 0.0f;
//    //Calcul du temps d'ajout à la fin
//    for (int k = 0; k < n ; k++){
//        S = test_ajout(N,S);
//    }
//    ofs << S/n << ",";
//    S = 0.0f;

//    //Calcul du temps d'ajout aléatoire
//    for (int k = 0; k < n ; k++){
//        S = test_ajout(N/2,S);
//    }
//    ofs << S/n << ",";
//    S = 0.0f;

//    /***************************
//     * Lecture dans le conteneur *
//     * ************************/
//    //Calcul du temps d'ajout au début
//    for (int k = 0; k < n ; k++){
//        S = test_lecture(1,S);
//    }
//    ofs << S/n << ",";
//    S = 0.0f;

//    //Calcul du temps d'ajout à la fin
//    for (int k = 0; k < n ; k++){
//        S = test_lecture(N,S);
//    }
//    ofs << S/n << ",";
//    S = 0.0f;

//    //Calcul du temps d'ajout aléatoire
//    for (int k = 0; k < n ; k++){
//        S = test_lecture(N/2,S);
//    }
//    ofs << S/n;
//    S = 0.0f;
    
//    if (N >= 1000000){
//        ofs << "];";
//    } else {
//        ofs << ";\n";
//    }

    // ////////////////////
    
    //Calcul du temps d'un erase
    for (int k = 0; k < n ; k++){
        S = test_erase(N/2, S);
    }
    ofs <<S/n<<std::endl;
    S = 0.0f;

    for (int k = 0; k < n ; k++){
        S = test_clean(S);
    }
    ofs <<S/n<<std::endl;
    S = 0.0f;

    for (int k = 0; k < n ; k++){
        S = test_copie1(S);
    }
    ofs <<S/n<<std::endl;
    S = 0.0f;

    for (int k = 0; k < n ; k++){
        S = test_copie2(S);
    }
    ofs <<S/n<<std::endl;
    S = 0.0f;

    for (int k = 0; k < n ; k++){
        S = test_size(S);
    }
    ofs <<S/n<<std::endl;
    S = 0.0f;




    // ///////////
//        //Calcul du temps d'un erase
//    for (int k = 0; k < n ; k++){
//        S = test_erase(N/2, S);
//    }
//    std::cout<<S/n<<std::endl;
//    S = 0.0f;

//    //Calcul du temps d'un clean
//    for (int k = 0; k < n ; k++){
//        S = test_clean(S);
//    }
//    std::cout<<S/n<<std::endl;
//    S = 0.0f;

//    //Calcul du temps de recherche d'un element
//    for (int k = 0; k < n ; k++){
//        S = test_find(N/2,S);
//    }
//    std::cout<<S/n<<std::endl;
//    S = 0.0f;

//    //Calcul du temps de copie1
//    for (int k = 0; k < n ; k++){
//        S = test_copie1(S);
//    }
//    std::cout<<S/n<<std::endl;
//    S = 0.0f;

//    //Calcul du temps de copie2
//    for (int k = 0; k < n ; k++){
//        S = test_copie2(S);
//    }
//    std::cout<<S/n<<std::endl;
//    S = 0.0f;

//    //Calcul du temps de copie3
//    for (int k = 0; k < n ; k++){
//        S = test_copie3(S);}

//    std::cout<<S/n<<std::endl;
//    S = 0.0f;

//    //Calcul du temps de count d'un element
//    for (int k = 0; k < n ; k++){
//        S = test_count(N/2,S);
//    }
//    std::cout<<S/n<<std::endl;
//    S = 0.0f;

//    //Calcul du temps d'union1
//    for (int k = 0; k < n ; k++){
//        S = test_union1(S);
//    }
//    std::cout<<S/n<<std::endl;
//    S = 0.0f;

//    //Calcul du temps d'union2
//    for (int k = 0; k < n ; k++){
//        S = test_union2(S);
//    }
//    std::cout<<S/n<<std::endl;
//    S = 0.0f;

//    //Calcul du temps d'inserction'
//    for (int k = 0; k < n ; k++){
//        S = test_intersect(S);
//    }
//    std::cout<<S/n<<std::endl;
//    S = 0.0f;
    ofs.close();
    return 0;
}

float test_ajout(int n, float S){
    //TODO Ajouter ici la création du conteneur
    std::multiset<int>test; 
    for (int i=1; i<=N; i++) test.insert(i);
    
    //TODO bien spécifier le type et la valeur à ajouter

    std::chrono::high_resolution_clock::time_point td1;
    std::chrono::high_resolution_clock::time_point td2;
    //TODO A DECOMMENTER SI IL EXISTE UNE FONCTION PUSH_BACK
    
    if (n == N) {
        //int max_tab = max(init_tab)
        td1 = std::chrono::high_resolution_clock::now();
        test.insert(n);
        td2 = std::chrono::high_resolution_clock::now();
        //Calcul du temps ecoule
        std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(td2 - td1);
        double tps_ecoule = time_span.count();    
    
        S += tps_ecoule;

//        std::cout<<"1"<<std::endl;
//        for(auto const& value: test)
//            std::cout<<value<<" ";
//        std::cout<<std::endl;

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

//        std::cout<<"2"<<std::endl;
//        for(auto const& value: test)
//            std::cout<<value<<" ";
//        std::cout<<std::endl;

        return S;
    }
    

    if (n == N/2) {
        //int moy_tab = max(init_tab)-min(init_tab)
        td1 = std::chrono::high_resolution_clock::now();
        test.insert(n);
        td2 = std::chrono::high_resolution_clock::now();
        //Calcul du temps ecoule
        std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(td2 - td1);
        double tps_ecoule = time_span.count();    
    
        S += tps_ecoule;

//        std::cout<<"3"<<std::endl;
//        for(auto const& value: test)
//            std::cout<<value<<" ";
//        std::cout<<std::endl;
    

        return S;
    }
    

    return S;
}

float test_lecture(int n, float S){
    //TODO Ajouter ici la création du conteneur
    std::multiset<int>test; 
    for (int i=1; i<=N; i++) test.insert(i);

//    std::cout<<""<<std::endl;
//    for(auto const& value: test)
//        std::cout<<value<<" ";
//    std::cout<<std::endl;
    
//    TODO Bien spécifier le type de la variable présente dans votre conteneur
    int a;
    std::chrono::high_resolution_clock::time_point td1;
    std::chrono::high_resolution_clock::time_point td2;


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
//            a = *it1;
            td2 = std::chrono::high_resolution_clock::now();
//            std::cout<<a<<std::endl;
    }     
    
    

    //ligne pour eviter une erreur de variable unused
    a+=1;
    
    //Calcul du temps ecoule
    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(td2 - td1);
    double tps_ecoule = time_span.count();  
    
    S += tps_ecoule;
    return S;
}

// peut supprimer plusieurs clé
float test_erase(int n, float S){

    std::multiset<int>test; 
    for (int i=1; i<=N; i++) test.insert(i);
    test.insert(n);

//    std::cout<<"av_erase"<<std::endl;
//    for(auto const& value: test)
//        std::cout<<value<<" ";
//    std::cout<<std::endl;


    std::chrono::high_resolution_clock::time_point td1;
    std::chrono::high_resolution_clock::time_point td2;

    td1 = std::chrono::high_resolution_clock::now();

        test.erase(n);

    td2 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(td2 - td1);
    double tps_ecoule = time_span.count();  
    
    S += tps_ecoule;

//    std::cout<<"erase"<<std::endl;
//    for(auto const& value: test)
//        std::cout<<value<<" ";
//    std::cout<<std::endl;

    return S;

}

float test_size(float S){

    std::multiset<int>test;
    for (int i=1; i<=N; i++) test.insert(i);


    std::chrono::high_resolution_clock::time_point td1;
    std::chrono::high_resolution_clock::time_point td2;

    td1 = std::chrono::high_resolution_clock::now();

        test.size();

    td2 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(td2 - td1);
    double tps_ecoule = time_span.count();

    S += tps_ecoule;


    return S;

}



float test_clean(float S){

    std::multiset<int>test; 
    for (int i=1; i<=N; i++) test.insert(i);

    std::chrono::high_resolution_clock::time_point td1;
    std::chrono::high_resolution_clock::time_point td2;

    td1 = std::chrono::high_resolution_clock::now();

        test.clear();

    td2 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(td2 - td1);
    double tps_ecoule = time_span.count();  
    
    S += tps_ecoule;

//    std::cout<<"clean"<<std::endl;
//    for(auto const& value: test)
//        std::cout<<value<<" ";
//    std::cout<<std::endl;

    return S;

}



float test_find(int n, float S){

    std::multiset<int>test; 
    for (int i=1; i<=N; i++) test.insert(i);

    std::chrono::high_resolution_clock::time_point td1;
    std::chrono::high_resolution_clock::time_point td2;

    std::cout<<"find"<<std::endl;

    td1 = std::chrono::high_resolution_clock::now();

        std::multiset<int>::iterator it = test.find(n);
        std::cout<<*it<<std::endl;
        //*it=n+1


    td2 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(td2 - td1);
    double tps_ecoule = time_span.count();  
    
    S += tps_ecoule;
    return S;

}


float test_copie1(float S){


    std::chrono::high_resolution_clock::time_point td1;
    std::chrono::high_resolution_clock::time_point td2;

    td1 = std::chrono::high_resolution_clock::now();

        std::multiset<int>test;
        for (int i=1; i<=N; i++) test.insert(i);

    td2 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(td2 - td1);
    double tps_ecoule = time_span.count();  
    
    S += tps_ecoule;

//    std::cout<<"copie1"<<std::endl;
//    for(auto const& value: test)
//        std::cout<<value<<" ";
//    std::cout<<std::endl;

    return S;

}




float test_copie2(float S){

    std::multiset<int>test; 
    for (int i=1; i<=N; i++) test.insert(i);

    std::chrono::high_resolution_clock::time_point td1;
    std::chrono::high_resolution_clock::time_point td2;

    td1 = std::chrono::high_resolution_clock::now();

        std::multiset<int> test2 (test.begin(),test.end());

    td2 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(td2 - td1);
    double tps_ecoule = time_span.count();  
    
    S += tps_ecoule;

//    std::cout<<"copie2"<<std::endl;
//    for(auto const& value: test2)
//        std::cout<<value<<" ";
//    std::cout<<std::endl;

    return S;

}

float test_copie3(float S){

    std::multiset<int> test; 
    for (int i=1; i<=N; i++) test.insert(i);

    std::chrono::high_resolution_clock::time_point td1;
    std::chrono::high_resolution_clock::time_point td2;

    std::multiset<int> test_copie; 

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

    std::multiset<int>test; 
    for (int i=1; i<=N; i++) test.insert(i);
    test.insert(n);
    test.insert(n);

    std::chrono::high_resolution_clock::time_point td1;
    std::chrono::high_resolution_clock::time_point td2;


    std::cout << n;
    td1 = std::chrono::high_resolution_clock::now();

        if (test.count(n)!=0)
            std::cout << " is an element of myset " << test.count(n) <<"fois\n";
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

    std::multiset<int>test; 
    for (int i=1; i<N/2; i++) test.insert(i);

    std::multiset<int>test2; 
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
// enleve les doublons
float test_union2(float S){

    std::multiset<int>test; 
    for (int i=1; i<N/2; i++) test.insert(i);

    std::multiset<int>test2; 
    for (int i=1; i<3*N/4+1; i++) test2.insert(i+N/4+1);

    std::chrono::high_resolution_clock::time_point td1;
    std::chrono::high_resolution_clock::time_point td2;

    std::cout<<"union21"<<std::endl;
    for(auto const& value: test)
        std::cout<<value<<" ";
    std::cout<<std::endl;

    std::multiset<int>test_union;

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

    std::multiset<int>test; 
    for (int i=1; i<N/2; i++) test.insert(i);

    std::multiset<int>test2; 
    for (int i=1; i<3*N/4+1; i++) test2.insert(i+N/4+1);

    std::chrono::high_resolution_clock::time_point td1;
    std::chrono::high_resolution_clock::time_point td2;

    std::cout<<"inter1"<<std::endl;
    for(auto const& value: test)
        std::cout<<value<<" ";
    std::cout<<std::endl;

    std::multiset<int>test_inter;


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


