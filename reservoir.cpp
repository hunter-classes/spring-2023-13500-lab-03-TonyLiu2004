// add your code

#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>

#include <reservoir.h>
int test(){
    return 1;
}
double get_east_storage(std::string date){
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    std::string Idate;
    std::string eastSt;
    std::string eastEl;
    std::string westSt;
    std::string westEl;
    while(fin >> Idate >> eastSt >> eastEl >> westSt >> westEl) { 
        fin.ignore(INT_MAX, '\n'); 
        if(Idate == date){
            return stod(eastSt);
        }
    }
}