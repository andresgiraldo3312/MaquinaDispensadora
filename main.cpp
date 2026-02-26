
#include <iostream>

using namespace std;

class Slot{
    
    private:
        float precio;
        int cantidad; 
        int capacidad; 
    
    public:
        Slot();
        Slot(float precio_, int capacidad_);
        bool Vacio();
        void Informacion();
        void Vender();
        void FijarPrecio(float precio_);
        void Recargar(int adicion);
    
};


Slot::Slot(){
    
    precio = 0;
    capacidad = 10;
    cantidad = 0;
    
};

bool Slot::Vacio(){
    
    if(cantidad == 0){
        
        return true;    
        
    }else{
        
        return false; 
        
    };
    
};

Slot::Slot(float precio_, int capacidad_){
    
    precio = precio_;
    capacidad = capacidad_;
    cantidad = 0;
    
};

void Slot::FijarPrecio(float precio_){
    
    precio = precio_;
    
};

void Slot::Informacion(){
    
    cout << "Precio: " << precio << endl;
    
    for(int i=0; i < cantidad ; i++){
        cout << '+';    
    }
    
    for(int i=0; i < (capacidad - cantidad); i++){
        cout << '-';
    }
    
    cout << endl;
    
};

void Slot::Recargar(int adicion){
    
    int temporal = cantidad + adicion;
    
    if(capacidad >= temporal){
        
        cantidad = temporal;
        
    }else{
        
        cout << "Error: Recarga invalida cod 02" << endl;   
        
    }
    
};

void Slot::Vender(){
    
    if(cantidad > 0){
        
        cantidad--;
        
    }else{
        
        cout << "Error: Producto no disponible cod 03" << endl;       
        
    }
    
};


class Maquina{
    
    private:
        float saldo;
        Slot bandejas[30];
        int capacidad = 30;
    public:
        Maquina();
        void Recargar(int ID, int adicion);
        void Recargar(int ID, int adicion, float precio);
        void Informacion();
        void Vender(int ID);
    
};

Maquina::Maquina(){
    
    capacidad = 30;
    saldo = 0;
    
}
    
void Maquina::Recargar(int ID, int adicion, float precio){
    
    if(bandejas[ID].Vacio()){
        bandejas[ID].FijarPrecio(precio); 
        bandejas[ID].Recargar(adicion);
    }else{
        cout << "Error: Se debe cambiar metodo de recarga cod 04" << endl;
    }
    
}

void Maquina::Recargar(int ID, int adicion){
    
    bandejas[ID].Recargar(adicion);
    
}

void Maquina::Informacion(){
    
    cout << "==============" << endl;
    
    for(int i = 0; i<capacidad ;i++){
        
        bandejas[i].Informacion();
    }
    
    cout << "==============" << endl << endl;
    
}

int main()
{
    /* Este codigo es para probar la clase Slot
    Slot badejaUno(1500,10);
    badejaUno.Informacion();
    cout << endl;
    badejaUno.Recargar(4);
    badejaUno.Informacion();
    cout << endl;
    badejaUno.Recargar(7);
    badejaUno.Informacion();
    cout << endl;
    badejaUno.Recargar(2);
    badejaUno.Informacion();
    cout << endl;
    badejaUno.Vender();
    badejaUno.Informacion();
    cout << endl;
    badejaUno.Vender();
    badejaUno.Vender();
    badejaUno.Vender();
    badejaUno.Vender();
    badejaUno.Vender();
    badejaUno.Vender();
    badejaUno.Vender();
    badejaUno.Informacion();
    */
    Maquina novaventa;
    
    novaventa.Recargar(0,5,1500);
    novaventa.Recargar(7,3,2600);
    novaventa.Recargar(7,3,2600);
    novaventa.Recargar(7,10);
    novaventa.Recargar(7,3);
    novaventa.Informacion();

    return 0;
}

