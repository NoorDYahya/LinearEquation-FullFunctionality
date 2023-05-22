#include <iostream>
#include "Variable.h"
class Function {

private:

    Variable* arr;

    int len;
    void sort(Function& f);
public:
    Function();
    Function(Function& x);
    ~Function();
    Function& operator += ( Variable&  x);
    Function& operator -= (int i);
    Function& operator + (Function const& x);
    Function& operator - (Function const& x);
    Function& operator * (Function const& x);
    Function& operator * (double x);
    Function& operator = (const Function& x);
    bool operator == (const Function& x);
    Variable& operator[](int i);
    friend std::ostream& operator<< (std::ostream& os, const Function& ob);
    void set_len(int len );
    Variable* get_arr();
    int get_len();











};