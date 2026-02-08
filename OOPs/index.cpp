#include<iostream>
#include <cstddef>
using namespace std;
class Hero {
    public:
    string name;
    int health;
    Hero(int health,string name){
        this->health=health;
        this->name=name;
    }
    // Hero(Hero obj_name,string name){
    //     this->health=obj_name.health;
    //     this->name=name;
    // }
    
};
int main(){
    Hero R(50,"R");
    Hero S(R);
    R.name="t";
    cout<<R.name<<S.name;

   
}