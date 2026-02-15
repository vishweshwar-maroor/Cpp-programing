#include <bits/stdc++.h> 
#include<iostream>

using namespace std;

// Create the classes here
class Shape{
    public:
    string shapeType;
    
    void printMyType(){
        cout<<this->shapeType<<endl;
    } 
};
class Square : public Shape{
    public:
    int leangth;
    Square(int a){
        leangth=a;
        this->shapeType="Square";
    }
    int calculateArea(){
        return (leangth*leangth);
    }
};
class Rectangle : public Shape{
    public:
    int leangth;
    int breadth;

    Rectangle(int l,int b){
        leangth=l;
        breadth=b;
        this->shapeType="Rectangle";
    }
    int calculateArea(){

        return (leangth*breadth);
    }
};

int main() {

    //Write your code here

    Square S(5);
    S.printMyType();
    cout<<S.calculateArea();
    cout<<endl;
    Rectangle R(5,4);
    R.printMyType();
    cout<<R.calculateArea();


    return 0;
}