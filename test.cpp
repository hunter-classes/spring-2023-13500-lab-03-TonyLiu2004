#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>
#include <iostream>

double get_max_east();
int main(){
    std::cout << get_max_east();
    return 0;
}

double get_max_east(){
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1); // exit if failed to open the file
    }
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