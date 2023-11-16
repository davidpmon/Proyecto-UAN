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

//1. Cantidad 2. Los productos que se compraron 3.Total de dinero recibido
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
    int totalproductoscomprados;
    int fp;
};
struct factura
{
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
    
    papas.fopreproduc=false;
    agua.fopreproduc=false;
    gaseosa.fopreproduc=true;
    ponque.fopreproduc=true;
    
    papas.precioproduc=2500;
    agua.precioproduc=1200;
    gaseosa.precioproduc=3000;
    ponque.precioproduc=2000;
    
    if(papas.fopreproduc==true)
    {
        papas.fp=papas.precioproduc*0.06;
    }
    if(agua.fopreproduc==true)
    {
        agua.fp=agua.precioproduc*0.06;
    }
    if(gaseosa.fopreproduc==true)
    {
        gaseosa.fp=gaseosa.precioproduc*0.06;
    }
    if(ponque.fopreproduc==true)
    {
        ponque.fp=ponque.precioproduc*0.06;
    }
    
    gaseosa.precioproduc=3000*1.06;
    ponque.precioproduc=2000*1.06;
    
    papas.codigoproduc=1101;
    agua.codigoproduc=1102;
    gaseosa.codigoproduc=1103;
    ponque.codigoproduc=1104;
    
    papas.stockproduc=10;
    agua.stockproduc=10;
    gaseosa.stockproduc=10;
    ponque.stockproduc=10;
    
    papas.totalproductoscomprados;
    agua.totalproductoscomprados;
    gaseosa.totalproductoscomprados;
    ponque.totalproductoscomprados;
    
    
    

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
        cout<<"******************************************************************************************\n";
        cout<<"Seleccione una opción: ";
        cout<<"\n1. Consultar información de los productos\n";
        cout<<"2. Comprar productos\n";
        cout<<"3. Mostrar historial de compras\n";
        cout<<"4. Terminar compra\n";
        cout<<"******************************************************************************************\n";
        cin>>op;
        
