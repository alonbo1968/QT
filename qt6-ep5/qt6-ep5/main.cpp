#include <iostream>
#include <stdlib.h>
#include <time.h>

//using namespace std;

int main()
{
    int rand_val;
    //Show Max Random value setting
    std::cout << "Max. Random value RAND_MAX = "  << RAND_MAX <<std::endl;

    //Initialize the Random Seed
    std::srand(time(nullptr));

    //Generate 3 random numbers between 1 to 10
    rand_val = std::rand() % 10;
    std::cout << "Random value = " << rand_val << std::endl;
    rand_val = std::rand() % 10;
    std::cout << "Random value = " << rand_val << std::endl;
    rand_val = std::rand() % 10;
    std::cout << "Random value = " << rand_val << std::endl;
    return 0;
}
