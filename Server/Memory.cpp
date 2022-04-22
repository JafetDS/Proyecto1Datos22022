//
// Created by Jafet on 22/04/2022.
//

#include "Memory.h"



string Memory::getImage(int n) {
    //  if(Page!=(int)(n-1)/2){
    ChangePage(n);
    //  }
    int i;
    if(n%2 == 0 ){
        i = 0;
    }else{
        i = 1;
    }
    return compimg(i);
}

void Memory::ChangePage(int n) {

    images[0].close();
    images[1].close();


    Page = (int)(n-1)/2;

    images[0] = ifstream("://IMG/page"+(string) to_string(Page)+"/img0.png", ios::in | ios::binary);
    images[1] = ifstream( "://IMG/page"+(string) to_string(Page)+"/img1.png",ios::in | ios::binary);


}

string Memory::compimg(int i ){

    string Bima;
    char c;
    while (!images[i].eof()){
        c = images[i].get();
        Bima.push_back(c);
    }
    return Bima;
}


Memory::Memory() {
    Page  = 0;
    images[0] = ifstream("://IMG/page"+(string) to_string(Page)+"/img0.png", ios::in | ios::binary);
    images[1] = ifstream( "://IMG/page"+(string) to_string(Page)+"/img1.png",ios::in | ios::binary);
}

