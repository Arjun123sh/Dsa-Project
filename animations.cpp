#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
void ani(char a[100]){
    for(int i=0;i<strlen(a);i++){
        for(int j=0;j<10000000;j++);
        cout<<a[i];
    }
}
void loading_animation(){
    std::cout << "Loading Please Wait";
    for(int i=0;i<2;i++)
    {
        sleep(1);
        std::cout << "." << std::flush;
        sleep(1);
        std::cout << "." << std::flush;
        sleep(1);
        std::cout << "." << std::flush;
        sleep(1);
        std::cout << "\b\b\b   \b\b\b" << std::flush;
    }
    sleep(1);
    cout<<endl;
}