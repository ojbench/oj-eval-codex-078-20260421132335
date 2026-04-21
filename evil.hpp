// evil.hpp - Implementation of Evil class per problem statement
#ifndef EVIL_HPP
#define EVIL_HPP

#include <iostream>
using namespace std;

class Evil{
private:
    int st, ed, val;
    int *data;

public:
    // Default constructor
    Evil() : st(0), ed(0), val(0) {
        // When st = ed = 0, we still allocate one element representing day 0
        data = new int[1];
        data[0] = 0;
    }

    // Parameterized constructor
    Evil(int _st, int _ed, int _val) : st(_st), ed(_ed), val(_val) {
        int n = (_ed - _st + 1);
        if (n <= 0) {
            // Handle invalid ranges by treating as single element
            st = _st;
            ed = _st;
            n = 1;
        }
        data = new int[n];
        for (int i = 0; i < n; ++i) data[i] = 0;
    }

    // Copy constructor
    Evil(const Evil &other) : st(other.st), ed(other.ed), val(other.val) {
        int n = ed - st + 1;
        if (n <= 0) n = 1;
        data = new int[n];
        for (int i = 0; i < n; ++i) data[i] = other.data[i];
    }

    // Subscript operator overload (both lvalue and rvalue access)
    int &operator[](int i) {
        if (st <= i && i <= ed) {
            return data[i - st];
        }
        // If out of range, return st day's energy
        return data[0];
    }

    const int &operator[](int i) const {
        if (st <= i && i <= ed) {
            return data[i - st];
        }
        return data[0];
    }

    // Assignment operator overload
    Evil &operator=(const Evil &other) {
        if (this == &other) return *this;
        // Reallocate if size differs
        int n_other = other.ed - other.st + 1;
        if (n_other <= 0) n_other = 1;

        int n_this = ed - st + 1;
        if (n_this <= 0) n_this = 1;

        if (n_this != n_other) {
            delete [] data;
            data = new int[n_other];
        }

        st = other.st;
        ed = other.ed;
        val = other.val;
        for (int i = 0; i < n_other; ++i) data[i] = other.data[i];
        return *this;
    }

    // Prefix ++
    Evil &operator++() {
        ++val;
        return *this;
    }

    // Postfix ++
    Evil operator++(int) {
        Evil tmp(*this);
        ++val;
        return tmp;
    }

    // Output operator overload
    friend ostream &operator<<(ostream &os, const Evil &e) {
        os << e.val << " ";
        int n = e.ed - e.st + 1;
        if (n <= 0) n = 1;
        for (int i = 0; i < n; ++i) {
            os << e.data[i] << " ";
        }
        os << '\n';
        return os;
    }

    // Destructor
    ~Evil() {
        delete [] data;
        data = nullptr;
    }

    void Print(){
        cout << val << " ";
        for(int i = 0;i < ed-st+1;++i)
            cout << data[i] <<" ";
        cout << endl;
    }
};

#endif // EVIL_HPP

