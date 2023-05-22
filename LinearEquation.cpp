#include "LinearEquation.h"
LinearEquation::LinearEquation(Function &f)
{
     if(f.get_arr() == NULL){
         std::cout <<"cant convert to linear equation "<<std::endl;
     }
     fun = f;
     right = 0;
     for(int i = 0 ; i < f.get_len();i++){
         if(f[i].get_namee() == NULL){
             right+=f[i].get_v();
         }
     }
//     if(right != 0){
//         right*=-1;
//     }


}
std::ostream& operator<< (std::ostream& os, const LinearEquation& ob){
    int k = ob.right;
    if(ob.right != 0)
    { k *= -1; }
    os<<ob.fun << "=" << k;
    return os;
}
LinearEquation& LinearEquation:: operator+(LinearEquation& l){
    LinearEquation* k = new LinearEquation(this->fun);

    k->fun = k->fun+ l.fun;
    k->right = this->right+l.right;

    return *k;


}
LinearEquation& LinearEquation:: operator-(LinearEquation& l){
    LinearEquation* k = new LinearEquation(this->fun);

    k->fun = k->fun- l.fun;
    k->right = this->right-l.right;

    return *k;


}
bool isStringPresent( char** array, size_t size,  char* target) {
    if(array[0] == NULL){
        return false;
    }
    for (size_t i = 0; i < size; ++i) {
        if (std::strcmp(array[i], target) == 0) {
            return true;
        }
    }
    return false;
}
bool PossibleSingleSolution(LinearEquation* arr, int size){

    char** var = new char*[100];
    for(int i = 0 ; i < 100 ; i++){
        var[i] = new char[1];
    }
    int count = 0;
     for(int i = 0 ; i< size ; i++){
         for(int j = 0 ; j < arr[i].fun.get_len() ; j++){
             if(arr[i].fun.get_arr()[j].get_namee() != NULL)
             {
                 if (!isStringPresent(var, 100,
                                      arr[i].fun.get_arr()[j].get_namee
                                              ()) && arr[i].fun.get_arr()[j].get_namee() != NULL)
                 {

                     strcpy(var[count], arr[i].fun.get_arr()[j].get_namee());
                     count++;

                 }
             }
         }
     }

     return count <= size;
}