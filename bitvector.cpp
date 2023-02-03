#include <iostream>

class bitVector {
public:
    bitVector(int);
    ~bitVector();

    void set(int);
    void reset(int);
    bool get_at(int position) const;
    int get_size() const;
    int get_arr_size() const;

private:
    int m_size;
    int m_arr_size;
    unsigned long int* m_buf;
};

void test(){
    bitVector b(100);
    std::cout << "size: " << b.get_size() << std::endl;
    std::cout << "arr_size: " << b.get_arr_size() << std::endl;
    std::cout << "value at 15th position before set: " << b.get_at(15) << std::endl; 
    b.set(15);
    std::cout << "value at 15th position after set: " << b.get_at(15) << std::endl; 
    b.reset(15);
    std::cout << "value at 15th position after reset: " << b.get_at(15) << std::endl;
}


int main(){
    test();
    return 0;
}

bitVector::bitVector(int size)
    :m_size(size)
    ,m_arr_size(size / (8 *sizeof(unsigned long int)) + 1)
    ,m_buf (new unsigned long int[m_arr_size])
{}

bitVector::~bitVector(){
    m_size = 0;
    m_arr_size = 0;
    delete m_buf;
    m_buf = nullptr;
}

void bitVector::set(int position){
    int arr_index = position / (8 * sizeof(unsigned long int));
    m_buf[arr_index] = m_buf[arr_index] | (1 << position % (8 * sizeof(unsigned long int)));
}

void bitVector::reset(int position){
if(this->get_at(position)){
    int arr_index = position / (8 * sizeof(unsigned long int));
    m_buf[arr_index] = m_buf[arr_index] ^ (1 << position % (8 * sizeof(unsigned long int)));
}

}

bool bitVector::get_at(int position) const{
int arr_index = position / (8 * sizeof(unsigned long int));
return (m_buf[arr_index] & (1 << position % (8 * sizeof(unsigned long int))));
}

int bitVector::get_size() const{
    return m_size;
}

int bitVector::get_arr_size() const{
    return m_arr_size;
}