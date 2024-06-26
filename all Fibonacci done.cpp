#include <iostream>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace std::chrono;

long long fibonacciRekursif(int n){
    if (n<=1)
        return n;
    return fibonacciRekursif(n-1)+fibonacciRekursif(n-2);
}

long long fibonacciDynamic(int n){
    if (n<=1)
        return n;
    long long a=0,b=1,c;
    for (int i=2; i<=n; i++){
        c=a+b; a=b; b=c;
    }return b;
}

void ukurWaktuEksekusi(){
    int nilai_n[]={10,25,30,40,50};
    cout<<left<<setw(5)<<"n"
        <<setw(20)<<"Hasil Rekursif"
        <<setw(25)<<"Waktu Rekursif (ms)"
        <<setw(20)<<"Hasil dynamic"
        <<setw(20)<<"Waktu dynamic (ms)"<<endl;

    for (int n:nilai_n){
        auto mulai=high_resolution_clock::now();
        long long hasil_rekursif=fibonacciRekursif(n);
        auto akhir=high_resolution_clock::now();
        auto durasi_rekursif=duration_cast<milliseconds>(akhir-mulai).count();

        mulai=high_resolution_clock::now();
        long long hasil_dynamic=fibonacciDynamic(n);
        akhir=high_resolution_clock::now();
        auto durasi_dynamic=duration_cast<milliseconds>(akhir-mulai).count();

        cout<<left<<setw(5)<<n
            <<setw(20)<<hasil_rekursif
            <<setw(25)<<durasi_rekursif
            <<setw(20)<<hasil_dynamic
            <<setw(20)<<durasi_dynamic<<endl;
    }
}

