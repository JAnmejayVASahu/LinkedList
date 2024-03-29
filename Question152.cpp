#include<iostream>
#include<list>
using namespace std;
int main(){
    // range based loop.
    list<int> l1 = {1, 2, 3};
    for(auto num: l1){
        cout << num << " ";
    }
    return 0;
}
