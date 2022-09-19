#include <iostream>
using namespace std;
template<typename T>
class sharedPtr{

private:
    T* _ptr;
    int* _pcount;

public:
    sharedPtr(T* ptr = nullptr) : _ptr(ptr), _pcount(new int(1)){
        cout << "调用构造函数" << endl;
    }

    sharedPtr(const sharedPtr& s): _ptr(s._ptr), _pcount(s._pcount){
        cout << "调用拷贝构造函数" << endl;
        ++(*_pcount);
    }

    sharedPtr<T>& operator=(const sharedPtr& s){
        cout << "调用重载的赋值运算符" << endl;
        if(this != &s){
            if(--(*(this->_pcount)) == 0){
                delete this->_ptr;
                delete this->_pcount;
            }
            _ptr = s._ptr;
            _pcount = s._pcount;
            (*_pcount)++;
        }
        return *this;
    }

    T& operator*(){
        return *(this->_ptr);
    }

    T* operator->(){
        return this->_ptr;
    }

    int use_count(){
        return *(this->_pcount);
    }

    ~sharedPtr(){
        --*(this->_pcount);
        if(*(this->_pcount) == 0){
            delete this->_ptr;
            _ptr = nullptr;
            delete this->_pcount;
            _pcount = nullptr;
        }
        cout << "调用析构函数" << endl;
    }
};