        int productoscomprados;
        int valorproductoscomprados=0;
        int donacionfopre;
        if(op>0 and op<=4)
        {
            switch(op)
            {
                case 1:
                {
                    float porcentaje_papas= papas.stockproduc*10;
                    float porcentaje_agua= (agua.stockproduc*100)/10;
                    float porcentaje_gaseosa = (gaseosa.stockproduc*100)/10;
                    float porcentaje_ponque = (ponque.stockproduc*100)/10;
                    
                    cout<<"En este momento tenemos disponible los siguientes productos: \n";
                    cout<<"Algunos productos forman parte del FOPRE, es una donacion del 6% del valor del producto a una fundacion ;)\n";
                    cout<<papas.nombreproduc<<"\nStock: "<<papas.stockproduc<<" -- "<<porcentaje_papas<<"%\nValor: $"<<papas.precioproduc<<"\nValor del FOPRE: $"<<papas.fp<<" \nCódigo: "<<papas.codigoproduc<<"\n"<<"\n";
                    cout<<agua.nombreproduc<<"\nStock: "<<agua.stockproduc<<" -- "<<porcentaje_agua<<"%\nValor: $"<<agua.precioproduc<<"\nValor del FOPRE: $"<<agua.fp<<" \nCódigo: "<<agua.codigoproduc<<"\n"<<"\n";
                    cout<<gaseosa.nombreproduc<<"\nEste producto hace parte del FOPRE"<<"\nStock: "<<gaseosa.stockproduc<<" -- "<<porcentaje_gaseosa<<"%\nValor: $"<<gaseosa.precioproduc<<"\nValor del FOPRE: $"<<gaseosa.fp<<" \nCódigo: "<<gaseosa.codigoproduc<<"\n"<<"\n";
                    cout<<ponque.nombreproduc<<"\nEste producto hace parte del FOPRE"<<"\nStock: "<<ponque.stockproduc<<" -- "<<porcentaje_ponque<<"%\nValor: $"<<ponque.precioproduc<<"\nValor del FOPRE: $"<<ponque.fp<<" \nCódigo: "<<ponque.codigoproduc<<"\n"<<"\n";
                    
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
    	                                    if (papas.stockproduc>0)
    	                                    {
    	                                        if(A.saldocli>=papas.precioproduc)
        	                                        {
        	                                            papas.precioproduc=2500;
            	                                        if(papas.fopreproduc==true)
                                                        {
                                                            donacionfopre=donacionfopre+(papas.precioproduc*0.06);
                                                            papas.precioproduc= papas.precioproduc+papas.precioproduc*6/100;
                                                        }
        	                                            cout << "Has seleccionado: " << papas.nombreproduc;
        	                                            vueltas=A.saldocli-papas.precioproduc;
        	                                            cout<<"\nSu saldo final es de: $"<<vueltas<<"\n";
        	                                            papas.stockproduc--;
        	                                            productoscomprados++;
        	                                            papas.totalproductoscomprados++;
        	                                        }
    	                                        else
    	                                        {
    	                                        cout<<"Saldo Insuficiente\n";
    	                                        cout<<"Tu cambio es de: $"<<A.saldocli<<"\n";
    	                                        break;
    	                                        }
    	                                    }
    	                                    else
    	                                    {
    	                                        cout<<"No hay stock de este producto por favor elige otro";
    	                                        break;
    	                                    }
    	                                } 
    	                                else if (codigocliente == agua.codigoproduc) 
    	                                {
    	                                    if(agua.stockproduc>0)
    	                                    {
        	                                    if(A.saldocli>=agua.precioproduc)
        	                                    {
        	                                        agua.precioproduc=1200;
        	                                        
        	                                        if(agua.fopreproduc==true)
                                                    {
                                                        donacionfopre=donacionfopre+(agua.precioproduc*0.06);
                                                        agua.precioproduc= agua.precioproduc+agua.precioproduc*6/100;
                                                    }
        	                                        cout << "Has seleccionado: " << agua.nombreproduc;
        	                                        vueltas=A.saldocli-agua.precioproduc;
        	                                        cout<<"\nSu saldo final es de: $"<<vueltas<<"\n";
        	                                        agua.stockproduc--;
        	                                        productoscomprados++;
        	                                        agua.totalproductoscomprados++;
        	                                    }
        	                                    else
        	                                    {
        	                                        cout<<"Saldo Insuficiente";
        	                                        cout<<"Tu cambio es de: $"<<A.saldocli<<"\n";
        	                                        break;
        	                                    }
    	                                    }
    	                                    else
    	                                    {
    	                                        cout<<"No hay stock de este producto por favor elige otro";
    	                                        break;
    	                                    }
    	                                }
    	                                else if (codigocliente == gaseosa.codigoproduc) 
    	                                {
    	                                    if(gaseosa.stockproduc>0)
    	                                    {
        	                                    if(A.saldocli>=gaseosa.precioproduc)
        	                                    {
        	                                        gaseosa.precioproduc=3000;
        	                                        if(gaseosa.fopreproduc==true)
                                                    {
                                                        donacionfopre=donacionfopre+(gaseosa.precioproduc*0.06);
                                                        gaseosa.precioproduc= gaseosa.precioproduc+gaseosa.precioproduc*6/100;
                                                    }
        	                                        cout << "Has seleccionado: " << gaseosa.nombreproduc;
        	                                        vueltas=A.saldocli-gaseosa.precioproduc;
        	                                        cout<<"\nSu saldo final es de: $"<<vueltas<<"\n";
        	                                        gaseosa.stockproduc--;
        	                                        productoscomprados++;
        	                                        gaseosa.totalproductoscomprados++;
        	                                    }
        	                                    else
        	                                    {
        	                                        cout<<"Saldo Insuficiente";
        	                                        cout<<"Tu cambio es de: $"<<A.saldocli<<"\n";
        	                                        break;
        	                                    }
    	                                    }
    	                                    else
    	                                    {
    	                                        cout<<"No hay stock de este producto por favor elige otro";
    	                                        break;
    	                                    }
    	                                    
    	                                }
    	                                else if (codigocliente == ponque.codigoproduc)
    	                                {
    	                                    if(ponque.stockproduc>0)
    	                                    {
        	                                    if(A.saldocli>=ponque.precioproduc)
        	                                    {
        	                                        ponque.precioproduc=2000;
        	                                        if(ponque.fopreproduc==true)
                                                    {
                                                        donacionfopre=donacionfopre+(ponque.precioproduc*0.06);
                                                        ponque.precioproduc= ponque.precioproduc+ponque.precioproduc*6/100;
                                                    }
        	                                        cout << "Has seleccionado: " << ponque.nombreproduc;
            	                                    vueltas=A.saldocli-ponque.precioproduc;
            	                                    cout<<"\nSu saldo final es de: $"<<vueltas<<"\n";
            	                                    ponque.stockproduc--;
            	                                    productoscomprados++;
            	                                    ponque.totalproductoscomprados++;
        	                                    }
        	                                    else
        	                                    {
        	                                        cout<<"Saldo Insuficiente";
        	                                        cout<<"Tu cambio es de: $"<<A.saldocli<<"\n";
        	                                        break;
        	                                    }
    	                                    }
    	                                    else
    	                                    {
    	                                        cout<<"No hay stock de este producto por favor elige otro";
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
                    cout<<"Se vendieron un total de "<<productoscomprados<<" productos en este lapso de tiempo.\n";
                    valorproductoscomprados = ((papas.totalproductoscomprados*papas.precioproduc)+(agua.totalproductoscomprados * agua.precioproduc)+(gaseosa.totalproductoscomprados*gaseosa.precioproduc)+(ponque.totalproductoscomprados*ponque.precioproduc));
                    cout<<"El valor total de las ventas fue de: $"<<valorproductoscomprados;
    
                    if(papas.totalproductoscomprados>agua.totalproductoscomprados and papas.totalproductoscomprados>gaseosa.totalproductoscomprados and papas.totalproductoscomprados>ponque.totalproductoscomprados)
                    {
                        cout<<"\nEl producto más vendido fue Las Papas Margarita\n";
                    }
                    else if(agua.totalproductoscomprados>papas.totalproductoscomprados and agua.totalproductoscomprados>gaseosa.totalproductoscomprados and agua.totalproductoscomprados>ponque.totalproductoscomprados)
                    {
                        cout<<"\nEl producto más vendido fue Agua Cristal 600ml\n";
                    }
                    else if(gaseosa.totalproductoscomprados>agua.totalproductoscomprados and gaseosa.totalproductoscomprados>papas.totalproductoscomprados and gaseosa.totalproductoscomprados>ponque.totalproductoscomprados)
                    {
                        cout<<"\nEl producto más vendido fue la CocaCola 500ml\n";
                    }
                    else if(ponque.totalproductoscomprados>agua.totalproductoscomprados and ponque.totalproductoscomprados>gaseosa.totalproductoscomprados and ponque.totalproductoscomprados>papas.totalproductoscomprados)
                    {
                        cout<<"\nEl producto más vendido fue El Chocoramo\n";
                    }
                    cout<<"\n******************************************************************\n";
                    
                    cout<<"Tu donacion total al FOPRE fue de $"<<donacionfopre<<"\n";
                    
                    cout<<"********************************************************************\n";
                    
                }break;
                default:
                {
                    cliente A;
                    cout<<"Gracias por utilizar nuestra maquina expendedora\n";
                    cout<<"Hasta pronto :D\n";
                    cout<<"Tu cambio es de $"<<vueltas;
                }
            }
        }
        else
        {
            cout<<"Por favor ingrese una opción válida";
        }
    }while(op!=4);
}





