// add your code

#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>

#include "reservoir.h"
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
    return 0;
}

double get_min_east(){
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    std::string date;
    std::string eastSt;
    std::string eastEl;
    std::string westSt;
    std::string westEl;
    float min = 0;
    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) { 
        fin.ignore(INT_MAX, '\n'); 
        if(min==0){
            try{
                min = stof(eastSt);
            }
            catch(...){
                continue;
            }
        }
        if(min > stof(eastSt)){
            min = stof(eastSt);
        }
    }
    return min;
}
double get_max_east(){
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    std::string date;
    std::string eastSt;
    std::string eastEl;
    std::string westSt;
    std::string westEl;
    float max = 0;
    float min = 0;
    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) { 
        fin.ignore(INT_MAX, '\n'); 
        if(min==0){
            try{
                min = stof(eastSt);
                max = stof(eastSt);
            }
            catch(...){
                continue;
            }
        }
        if(min > stof(eastSt)){
            min = stof(eastSt);
        }else if(max < stof(eastSt)){
            max = stof(eastSt);
        }
    }   
    fin.close();
    return max;
}
