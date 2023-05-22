#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

//Pembuatan struktur data graph dengan bahasa c++
//created by : Alef

int arr[10][10],complated[10],n,cost=0;

struct Vertex{
    int angka;
    Vertex *next, *prev;
};
Vertex *head=NULL, *tail=NULL, *baru, *bantu, *hapus;

void inputList(){
	system("cls");
    baru = new Vertex;
    baru->next = NULL;
    baru->prev = NULL;
    cout<<"Input Vertex\t: ";
    cin>>baru->angka;
    if(head == NULL){
        head = tail = baru;
    }
    else{
        baru->next = head;
        head->prev = baru;
        head = baru;
    }
}

void hapusList(){
    if(head->next == NULL){
        head = tail = NULL;
        cout<<"\nEmpty.........!\n";
    }
    else{
        hapus = head;
        head = head->next;
        head->prev = NULL;
        delete hapus;
    }
}

void outputList(){
    bantu = head;
    while(bantu != NULL){
        cout<<"-->"<<bantu->angka;
        bantu = bantu->next;
    }
    cout<<"\n\n";
}

void adjencyList(){
    system("cls");
    int cho1;
    do{
        cout<<"    Adjency List        "
        <<"\n+----------------------+"
        <<"\n|1.Input Vertex        |"
        <<"\n|2.Hapus Vertex        |"
        <<"\n|3.Output              |"
        <<"\n+----------------------+"
        <<"\nchoose -> ";
        cin>>cho1;
        switch (cho1)
        {
        case 1:
            inputList();
            break;
        case 2:
            hapusList();
            break;
        case 3:
            if(baru == NULL){
                cout<<"Data is empty........!\n\n";
            }
            else{
                outputList();
            }
            break;
        default:
            break;
        }
    }while(cho1 <= 3);
}

void takeInput(){ //membuat data graph dengan metode matriks
    system("cls");
    int i,j;
    cout<<"Masukkan Jumlah Data : "; //jumlah data vertex (tidak menyatakan data edge)
    cin>>n;
    cout<<"\nInput Nilai Via Matriks\n";
    for(i=0; i < n; i++){
        cout<<"\nElement data baris ke : "<<i+1<<"\n";
        for(j=0; j < n; j++)
        cin>>arr[i][j]; //menginput value untuk menyatakan relasi
        complated[i]=0;
        system("cls");
    }
    cout<<"\n\nMatriks List  : \n"; //tabel dari sebuah graph
    for(i=0; i < n; i++){
        cout<<"\t"<<i+1;
    }
    for(i=0; i < n; i++){
    	cout<<"\n";
    	cout<<i+1;
        for(j=0; j < n; j++){
        	cout<<"\t"<<arr[i][j];
		}
    }
    cout<<"\n\n";
}

void graphCond(){ //data graph matriks dengan metode pernyataan
    bool ketemu, nolsemua;
    int matrix[10][10];
    int i,j,jumlah_simpul,jumlah_sisi,asal,tujuan;
    cout<<"Jumlah simpul\t: ";  //menginput jumlah vertex
    cin>>jumlah_simpul;
    cout<<"Jumlah sisi  \t: ";  //menginput jumlah edge
    cin>>jumlah_sisi;
    for(i=1; i <= jumlah_simpul; i++){
        for(j=1; j <= jumlah_simpul; j++){
            matrix[i][j]=0;
        }  //membuat sebuah matriks dengan nilai 0
    }

    for(i=1; i <= jumlah_sisi; i++){
        cout<<"Simpul asal  \t: "; //vertex titik awal
        cin>>asal;
        cout<<"Simpul tujuan\t: "; //vertex titik tujuan
        cin>>tujuan;
            matrix[asal][tujuan]=1;
            matrix[tujuan][asal]=1;
        system("cls");
    } //menginput value vertex dalam data graph
        //jika diinput maka nilai dari matriks = 1

    i=1;
    nolsemua=false;
    while(i <= jumlah_simpul && nolsemua == false){
        j=1;
        ketemu=false;
        while(j <= jumlah_simpul && ketemu == false){ 
            if(matrix[i][j] == 1){ //Statement condition if untuk menganalisis pernyataan pada graph
                ketemu = true;
            }
            else{
                j++; //jika sebuah matriks mempunyai value 0, maka akan di arahkan ke else(pernyataan nilai false)
            } // value dari variable j akan berubah jika menyatakan nilai false
        }
        if(ketemu == false){
            nolsemua = true;
        }
        else{
            i++;
        }
    }

    if(nolsemua == true){
        cout<<"graph tidak terhubung.......!";
    }
    else{
        cout<<"graph terhubung.......!";
    }
    cout<<"\n\n";
}

//fungsi utama
int main(){
    int choose;
    do{
        cout<<"      Data Graph        "
        <<"\n+----------------------+"
        <<"\n|1.Matriks Mode        |"
        <<"\n|2.Pernyataan          |"
        <<"\n|3.Adjency List        |"
        <<"\n|Lainnya >> Keluar     |"
        <<"\n+----------------------+"
        <<"\nchoose -> ";
        cin>>choose;
        switch(choose){
            case 1 :
                takeInput();
                break;
            case 2 :
                graphCond();
                break;
            case 3:
                adjencyList();
                break;
            default :
                cout<<"----Anda Keluar----";
                break;  
        }
    }while(choose <= 3);
    getch();
    return 0;
}
