
#include <iostream>
#include <string>

// void Print(int value){
//     std::cout << value << std::endl;
// }

// void Print(std::string value){
//     std::cout << value << std::endl;
// }
// void Print(float value){
//     std::cout << value << std::endl;
// }
//   this codes are just repetetive to avoid that we should create template

template<typename T>
void Print(T value)
{
    std::cout << value << std::endl;
}

template<typename T, int N>
class Array {
    private: 
        T m_Array[N];
    public:
        T GetSize() const {return N;}
};
int main()
{
    
    Print<int>(5); // there int is typename , it is repaced  with typename on the template so, it is actually no need to write, but to explain, we can specify the type there but no nee to
    Print("hello");
    Print(5.5f);
    
    Array<int, 50> array;
    std::cout << array.GetSize() << std::endl;
    std::cin.get();
    return 0;
}
