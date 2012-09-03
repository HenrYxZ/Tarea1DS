#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include "kangaroolinked.h"
#include "kangaroo.h"
#include "kangarooarray.h"

using namespace std;

int str2int (const string &str) {
  stringstream ss(str);
  int num;
  ss >> num;
  return num;
}
double str2double( const string& s )
 {
   istringstream i(s);
   double x;
   if (!(i >> x))
     return 0;
   return x;
 }

int main(int argc, char *argv[])
{



//SI SE QUIERE OCUPAR LA INTERFAZ HACER kangarooList* k = new kangarooLinked(); o new KangarooArray();
//y cambiar lo que sea pertinente	

kangarooLinked k;

cout<<k.size()<<endl;    

string dir;  
        cout << "Ingrese ruta del archivo: " << endl;
        cin >>  dir;
        
        const char* c = dir.c_str();
        
        ifstream file( c );

for(;;){
    int op, x, n,j;
    double d,s;
    string str,name;
    system("cls");
    cout<<"----------"<<endl;
    cout<<"|CANGUROS|"<<endl;
    cout<<"----------"<<endl<<endl;
    cout<<"(1) Agregar canguros"<<endl;
    cout<<"(2) Listar canguros"<<endl;
    cout<<"(3) Consultar por salto"<<endl;
    cout<<"(4) Consultar por nombre"<<endl;
    cout<<"(5) Consultar por salto y nombre"<<endl;
    cout<<"(6) Consultar existencia"<<endl;
    cout<<"(7) Eliminar canguro"<<endl;
    cout<<"(8) Agregar canguros desde archivo (input.txt)"<<endl;
    cout<<"(0) SALIR"<<endl<<endl;
    cout<<"Ingrese opcion:"<<endl;
    cin>>op;
    
    switch(op){
        //
        case 1:
        system("cls");
        cout<<"Ingrese numero de canguros"<<endl<<endl;
        cin>>n;
        for(int i=0;i<n;i++){
        system("cls");
        cout<<"Ingrese nombre de canguro("<<i<<"):"<<endl<<endl;
        cin>>str;
        cout<<"Ingrese salto de <"<<str<<">:"<<endl<<endl;
        cin>>d;
        kangaroo element=kangaroo(d,str);
            k.add(k.size(),element);
        }
        system("PAUSE");
        break;
        //
        case 2:
        system("cls");
        cout<<"LISTA DE CANGUROS"<<endl;
        cout<<k<<endl;
        system("PAUSE");
        break;
        
        case 3:
             
             int j;
             double s;
        system("cls");
        cout<<"(1) Saltos menores que: "<<endl;
        cout<<"(2) Saltos mayores que:"<<endl;
        cout<<"(3) Saltos iguales a: "<<endl;
        cin >> j;
        switch(j){
                  case 1:
             system("cls");
             cout<<"Ingrese el valor de salto"<<endl;
             cin >> s;
             
             for(int i=0;i < k.size(); i++)
             {
                     if(k.get(i).getJump() < s)
                     {
                          cout << "(" << i << ") ";
                          cout << k.get(i) << endl;   
                     }    
             }
             system("PAUSE");
             break;
          
                  case 2:
             system("cls");
             cout<<"Ingrese el valor de salto"<<endl;
             cin >> s;
             
             for(int i=0;i < k.size(); i++)
             {
                     if(k.get(i).getJump() > s)  
                     {
                          cout << "(" << i << ") ";
                          cout << k.get(i) << endl;   
                     }        
             }
             system("PAUSE");
             break;
             
             
                   case 3:
             system("cls");
             cout<<"Ingrese el valor de salto"<<endl;
             cin >> s;
             
             for(int i=0;i < k.size(); i++)
             {
                     if(k.get(i).getJump() == s)  
                     {
                          cout << "(" << i << ") ";
                          cout << k.get(i) << endl;   
                     }       
             }
             system("PAUSE");
                  break;
                  
                  default:
                          cout << "Error";
                          system("PAUSE");
                  break;
                       
             //switch(j)     
           }
           system("PAUSE");
        break;
        
        
        case 4:
             
             
             system("cls");
             cout<<"Ingrese el nombre del canguro"<<endl;
             cin >> name;
             
             for(int i=0;i < k.size(); i++)
             {
                     if(k.get(i).getName() == name)  
                     {
                          cout << "(" << i << ") ";
                          cout << k.get(i) << endl;   
                     }       
             }
             system("PAUSE");
             break;
            
        
        case 5:
             
             
             system("cls");
             cout<<"Ingrese el nombre del canguro"<<endl;
             cin >> name;
             cout<<"Ingrese el salto del canguro"<<endl;
             cin >> s;
             
             for(int i=0;i < k.size(); i++)
             {
                     if( k.get(i).getName() == name && k.get(i).getJump() == s )  
                     {
                          cout << "(" << i << ") ";
                          cout << k.get(i) << endl;   
                     }        
             }
             
             system("PAUSE");
             break;
             
        
        case 6:
             system("cls");
             cout << "La cantidad de elementos en lista son:           " << k.size();
             system("PAUSE");
             break;
             
             
        case 7:
             
             system("cls");
             int index;
             cout << "Ingrese el indice en lista del canguro a eliminar" << endl;
             cin >> index;
             cout << "Se eliminara a: "<<endl;
             cout << k.get(index);
             k.remove(index);
             system("PAUSE");
             break;
             
        
        
        case 8:
            
// checkear errores falta aqui
        system("cls");


        
        
        getline( file, str ) ;
        n=str2int(str);
        
       
        
        while( getline( file, str ) )
        {
            
            
            
            string s;
            istringstream iss(str,istringstream::in);
            getline( iss, s, '\t' );
            string nombre=s;    
            getline( iss, s, '\t' );
            double salto=str2double(s);
            cout<<"S:"<<salto<<"\tN:"<<nombre<<endl;
            //cout<<"SIZE:"<<k.size()<endl;
            kangaroo element=kangaroo(salto,nombre);
            k.add(k.size(),element);
        
        
        }
            
            cout<<"-----------------------------"<<endl;
            cout<<k.size()<<" Canguros fueron ingresados correctamente"<<endl;
            system("PAUSE");
        break;
        
        case 0:
        exit (0);
        system("PAUSE");
        break;
        
        default:
        system("cls");
        cout<<"OPCION NO VALIDA"<<endl<<endl;
        system("PAUSE");
        break;
        }
    }
    system("PAUSE");
	return EXIT_SUCCESS;
}
