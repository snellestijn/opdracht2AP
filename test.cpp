#include <iostream>
#include <vector>

int main(){

std::vector<int> hoi;
for (int i = 0 ; i < 11; i++){
    hoi.push_back(i);
}
hoi.erase(hoi.begin()+2);
if (hoi[12]){
    std::cout << "hoi;";
}

}