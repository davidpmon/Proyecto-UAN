/*
1 . Visualizar la información de los productos. 
2. Agregar crédito (monto de dinero) a la máquina.
3. Comprar un producto.
4. Calcular la cantidad total de unidades compradas (de todos los productos).
5. Calcular el valor total por las compras realizadas.
6. Calcular el porcentaje de disponibilidad de la máquina. 
7. Consultar el producto más comprado (del cual ha comprado un mayor número de unidades).
8. Calcular el valor de la donación total al FOPRE por las compras realizadas.
9. Conocer el valor de la donación al FOPRE por tipo de producto. 
10. Conocer las unidades compradas de productos FOPRE y por tipo de producto. 
11. Terminar la compra.  
*/
#include <iostream>
#include <math.h>
using namespace std;

struct cliente
{
    unsigned int saldocli;
};
struct productos
{
    string nombreproduc;
    unsigned int precioproduc;
    unsigned int codigoproduc;
    unsigned int stockproduc;
    bool fopreproduc;
};
struct factura
{
    char fecha;
    char hora;
    string nomproducscomprados;
    unsigned int cantproducscomprados;
};
int main()
{
    productos papas, agua, gaseosa, ponque;
    
    papas.nombreproduc="Papas Margarita";
    agua.nombreproduc="Agua Cristal 600ml";
    gaseosa.nombreproduc= "CocaCola 500ml";
    ponque.nombreproduc="Chocoramo";
    
    papas.precioproduc=2500;
    agua.precioproduc=1200;
    gaseosa.precioproduc=3000;
    ponque.precioproduc=2000;
    
    
    papas.codigoproduc=1101;
    agua.codigoproduc=1102;
    gaseosa.codigoproduc=1103;
    ponque.codigoproduc=1104;
    
    papas.stockproduc=10;
    agua.stockproduc=10;
    gaseosa.stockproduc=10;
    ponque.stockproduc=10;
    
    /*papas.fopreproduc= false;
    agua.fopreproduc= false;
    gaseosa.fopreproduc= true;
    ponque.fopreproduc= true;
    
    if(fopreproduc==true)
    {
     precioproduc= precioproduc*6/100;
    }*/
    
    

    //PRUEBEN LA OPCION DE ABAJO DE MOSTRAR PRODUCTOS
    /*cout<<papas.nombreproduc<<"     "<<agua.nombreproduc<<"    "<<gaseosa.nombreproduc<<"         "<<ponque.nombreproduc<<" \n";
    cout<<"Stock: "<<papas.stockproduc<<" %"<<porcentaje_papas<<"      "<<"Stock:"<<agua.stockproduc<<" %"<<porcentaje_agua<<"         "<<"Stock: "<<gaseosa.stockproduc<<" %"<<porcentaje_gaseosa<<"         "<<"Stock: "<<ponque.stockproduc<<" %"<<porcentaje_ponque<<"\n";
    cout<<"Codigo: "<<papas.codigoproduc<<"        "<<"Codigo: "<<agua.codigoproduc<<"          "<<"Codigo: "<<gaseosa.codigoproduc<<"           "<<"Codigo: "<<agua.codigoproduc<<"\n";
    cout<<"Precio: $"<<papas.precioproduc<<"       "<<"Precio: $"<<agua.precioproduc<<"         "<<"Precio: $"<<gaseosa.precioproduc<<"          "<<"Precio: $"<<ponque.precioproduc<<"\n";
*/
    int vueltas;
    int op;
    do{
        cout<<"\nBIENVENIDO A LA MAQUINA EXPENDEDORA MAS EXPENDEDOSA DEL TODAS LAS MAQUINAS EXPENDEDORAS\n";
        cout<<"******************************************\n";
        cout<<"Seleccione una opción: ";
        cout<<"\n1. Consultar información de los productos\n";
        cout<<"2. Comprar productos\n";
        cout<<"3. Mostrar historial de compras\n";
        cout<<"4. Terminar compra\n";
        cin>>op;
        
        switch(op)
        {
            case 1:
            {
                float porcentaje_papas= papas.stockproduc*10;
                float porcentaje_agua= (agua.stockproduc*100)/10;
                float porcentaje_gaseosa = (gaseosa.stockproduc*100)/10;
                float porcentaje_ponque = (ponque.stockproduc*100)/10;
                
                cout<<"En este momento tenemos disponible los siguientes productos: \n";
                cout<<papas.nombreproduc<<"\nStock: "<<papas.stockproduc<<" -- "<<porcentaje_papas<<"%\nValor: $"<<papas.precioproduc<<" \nCódigo: "<<papas.codigoproduc<<"\n"<<"\n";
                cout<<agua.nombreproduc<<"\nStock: "<<agua.stockproduc<<" -- "<<porcentaje_agua<<"%\nValor: $"<<agua.precioproduc<<" \nCódigo: "<<agua.codigoproduc<<"\n"<<"\n";
                cout<<gaseosa.nombreproduc<<"\nStock: "<<gaseosa.stockproduc<<" -- "<<porcentaje_gaseosa<<"%\nValor: $"<<gaseosa.precioproduc<<" \nCódigo: "<<gaseosa.codigoproduc<<"\n"<<"\n";
                cout<<ponque.nombreproduc<<"\nStock: "<<ponque.stockproduc<<" -- "<<porcentaje_ponque<<"%\nValor: $"<<ponque.precioproduc<<" \nCódigo: "<<ponque.codigoproduc<<"\n"<<"\n";
            }break;
            case 2:
            {
            	cliente A;
                int codigocliente;
                int numerocli;
                bool codigoValido = false;
                if(vueltas<1200)
                {
                    cout<<"\nIngresa tu dinero: ";
	                cin>>A.saldocli;
                }
                else
                {
                    A.saldocli=vueltas;
                }    
                if(A.saldocli>=1200)
	                    {
	                        cout<<"Ingreso de saldo exitoso"<<" \n"<<"Tu saldo actual es de: $"<<A.saldocli<<"\n";
	                        bool codigoValido = false;
	                        while (!codigoValido) 
	                        {
	                            cout << "Ingrese el código del producto: ";
	                            cin >> codigocliente;
	        
	                            if (1101 <= codigocliente and codigocliente <= 1104)
	                            {
	                                if (codigocliente == papas.codigoproduc) 
	                                {
	                                    if(A.saldocli>=papas.precioproduc)
	                                    {
	                                        cout << "Has seleccionado: " << papas.nombreproduc;
	                                        vueltas=A.saldocli-papas.precioproduc;
	                                        cout<<"\nSu saldo final es de: $"<<vueltas<<"\n";
	                                        papas.stockproduc--;
	                                    }
	                                    else
	                                    {
	                                        cout<<"Saldo Insuficiente\n";
	                                        cout<<"Tu cambio es de: $"<<A.saldocli<<"\n";
	                                        break;
	                                    }
	                                } 
	                                else if (codigocliente == agua.codigoproduc) 
	                                {
	                                    if(A.saldocli>=agua.precioproduc)
	                                    {
	                                    cout << "Has seleccionado: " << agua.nombreproduc;
	                                    vueltas=A.saldocli-agua.precioproduc;
	                                    cout<<"\nSu saldo final es de: $"<<vueltas<<"\n";
	                                    agua.stockproduc--;
	                                    }
	                                    else
	                                    {
	                                        cout<<"Saldo Insuficiente";
	                                        cout<<"Tu cambio es de: $"<<A.saldocli<<"\n";
	                                        break;
	                                    }
	                                }
	                                else if (codigocliente == gaseosa.codigoproduc) 
	                                {
	                                    if(A.saldocli>=gaseosa.precioproduc)
	                                    {
	                                    cout << "Has seleccionado: " << gaseosa.nombreproduc;
	                                    vueltas=A.saldocli-gaseosa.precioproduc;
	                                    cout<<"\nSu saldo final es de: $"<<vueltas<<"\n";
	                                    gaseosa.stockproduc--;
	                                    }
	                                    else
	                                    {
	                                        cout<<"Saldo Insuficiente";
	                                        cout<<"Tu cambio es de: $"<<A.saldocli<<"\n";
	                                        break;
	                                    }
	                                }
	                                else if (codigocliente == ponque.codigoproduc)
	                                {
	                                    if(A.saldocli>=ponque.precioproduc)
	                                    {
	                                    cout << "Has seleccionado: " << ponque.nombreproduc;
	                                    vueltas=A.saldocli-ponque.precioproduc;
	                                    cout<<"\nSu saldo final es de: $"<<vueltas<<"\n";
	                                    ponque.stockproduc--;
	                                    }
	                                    else
	                                    {
	                                        cout<<"Saldo Insuficiente";
	                                        cout<<"Tu cambio es de: $"<<A.saldocli<<"\n";
	                                        break;
	                                    }
	                                }
	                                codigoValido = true; // El código ingresado es válido, salimos del bucle
	                            } 
	                            else 
	                            {
	                                cout << "\nCódigo inválido. Por favor, ingrese un código válido.";
	                            }
	                        }    
	                    }
	                    else
	                    {
	                        cout<<"Saldo Insuficiente\n";
	                        cout<<"Recibes $"<<A.saldocli<<" de cambio";
	                    }
                break;
            }break;
            case 3:
            {
                
            }break;
            default:
            {
                cliente A;
                cout<<"Gracias por utilizar nuestra maquina expendedora\n";
                cout<<"Hasta pronto :D\n";
                cout<<"Tu cambio es de $"<<vueltas;
            }
        }
    }while(op!=4);
}

