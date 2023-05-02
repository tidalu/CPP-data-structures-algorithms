
#include <iostream>

struct person {
    std::string first_name;
    std::string last_name;
    std::string get_password(){
        return password;
    }
    private: 
        std::string password = "Gold";
    
};


int main()
{
    
    person me;
    me.first_name = "alif";
    me.last_name = "tidalu";
    // me.password = "gold";  it wont work cuz it si private
    
    
    std::cout<< "First Name: " << me.first_name << std::endl;
    std::cout<< "Password: " << me.get_password() << std::endl;
    
    return 0;
}
