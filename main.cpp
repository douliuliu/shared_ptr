#include <iostream>
#include "sharedPtr.h"


using namespace std;

int main(int argc, char** argv){
    sharedPtr<int> age(new int(24));
    cout << "age管理指针所指对象的数值是： " << *(age) << endl;
    cout << "引用对象数是： " << age.use_count() << endl;
    cout << "age管理指针的值是： " << age.operator->() << endl;
    /* sharedPtr<int> age2(age);
    cout << "引用对象数是： " << age.use_count() << endl;
    cout << "age管理指针的值是： " << age.operator->() << endl; */
    

    sharedPtr<int> age3(new int(25));
    cout << "age3管理指针所指对象的数值是： " << *(age3) << endl;
    cout << "引用对象数是： " << age3.use_count() << endl;
    cout << "age3管理指针的值是： " << age3.operator->() << endl;
    age = age3;
    cout << "age管理指针所指对象的数值是： " << *(age) << endl;
    cout << "引用对象数是： " << age.use_count() << endl;
    cout << "age管理指针的值是： " << age.operator->() << endl;
}