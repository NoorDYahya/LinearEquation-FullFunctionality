#include <iostream>

class Variable {

private:
    double val;
    char* name;
    void sort(Variable& v);

public:
    Variable(Variable& x);
    Variable();
    Variable(double v);
    Variable(double v, char* namee);
    ~Variable();
    Variable& operator+(Variable const& a);
    Variable& operator-(Variable const& a);
    Variable& operator*(Variable const& a);
    Variable& operator*(double a);
    Variable& operator += (const Variable& a);
    Variable& operator -= (const Variable& a);
    Variable& operator *= (const Variable& a);
    Variable& operator *= (double a);
    bool operator==(const Variable& a);
    Variable& operator=(const Variable& a);
    Variable& operator() ( char** var, double *d);

    friend std::ostream& operator<< (std::ostream& os, const Variable& ob);
    char* get_namee();
    double get_v();
    void set_namee(char* x);
    void set_v(double v);




};