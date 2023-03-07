/* Alan Varela
   27/02/22 1er cambio
   06/03.23 2do cambio Herencia
*/


#include <iostream>

class Pokemon
{
protected:
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
    std::string getTipo()
    {
        return Tipo;
    }
    std::string getColor()
    {
        return Color;
    }
    int getAtaque()
    {
        return Ataque;
    }
    int getSalud() 
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
class PokemonAgua : public Pokemon
{
protected:    
    int tiempoEnAgua;
    int tiempoEnAire;
public:
    //Constructor Generico
    PokemonAgua() : Pokemon ()
    {
        tiempoEnAgua = 15;
        tiempoEnAire = 20;
    }
    //Constructor Especifico 
    PokemonAgua(std::string _nombre, std::string  _tipo, std::string _color, int _ataque, int _salud, int _tiempoEnAgua, int _tiempoEnAire)
    {
        Nombre = _nombre;
        Tipo = _tipo;
        Color = _color;
        Ataque = _ataque;
        Salud = _salud;
        tiempoEnAgua = tiempoEnAgua;
        tiempoEnAire = tiempoEnAire;
    }
    //Destructor
    ~PokemonAgua()
    {
        std::cout << "Pokemon Agua " << Nombre << " ha sido destruido\n" << std::endl;
    }
    //Setter
    void setTiempoEnAgua(int _tiempoEnAgua)
    {
        tiempoEnAgua = _tiempoEnAgua;
    }
    void setTiempoEnAire(int _tiempoEnAire)
    {
        tiempoEnAire = _tiempoEnAire;
    }
    //Getter
    int getTiempoEnAgua()
    {
        return tiempoEnAgua;
    }
    int getTiempoEnAire()
    {
        return tiempoEnAire;
    }

    void Nadar()
    {
        tiempoEnAgua += 100;
        tiempoEnAire = 0;
    }
};

class PokemonPlanta : public Pokemon
{
protected:
    int tiempoVida;
  
public:
    //Constructor Generico
    PokemonPlanta() : Pokemon()
    {
        tiempoVida = 15;
   
    }
    //Constructor Especifico 
    PokemonPlanta(std::string _nombre, std::string  _tipo, std::string _color, int _ataque, int _salud, int _tiempoVida)
    {
        Nombre = _nombre;
        Tipo = _tipo;
        Color = _color;
        Ataque = _ataque;
        Salud = _salud;
        tiempoVida = _tiempoVida;
    }
    //Destructor
    ~PokemonPlanta()
    {
        std::cout << "Pokemon Planta " << Nombre << " ha sido destruido\n" << std::endl;
    }
    //Setter
    void setTiempoVida(int _tiempoVida)
    {
        tiempoVida = _tiempoVida;
    }
    //Getter
    int getTiempoVida()
    {
        return tiempoVida;
    }

    void Fotosintesis()
    {
        tiempoVida += 50;
    }
};

class PokemonFuego : public Pokemon
{
protected:
    int temperatura;
public:
    //Constructor Generico
    PokemonFuego() : Pokemon()
    {
        temperatura = 10;
    }
    //Constructor Especifico 
    PokemonFuego(std::string _nombre, std::string  _tipo, std::string _color, int _ataque, int _salud, int _tiempoEnAgua, int _temperatura)
    {
        Nombre = _nombre;
        Tipo = _tipo;
        Color = _color;
        Ataque = _ataque;
        Salud = _salud;
        temperatura = _temperatura;
    }
    //Destructor
    ~PokemonFuego()
    {
        std::cout << "Pokemon Fuego " << Nombre << " ha sido destruido\n" << std::endl;
    }
    //Setter
    void setTemperatura(int _temperatura)
    {
        temperatura = _temperatura;
    }
    //Getter
    int getTemperatura()
    {
        return temperatura;
    }

    void Calentar()
    {
        temperatura += 100;
    }
};

class PokemonElectrico : public Pokemon
{
protected:
    int voltaje;
    int corriente;
    int potencia;
public:
    //Constructor Generico
    PokemonElectrico() : Pokemon()
    {
        voltaje = 10;
        corriente = 50;
        potencia = 25;
        
    }
    //Constructor Especifico 
    PokemonElectrico(std::string _nombre, std::string  _tipo, std::string _color, int _ataque, int _salud, int _voltaje, int _corriente, int _potencia)
    {
        Nombre = _nombre;
        Tipo = _tipo;
        Color = _color;
        Ataque = _ataque;
        Salud = _salud;
        voltaje = _voltaje;
        corriente = _corriente;
        potencia = _potencia;
    }
    //Destructor
    ~PokemonElectrico()
    {
        std::cout << "Pokemon Electrico " << Nombre << " ha sido destruido\n" << std::endl;
    }
    //Setter
    void setVoltaje(int _voltaje)
    {
        voltaje = _voltaje;
    }
    void setCorriente(int _corriente)
    {
        corriente = _corriente;
    }
    void setPotencia(int _potencia)
    {
        potencia = _potencia;
    }
    //Getter
    int getVoltaje()
    {
        return voltaje;
    }
    int getCorriente()
    {
        return corriente;
    }
    int getPotencia()
    {
        return potencia;
    }

    void prenderFoco()
    {
        voltaje += 15;
        potencia -= 5;
    }
};
int main()
{
    Pokemon Random;
    Random.mostrarAtributos();
    Pokemon Charmander("Charmander","Fuego","Naranja",30,100);
    Charmander.mostrarAtributos();
    Random.setNombre("Hola");
    Charmander.evolucionarPokemon("Charmeleon", "Fuego", "Rojo");
    Charmander.mostrarAtributos();
    PokemonElectrico Pikachu("Pikachu", "Electrico", "Amarillo",  100,150,500,100,100);
    Pikachu.mostrarAtributos();
}

