#include <iostream>

template <typename T>
class Collection{
public:
    virtual bool add(T*,int) = 0;
    virtual int get(std::string) = 0;
    virtual void clear() = 0;
    virtual bool isEmpty() = 0;
    virtual int size() = 0;
};

class Key{
public:
    Key(const std::string& key);
    int hashCode();
    bool equals(const Key&) const;
    std::string getKey() const;
    void setKey(std::string);
private:
    std::string key;
};

Key::Key(const std::string& key){
    this->key = key;
}

int Key::hashCode() {return (int)key[0];}

bool Key::equals(const Key& Key) const { return (key == Key.getKey());}

std::string Key::getKey() const { return key;}

void Key::setKey(std::string key) {this->key = key;}

struct Node{
    int hash;
    Key *key;
    int value;
    Node* next;
};

class HashMap: public Collection<Key>{
public:
    explicit HashMap(int a);
    ~HashMap();
    bool add(Key*,int) override;
    int get(std::string) override;
    void clear() override;
    void deletePath(Node*);
    bool isEmpty() override;
    int size() override;
    void print();
private:
    int length;
    Node** array;
};

HashMap::HashMap(int a) {
    length = a;
    array = new Node*[a];
    for (int i=0;i<a;i++)
        array[i] = nullptr;
}

HashMap::~HashMap() {
    clear();
    delete array;
}

bool HashMap::add(Key* key,int value) {
    int index = key->hashCode() & (length-1);
    if (array[index] == nullptr) {
        array[index] = new Node{key->hashCode(), key, value, nullptr};
        return true;
    }else {
        Node *p = array[index];
        if (p->key->equals(key->getKey())){
            p->value = value;
            return true;
        }
        else {
            while (p->next != nullptr) {
                if (p->key->equals(key->getKey())){
                    p->value = value;
                    return true;
                }else
                    p = p->next;
            }
            p->next = new Node{key->hashCode(), key, value, nullptr};
        }
        return true;
    }
    return false;
}

int HashMap::get(std::string key){
    int index = (int)key[0] & (length-1);
    Node *p = array[index];
    while (p!= nullptr) {
        if (p->key->equals(key))
            return p->value;
        p = p->next;
    }
    return 0;
}

void HashMap::clear() {
    for (int i=0;i<length;i++) {
        deletePath(array[i]);
        array[i] = nullptr;
        delete array[i];
    }
}

void HashMap::deletePath(Node* node) {
    if (node == nullptr) return;
    deletePath(node->next);
    if (node != nullptr)
        delete node;
}

bool HashMap::isEmpty() {
    for (int i=0;i<length;i++)
        if (array[i] != nullptr)
            return false;
    return true;
}

int HashMap::size() { return length;}

void HashMap::print() {
    for (int i=0;i<length;i++){
        Node *p = array[i];
        while (p != nullptr) {
            std::cout<<p->key->getKey() << "-" << p->value << "; ";
            p = p->next;
        }
        std::cout<<p<<std::endl;
    }
}
