#include <QCoreApplication>
#include <iostream>

#define ARRAY_SIZE  10


void detect_repeated_element(int arr[], int size) {
    int work_array[ARRAY_SIZE] = {0};
    for(int i = 0; i < size; i++) {
        if(work_array[arr[i]] != 0) {
            //Repeating element detected
            std::cout << "Repeated element is " << arr[i] << std::endl;
            return;
        }
        work_array[arr[i]]++;
    }
    std::cout << "No repeated element found!!" << std::endl;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //You have an N elements array with elements value between
    // 0 to N-1.
    // Detect the first element that apears twice.
    //int len = ARRAY_SIZE;

    int array1[ARRAY_SIZE] = {1,0,2,3,4,7,5,6,4,8};
    detect_repeated_element(array1, ARRAY_SIZE);

    int array2[ARRAY_SIZE] = {0,2,2,4,7,5,6,4,8,8};
    detect_repeated_element(array2, ARRAY_SIZE);

    int array3[ARRAY_SIZE] = {0,1,2,3,4,5,6,7,8,9};
    detect_repeated_element(array3, ARRAY_SIZE);

    a.exit();
    //return a.exec();
}
