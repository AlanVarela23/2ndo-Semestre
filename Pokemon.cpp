/* Alan Varela
   27/02/22

*/


#include <iostream>

class Pokemon
{
    std::string Nombre;
    std::string Tipo;
    std::string Color;
    int Ataque;
    int Salud;
public:    
    //Constructor Generico
    Pokemon()
    {
        Nombre = "NPC";
        Tipo = "Agua";
        Color = "Azul";
        Ataque = 25;
        Salud = 100;
    }
    //Constructor especifico
    Pokemon(std::string _nombre, std::string  _tipo, std::string _color, int _ataque, int _salud)
    {
        Nombre = _nombre;
        Tipo = _tipo;
        Color = _color;
        Ataque = _ataque;
        Salud = _salud;
    }
    //Destructor
    ~Pokemon()
    {
        std::cout<<"Pokemon "<<Nombre<<" ha sido destruido\n"<<std::endl;
    }
    //Setter
    void setNombre(std::string n)
    {
        Nombre = n;
    }
    void setTipo(std::string t)
    {
        Tipo = t;
    }
    void setColor(std::string c)
    {
        Color = c;
    }
    void setAtaque(int a)
    {
        Ataque = a;
    }
    void setSalud(int s)
    {
        Salud = s;
    }
    //Getter
    std::string getNombre()
    {
        return Nombre;
    }
    std::string setTipo()
    {
        return Tipo;
    }
    std::string setColor()
    {
        return Color;
    }
    int setAtaque()
    {
        return Ataque;
    }
    int setSalud() 
    {
        return Salud;
    }

    void Sanar()
    {
        Salud = 100;
    }
    void mostrarAtributos() 
    {
        std::cout << "Nombre: " << Nombre << std::endl;
        std::cout << "Tipo: " << Tipo << std::endl;
        std::cout << "Color: " << Color << std::endl;
        std::cout << "Ataque: " << Ataque << std::endl;
        std::cout << "Salud: " << Salud <<"\n" << std::endl;
    }
    void evolucionarPokemon(std::string _nombre, std::string  _tipo, std::string _color) 
    {
        Nombre = _nombre;
        Tipo = _tipo;
        Color = _color;
        Ataque *= 1.3;
    }
};

int main()
{
    Pokemon Random;
    Random.mostrarAtributos();
    Pokemon Charmander("Charmander","Fuego","Naranja",30,100);
    Charmander.mostrarAtributos();
    Random.setNombre("Pikachu");
    Charmander.evolucionarPokemon("Charmeleon", "Fuego", "Rojo");
    Charmander.mostrarAtributos();
}

