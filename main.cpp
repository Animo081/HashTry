#include <iostream>
#include "Sort.h"
#include "Collection.h"

int main() {
    HashMap *hashMap = new HashMap(10);
    hashMap->add(new Key("krot"),10);
    hashMap->add(new Key("krot"),20);
    hashMap->add(new Key("kroti"),30);
    hashMap->add(new Key("kro"),40);
    hashMap->print();
    std::cout<<"\n\n\n";
    std::cout<<hashMap->get("krot");
    hashMap->clear();
    std::cout<<"\n\n\n";
    hashMap->print();
    delete hashMap;
    return 0;
}