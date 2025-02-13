#include <string>
#include <iostream>

class HasPtr 
{
public:
    friend void swap(HasPtr&, HasPtr&);
    friend bool operator<(const HasPtr &lhs, const HasPtr &rhs);

    HasPtr(const std::string &s = std::string()) 
        : ps(new std::string(s)), i(0) 
    { }

    HasPtr(const HasPtr &hp) 
        : ps(new std::string(*hp.ps)), i(hp.i) 
    { }

    ~HasPtr() 
    {
        delete ps;
    }

    HasPtr& operator=(HasPtr tmp) 
    {
        this->swap(tmp);
        return *this;
    }

    void swap(HasPtr& rhs) 
    {
        std::swap(ps, rhs.ps);
        std::swap(i, rhs.i);
        std::cout << "call swap(HasPtr &rhs)" << std::endl;
    }

    void show() const
    { 
        std::cout << *ps << std::endl; 
    }

private:
    std::string *ps;
    int i;
};

void swap(HasPtr& lhs, HasPtr& rhs)
{
    lhs.swap(rhs);
}

bool operator<(const HasPtr& lhs, const HasPtr& rhs)
{
    return *lhs.ps < *rhs.ps;
}

#include <vector>
#include <algorithm>

int main(void)
{
    HasPtr s{ "s" }, a{ "a" }, c{ "c" };
    std::vector<HasPtr> vec{ s, a, c };
    std::sort(vec.begin(), vec.end());

    for (auto const& elem : vec) elem.show();
    
    return 0;
}