#include "Function.h"
class LinearEquation{
private:
    Function fun;
    double right;
public:
     LinearEquation(Function& f);
    friend std::ostream& operator<< (std::ostream& os, const LinearEquation& ob);
    LinearEquation& operator+(LinearEquation& l);
    LinearEquation& operator-(LinearEquation& l);
    friend bool PossibleSingleSolution(LinearEquation* arr, int size);
};