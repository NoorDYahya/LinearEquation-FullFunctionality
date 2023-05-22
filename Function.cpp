#include "Function.h"

Function::Function()
{
    len = 0;
    arr = NULL;
}

Function::Function(Function &a)
{
    len = a.len;

    arr = new Variable[len];
    for (int i = 0; i < len; i++)
    {
        arr[i] = a.arr[i];
    }
}


Function::~Function()
{
    delete[]arr;
}

Function &Function::operator+=(Variable &x)
{

    if (this->arr == NULL)
    {
        this->arr = new Variable[1];
        this->arr[len] = x;
        this->set_len(1);
        return *this;
    }
    if(x.get_namee() == NULL){
        for (int i = 0; i < this->len; i++)
        {
            if(this->arr[i].get_namee() == NULL ){
                this->arr[i]+=x;
                return *this;
            }
        }
        Variable* tmp = new Variable[len];
        for (int i = 0; i < this->len; i++)
        {
            tmp[i] = this->arr[i];
        }
        delete []arr;
        arr = new Variable[len+1];
        for (int i = 0; i < this->len; i++)
        {
            arr[i] = tmp[i];
        }
        arr[len] = x;
        len++;
        return *this;
    }
    else
    {

        int flag = 0;
        for (int i = 0; i < this->len; i++)
        {
            if (strcmp(this->arr[i].get_namee(), x.get_namee()) == 0)
            {
                this->arr[i] += x;
//                this->len++;
                flag = 1;

            }
        }
        if (flag == 0)
        {
        Variable* tmp = new Variable[len];
            for (int i = 0; i < this->len; i++)
            {
                tmp[i] = this->arr[i];
            }
            delete []arr;
            arr = new Variable[len+1];
            for (int i = 0; i < this->len; i++)
            {
                arr[i] = tmp[i];
            }
            arr[len] = x;
            this->set_len(len + 1);
        }
    }


    return *this;
}

Function &Function::operator-=(int i)
{
    if (i < 0 || i >= len)
    {

        std::cout << "index out of range" << std::endl;
        return *this;
    }
    Variable *m = new Variable[len - 1];
    for (int j = 0; j < i; j++)
    {
        m[j] = arr[j];
    }
    for (int j = i + 1; j < len - 1; j++)
    {
        m[j] = arr[j];
    }
    delete[]arr;
    arr = new Variable[len - 1];
    for (int j = 0; j < len - 1; j++)
    {
        arr[j] = m[j];
    }
    len -= 1;
    return *this;
}

void Function::set_len(int len1)
{
    this->len = len1;
}

Function &Function::operator+(const Function &x)
{
    int size = 0;
    Function *fun = new Function();

    fun->arr = new Variable[len+x.len];
    fun->len = len;
    if (this->arr == NULL)
    {
        for (int i = 0; i < x.len; i++)
        {
            fun->arr[i] = x.arr[i];

        }
        fun->len = x.len;
        return *fun;
    }
    for(int i = 0 ; i < len ; i++){
        fun->arr[i] = this->arr[i];
    }
    for(int i = 0 ; i < x.len ; i++){
        int flag = 0;
        for(int j = 0 ; j < len ; j++){
            if(fun->arr[j].get_namee() == NULL &&x.arr[i].get_namee() ==
            NULL ){
                fun->arr[j]+=x.arr[i];
                flag = 1;
            }
            else
            {
                if(fun->arr[j].get_namee() != NULL && x.arr[i].get_namee()
                != NULL)
                {
                    if (strcmp(fun->arr[j].get_namee(),
                               x.arr[i].get_namee()) ==0
                            )
                    {
                        fun->arr[j] += x.arr[i];
                        flag = 1;
                    }
                }

            }
        }
        if(flag == 0){
            Variable* tmp = new Variable[len];
            for (int j = 0; j < this->len; j++)
            {
                tmp[j] = fun->arr[j];
            }
            delete []fun->arr;
            fun->arr = new Variable[len+1];
            for (int j = 0; j < this->len; j++)
            {
                fun->arr[j] = tmp[j];
            }
            fun->arr[len] = x.arr[i];
            fun->len++;
        }
    }
    return *fun;
//    sort()

}

