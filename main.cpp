#include <iostream>
#include <string>

using namespace std;

#define HashMod 30

unsigned long long CharToInt(char entrada)
{
    unsigned long long Salida;
    Salida = entrada;
    return Salida;
}

unsigned long long ObtenerNumero(string entrada)
{
    unsigned long long Salida = 0;

    for(int i=0;entrada[i] != '\0';i++)
    {
        if(entrada[1+i] == '\0' && i == 0)
            Salida += CharToInt(entrada[i]);
        else
        {
            if(i == 0)
            {
                Salida += CharToInt(entrada[i]);
                continue;
            }
            else
            {
                int miChar = CharToInt(entrada[i]);
                if(miChar > 99)
                {
                    Salida *= 1000;
                }
                else if(miChar > 9)
                {
                    Salida *= 100;
                }
                Salida += miChar;
            }
        }
    }
    return Salida;
}

int FuncHash(string entrada)
{
    unsigned long long Amodular = ObtenerNumero(entrada);
    int Salida = Amodular%HashMod;
    return Salida;
}

int main()
{
    string Tabla[HashMod];

    for(int i=0;i<HashMod;i++)
    {
        Tabla[i] = "null";
    }

    int opc;
    do
    {
        cout << "\n---Menu hash---" << endl;
        cout << "1.- Insertar clave" << endl;
        cout << "2.- Ver elementos clave" << endl;
        cout << "3.- Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opc;

        switch(opc)
        {
        case 1:
        {
            string Clave;
            cout << "Ingrese un caracter al que determinara su ascii: "; // Este caracter se almacenar en la tabla hash
            cin >> Clave;
            int Pos = FuncHash(Clave);
            cout << "\nEl valor ascii es: " << ObtenerNumero(Clave);
            cout << "\nValor hash: " << Pos << endl;
            if(Tabla[Pos] == "null" || Tabla[Pos] == Clave)
                Tabla[Pos] = Clave;
            else
                for(int i=Pos;i<HashMod;i++)
                    if(Tabla[i] == "null")
                    {
                        Tabla[i] = Clave;
                        break;
                    }
            break;
        }
        case 2:
        {
            cout << endl;
            for(int i=0;i<HashMod;i++)
            {
                cout << "Elemento #" << i << ": " << Tabla[i] << endl;
            }
            break;
        }
        case 3:
                cout << "\nGracias por usas nuestro programa" << endl;
                break;
        default:
                cout << "\nIngrese una opcion valida" << endl;
                break;
        }
    }while(opc != 3);

        return 0;
    }
