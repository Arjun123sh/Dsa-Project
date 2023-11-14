// #include<iostream>
// using namespace std;
// class Add_complex{
//     public:
//     int a,b,c,d;
//     int ans1,ans2;
//     void get_data(){
//         cout<<" Enter the real numbers "<<endl;
//         cin>>a>>b;
//         cout<<" Enter the imaginary numbers "<<endl;
//         cin>>c>>d;
//     }
//     void operator+(){
//         ans1=a+b;
//         ans2=c+d;
//     }
//     void show(){
//         cout<<" The addition of two numbers is "<<endl;
//         cout<<ans1<<" + "<<ans2<<"i"<<endl;
//     }
// }n;
// int main(){
//     n.get_data();
//     n.operator+();
//     n.show();
//     return 0;
// }
// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cout<<" Enter the value of n "<<endl;
//     cin>>n;
//     int no;
//     for(int i=1;i<=n;i++){
//         no=0;
//         for(int j=1;j<=i;j++){
//             if(j%2!=0)
//             cout<<0<<" ";
//             else
//             cout<<1<<" ";
//         }cout<<endl;
//     }
//     return 0;
// }
// #include<iostream>
// using namespace std;
// class base1{
//     public:
//     int data1;
//     base1(int d){
//         data1=d;
//         cout<<" Base1 class constructor called "<<endl;
//     }
// };
// class base2{
//     public:
//     int data2;
//    base2(int d){
//         data2=d;
//         cout<<" base2 class constructor called "<<endl;
//     }  
// };
// class derived:public base1,virtual public base2{
//     public:
//     int data3;
//     derived(int i,int j,int k):base1(j),base2(k){
//         data3=i;
//         cout<<" Derived class constructor called "<<endl;
//     }
// };
// int main(){
//     derived d(1,2,3);
//     return 0;
// }
// #include<iostream>
// using namespace std;
// class base1{
//     public:
//     int a;
//     void get_data1(){
//         cout<<" Enter the value of a "<<endl;
//         cin>>a;
//     }
//     void print_data1(){
//         cout<<" The vaue of a is "<<a<<endl;
//     }
// };
// class Derived1:public base1{
//     public:
//     int b;
//     void get_data2(){
//         cout<<" Enter the value of b "<<endl;       //single level inheritance
//         cin>>b;
//     }
//     void print_data2(){
//         cout<<" The vaue of b is "<<b<<endl;
//     }
// };
// class Derived2: public base1, public Derived1{
//     public:
//     int c;
//     void get_data3(){
//         cout<<" Enter the value of c "<<endl;       //Multilevel level inheritance
//         cin>>c;
//     }
//     void print_data2(){
//         cout<<" The vaue of c is "<<c<<endl;
//     }
// };
// class base2{
//     public:
//     int d;
//     void get_data4(){
//         cout<<" Enter the value of d "<<endl;       
//         cin>>d;
//     }
//     void print_data4(){
//         cout<<" The vaue of d is "<<d<<endl;
//     }
// };
// class derived3:public base1,public base2{
//     public:
//     int e;
//     void get_data5(){
//         cout<<" Enter the value of e "<<endl;       //multiple inheritance
//         cin>>e;
//     }
//     void print_data4(){
//         cout<<" The vaue of e is "<<e<<endl;
//     }
// };
// class derived4:public base1{
//     public:
//     int f;
//     void get_data5(){
//         cout<<" Enter the value of f "<<endl;       //multiple inheritance
//         cin>>f;
//     }
//     void print_data4(){
//         cout<<" The vaue of f is "<<f<<endl;
//     }
// };
// class derived5:public base1{
//     public:
//     int g;
//     void get_data5(){
//         cout<<" Enter the value of g "<<endl;       //Heirachical inheritance
//         cin>>g;
//     }
//     void print_data5(){
//         cout<<" The vaue of g is "<<g<<endl;
//     }
// };
#include<iostream>
using namespace std;
// void volume(int l,int b,int h){
//     cout<<" The volume of the cube is "<<l*b*h<<endl;
// }
// void area_andPerimeter(int l,int b ,int &perimeter,int &area){
//     perimeter=2*(l+b);
//     area=l*b;
// }
// int main(){
//     int perimeter=0;
//     int area=0;
//     area_andPerimeter(1,2,perimeter,area);
//     cout<<" The perimter of the rectangle is "<<perimeter<<endl;
//     cout<<" The area of the rectangle is "<<area<<endl;
//     return 0;
// }
// class A{

// }a;
// int main(){
//     cout<<" The size of the class is "<<sizeof(a)<<endl;
//     return 0;
// }
class A{
    int a;
    void get_data(){
        cout<<" Enter the value of a "<<endl;
        cin>>a;
    }
    public:
    void print(){
        get_data();
        cout<<a<<endl;
    }
}ob;
int main(){
    ob.print();
    return 0;
}