Function &Function::operator-(const Function &x)
{
    Function *fun = new Function();

    fun->arr = new Variable[len+x.len];
    fun->len = len;
    if (this->arr == NULL)
    {
        for (int i = 0; i < x.len; i++)
        {
            Variable a(0,x.arr[i].get_namee());
            fun->arr[i] =a;

            fun->arr[i] -= x.arr[i];

        }
        fun->len = x.len;
        return *fun;
    }
    for(int i = 0 ; i < len ; i++){
        fun->arr[i] = this->arr[i];
    }
    for(int i = 0 ; i < x.len ; i++){
        int flag = 0;
        for(int j = 0 ; j < len ; j++){
            if(fun->arr[j].get_namee() == NULL && x.arr[i].get_namee() ==
                                                 NULL ){
                fun->arr[j]-=x.arr[i];
                flag = 1;
            }
            else
            {
                if(fun->arr[j].get_namee() != NULL && x.arr[i].get_namee()
                                                      != NULL)
                {
                    if (strcmp(fun->arr[j].get_namee(),
                               x.arr[i].get_namee()) ==0
                            )
                    {
                        fun->arr[j] -= x.arr[i];
                        flag = 1;
                    }
                }

            }
        }
        if(flag == 0){
            Variable* tmp = new Variable[len];
            for (int j = 0; j < this->len; j++)
            {
                tmp[j] = fun->arr[j];
            }
            delete []fun->arr;
            fun->arr = new Variable[len+1];
            for (int j = 0; j < this->len; j++)
            {
                fun->arr[j] = tmp[j];
            }
            if(x.arr[i].get_namee() == NULL){
                Variable a(-1*x.arr[i].get_v());
                fun->arr[len] = a;
            }
            else
            {
                Variable a(-1 * x.arr[i].get_v(), x.arr[i].get_namee());
                fun->arr[len] = a;
            }
            fun->len++;
        }
    }
    for( int i = 0 ; i< fun->len ; i++){
        if(fun->arr[i].get_v() == 0){
            fun->operator-=(i);
        }
    }
    return *fun;
}

Function &Function::operator*(double x)
{
    Function *fun = new Function();
    fun->len = len;
    for (int i = 0; i < len; i++)
    {
        fun->arr[i] = this->arr[i] * x;
    }
    return *fun;
}

Function &Function::operator*(const Function &x)
{
    Function *fun = new Function();

    fun->arr = new Variable[len+x.len];
    for(int i = 0 ; i < len ; i++){
        fun->arr[i] = this->arr[i];
    }
    int size = 0 ;
    for(int i = 0 ; i < x.len ; i++){
        for(int j = 0 ; j < len ; j++){
            fun->arr[size] = arr[j] * x.arr[i];
            size++;
        }

    }
    fun->len = size;
//    sort(*fun);
    return *fun;
}

Function &Function::operator=(const Function &x)
{
    if (*this == x)
    {
        return *this;
    }
    this->len = x.len;
    delete []arr;

    arr = new Variable[len];
    for (int i = 0; i < len; i++)
    {
        arr[i] = x.arr[i];
    }
    return *this;
}

bool Function::operator==(const Function &x)
{
    if (x.len != len)
    {
        return false;
    }
    int j = 0;
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == x.arr[i])
        {
            j++;
        }

    }
    if(j == x.len){return true;}
    return false;
}
Variable& Function::operator[](int i){
    if (i < 0 || i >= len)
    {

        std::cout << "index out of range" << std::endl;
        exit(1);
    }else{
        return arr[i];
    }

}
std::ostream &operator<<(std::ostream &os, const Function &ob)
{
    for (int i = 0; i < ob.len - 1; i++)
    {
        if(ob.arr[i].get_namee() == NULL){
            os << ob.arr[i];
        }
        if(ob.arr[i+1].get_namee() != NULL && ob.arr[i].get_namee() != NULL){
            os << ob.arr[i] << "+";
        }
        else{
            os << ob.arr[i];
        }



    }
    os << ob.arr[ob.len - 1];
    return os;
}
bool compareString( Variable& a,  Variable& b) {
    return strcmp(a.get_namee() , b.get_namee()) < 0;
}
//void Function::sort(Function& f)
//{
//    std::sort(f.arr, f.arr + len, compareString);
//
//}
Variable* Function:: get_arr(){
    return arr;
}
int Function::get_len(){
    return len;
}