#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;

// Problme02 // 
int max(int a, int b){
    /*Compare max value*/
    if (a>b) return a; 
    else if (a<b) return b; 
    else return a; 
}

int price(int i, int rod_size){
    /*Get the price*/
    int price;
    if (i==1)  price=2;
    else if (i < rod_size)  price=floor(double(i)*2.5);
    else  price = double(i) * 2.5 - 1; 
    return price; 
}

int cut_rod_R(int rod_size){
    /*Recursive method of cutting rod function*/
    int result=0; 
    for (int i=0; i<rod_size; i++){
        /*Get better result between pristine price and update price*/
        result = max(result, price(i, rod_size) + cut_rod_R(rod_size-i-1)); 
    }
    return result; 
}

int cut_rod_D(int rod_size){
    /*Dynamic method of cutting rod function*/
    int results[rod_size + 1];
    results[0] = 0;
    for (int i=1; i<=rod_size; i++){
        int result = 0; 
        for (int j=0; j<i; j++){
            /*Update better result*/
            result = max(result, price(j, rod_size) + results[i-j-1]); 
            results[i] = result;
        }
    }
    return results[rod_size]; 
}

int main(){
    /*Explicit test samples in functions calculating time complexity*/
    int test_samples[] = {5,10,15,20,25,30,35,40,45,50};
    /*Set time complexity variables*/
    clock_t start, finish; 
    double duration;
    for (int i=0; i<10; i++){
        cout << "Size of test samples: " << test_samples[i] << endl;
        start = clock(); 
        cout << "Max Revenue: " << cut_rod_R(test_samples[i]) << endl;
        finish = clock(); 
        duration = (double)(finish - start) / CLOCKS_PER_SEC;
        printf("%fsec", duration);
        cout << endl;
    }

    for(int i=0; i<10;i++){
        cout << "Size of test samples: " << test_samples[i] << endl;
        start = clock(); 
        cout << "Max Revenue: " << cut_rod_D(test_samples[i]) << endl;
        finish = clock(); 
        duration = (double)(finish - start) / CLOCKS_PER_SEC;
        printf("%fsec", duration);
        cout << endl;
    }
}