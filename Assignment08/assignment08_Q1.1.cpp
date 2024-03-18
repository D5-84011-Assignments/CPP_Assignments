#include<iostream>
using namespace std;




int fact(int num){
    int res=1;

    if(num<0){
        throw 2;
    }

    for(int i=1;i<=num;i++){
        res=res*i;
    }

    return res;
}

int main(){
    int num,res;
    cout<<"Enter number to calculate factorial: ";
    cin>>num;
    try{
        res =fact(num);
    cout<<"Factorial of "<<num<<" = "<<res<<endl;
    }
    catch(int error){
        cout<<"Factorial cannot be calculated for a negative number"<<endl;
    }



    return 0;
}