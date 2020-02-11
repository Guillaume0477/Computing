
#include "color.hpp"
#include "image.hpp"

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;




int main(int argc, char **argv) {

    if (argc<1){
        cerr<< "Error 1 : Running out of arguments" <<endl;
        return 0;
    }

    string filename = argv[1];
    cout <<filename <<endl;
    //from_ppm(filename);
    to_ppm(filename);


}


