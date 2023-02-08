// add your code as appropriate 
#include <iostream>
#include "reservoir.h"
#include "reverseorder.h"

int main()
{
  std::cout << "east storage: " << get_east_storage("05/10/2018") << std::endl;
  std::cout << "max: " << get_max_east() << std::endl; 
  std::cout << "min: " << get_min_east() << std::endl;
  std::cout << "compare: " << compare_basins("05/10/2018") << std::endl;
  return 0;
}
