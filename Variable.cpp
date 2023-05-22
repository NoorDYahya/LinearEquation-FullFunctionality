#include "Variable.h"

Variable::Variable() {

    name = NULL;
    val = 0;

}

Variable::Variable(double v) {

    val = v;
    name = NULL;
}

Variable::Variable(double v, char* namee) :Variable(v){
    name = new char[50];
    strcpy(name, namee);

}

Variable::~Variable() {

    delete name ;
}

Variable& Variable::operator+(const Variable &a)
{
    if(strcmp(a.name,this->name) != 0 ){
        std::cout << "wrong operand (x!=y)" << std::endl;
        return *this;
    }
    Variable* tmp = new Variable(this->val + a.val,this->name);

    return *tmp;


}

Variable& Variable::operator-(const Variable &a)
{
    if(strcmp(a.name,this->name) != 0 ){
        std::cout << "wrong operand (x!=y)" << std::endl;
        return *this;
    }
    Variable* tmp = new Variable(this->val - a.val,this->name);
//    tmp.val = this->val + a.val;
//    strcpy(tmp.name,this->name);
    return *tmp;
}

Variable& Variable::operator*(const Variable &a)
{

    Variable* tmp = new Variable(this->val * a.val,this->name);
    strcat(tmp->name ,a.name);
    sort(*tmp);
    return *tmp;
}

Variable& Variable::operator*(double a)
{
    Variable* tmp = new Variable(this->val * a,this->name);
    strcpy(tmp->name,this->name );
    sort(*tmp);
    return *tmp;
}
Variable& Variable::operator += (const Variable& a){
    if(a.name == NULL && this->name == NULL){
        this->val += a.val;
        return *this;
    }
    if(strcmp(a.name,this->name) != 0 ){
        std::cout << "wrong operand (x!=y)" << std::endl;
    }
    this->val += a.val;
    return *this;
}
Variable& Variable::operator -= (const Variable& a){
    if(strcmp(a.name,this->name) != 0 ){
        std::cout << "wrong operand (x!=y)" << std::endl;
    }

    this->val -= a.val;
    return *this;
}
Variable& Variable::operator*= (const Variable& a){

    this->val *= a.val;
    strcat(this->name ,a.name);
    sort(*this);
    return *this;


}
Variable& Variable::operator*= (double a){

    this->val *= a;
    return *this;


}
 bool Variable:: operator==(const Variable& a){
    if(this->name == NULL || a.name == NULL){ return false;}

    if(strcmp(a.name, this->name) == 0 && this->val == a.val){
        return true;
    }
    return false;

}
Variable& Variable:: operator=(const Variable& a){
    if(*this == a){
        return *this;
    }
    this->val = a.val;
    if(a.name == NULL){
        this->name = NULL;
        return *this;
    }
    if(this->name == NULL){
        this->name = new char[50];
    }
    strcpy(this->name, a.name);
    return *this;

}
//Variable& Variable:: operator() (char* var, double* d){
//
//}
void Variable::sort(Variable& v){
    int len = strlen(v.name);
//    std::string s = v.name;
//    std::sort(s.begin(),s.end());
   char temp;
    for (int i = 0; i < len; i++){

        for (int j = 0; j < len - 1; j++){
            if (v.name[j] > v.name[j + 1]){ //if j has larger ascii value than the
                // next,

                //swapping the prev and next characters

                temp = v.name[j];
                v.name[j] = v.name[j + 1];
                v.name[j + 1] = temp;
            }
        }
    }

}
char* Variable::get_namee(){
    return name;
}
double Variable::get_v(){
    return val;
}
void Variable::set_namee(char* x){
    strcpy(name,x);
}
void Variable::set_v(double v){
    this->val = v;
}

std::ostream &operator<<(std::ostream &os, const Variable &ob)
{

    if(ob.name != NULL)
    { os << ob.val << ob.name; }
    return os;
}
void removeCharFromString(char* str, char ch) {
    size_t pos = 0;
    size_t len = strlen(str);
    for (size_t i = 0; i < len; ++i) {
        if (str[i] == ch) {
            for (size_t j = i; j < len - 1; ++j) {
                str[j] = str[j + 1];
            }
            --i;
            --len;
        }
    }
    str[len] = '\0';
}
Variable &Variable::operator()( char  **var, double *d)
{
    Variable* v = new Variable(this->val,this->name);
    for(int i = 0 ; i <4; i++){
        for(int j = 0 ; j< strlen(name) ; j++)
        {
            char c = var[i][0];
            if (name[j]== c)
            {
                removeCharFromString(v->name, c);
                v->set_namee(v->name);
                v->set_v(v->val * d[i]);
            }
        }
    }
    return *v;


}

Variable::Variable(Variable &x)
{
    this->val = x.val;
    strcpy(this->name,x.name);
}
