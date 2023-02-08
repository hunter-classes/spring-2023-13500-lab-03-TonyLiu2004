#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <vector>
void reverse_oreder(std::string date1, std::string date2){
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    std::string date;
    std::string eastSt;
    std::string eastEl;
    std::string westSt;
    std::string westEl;
    std::vector<std::string> dates;
    std::vector<std::string> elevation;
    bool rec = false;
    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) { 
        fin.ignore(INT_MAX, '\n'); 
        if(date == date1){
            dates.push_back(date);
            elevation.push_back(westEl);
            rec = true;
        }
        if(rec){
            dates.push_back(date);
            elevation.push_back(westEl);
        }
        if(date == date2){
            rec = false;
        }
    }
    fin.close();
    for(int i = dates.size()-1; i >0; i--){
        std::cout << dates[i] << " " << elevation[i] << " ft" << std::endl;
    }
}