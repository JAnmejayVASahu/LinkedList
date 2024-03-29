#include<iostream>
#include<list>
using namespace std;
int main(){
    list<int> l1 = {1, 2, 3};
    auto itr = l1.begin();
    advance(itr, 2);
    l1.insert(itr, 5);
    cout << "Inserting 5 at 3rd position. -> ";
    for(auto itr = l1.begin(); itr != l1.end(); itr++){
        cout << *itr << " ";
    }cout << endl;
    l1.insert(itr, 3, 5);
    cout << "Befor part inserting again -> ";
    auto l = l1.begin();
    auto r = l1.begin();
    advance(r, 2);
    l1.insert(itr, l, r);
    for(auto itr = l1.begin(); itr != l1.end(); itr++){
        cout << *itr << " ";
    } cout << endl;
    cout << "Delet specific part inserting again -> ";
    auto s_itr = l1.begin();
    advance(s_itr, 2);
    auto e_itr = l1.begin();
    advance(e_itr, 4); // e_itr pointing  to 5th element
    l1.erase(s_itr, e_itr);
    for(auto itr = l1.begin(); itr != l1.end(); itr++){
        cout << *itr << " ";
    } cout << endl;
    return 0;
}
