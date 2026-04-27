#ifndef IPERSONAJE_H
#define IPERSONAJE_H

class IPersonaje {
public:
    virtual void curarValor(int pocion) = 0;
    virtual void curarRef(int& pocion) = 0;
    virtual void curarPtr(int* pocion) = 0;
    virtual ~IPersonaje() = default;
};

#endif