/* Alan Varela
   27/02/22 clases
   06/03.23 Herencia
   17/03/23 polimorfismo
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
        std::cout << "Pokemon " << Nombre << " ha sido destruido\n" << std::endl;
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
        Salud += (Salud * .40);
        std::cout <<"\n" << Nombre << " se sano \nHP = " << Salud << std::endl;
    }
    void mostrarAtributos()
    {
        std::cout << "Nombre: " << Nombre << std::endl;
        std::cout << "Tipo: " << Tipo << std::endl;
        std::cout << "Color: " << Color << std::endl;
        std::cout << "Ataque: " << Ataque << std::endl;
        std::cout << "Salud: " << Salud << "\n" << std::endl;
    }
    void evolucionarPokemon(std::string _nombre, std::string  _tipo, std::string _color)
    {
        Nombre = _nombre;
        Tipo = _tipo;
        Color = _color;
        Ataque *= 1.3;
    }
    virtual void atacar(Pokemon* rival)
    {
        std::cout << Nombre << " ataco a " << rival->getNombre() << std::endl;
        rival->setSalud((rival->getSalud() - Ataque));
    }
};
class PokemonAgua : public Pokemon
{
protected:
    int tiempoEnAgua;
    int tiempoEnAire;
public:
    //Constructor Generico
    PokemonAgua() : Pokemon()
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
    void atacar(Pokemon* rival) override
    {
        std::cout << Nombre << " ataco a " << rival->getNombre() << " con lanzamiento de agua" << std::endl;
        rival->setSalud((rival->getSalud() - Ataque));
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
    void atacar(Pokemon* rival) override
    {
        std::cout << Nombre << " ataco a " << rival->getNombre() << " con rocas" << std::endl;
        rival->setSalud((rival->getSalud() - Ataque));
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
    void atacar(Pokemon* rival) override
    {
        std::cout << Nombre << " ataco a " << rival->getNombre() << " con llamas" << std::endl;
        rival->setSalud((rival->getSalud() - Ataque));
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
    void atacar(Pokemon* rival) override
    {
        std::cout << Nombre << " ataco a " << rival->getNombre() << " con rayos" << std::endl;
        rival->setSalud((rival->getSalud() - Ataque));
    }
};

void combatePokemon(Pokemon* pokemon1, Pokemon* pokemon2)
{
    srand(time(0));
    int resp,npc=0;

    while (pokemon1->getSalud() > 1 && pokemon2->getSalud() > 1)
    {
        if (pokemon1->getSalud() > 1)
        {
            std::cout << "Turno de " << pokemon1->getNombre() << std::endl;
            do
            { 
                std::cout << "(1) Atacar\n(2) Sanar" << std::endl;
                std::cin >> resp;
                switch (resp)
                {
                case 1:
                    pokemon1->atacar(pokemon2);
                    break;
                case 2:
                    pokemon1->Sanar();
                    break;
                default:
                    std::cout << "Elige una opcion valida" << std::endl;
                    break;
                }
            } while (resp != 1 && resp != 2);
            std::cout << "\nVida " << pokemon1->getNombre() << "= " << pokemon1->getSalud() << std::endl;
            std::cout << "Vida " << pokemon2->getNombre() << "= " << pokemon2->getSalud() << std::endl;
        }
        if (pokemon2->getSalud() > 1)
        {
            npc =1 + rand() % 2;
            switch (npc)
            {
            case 1:
                pokemon2->atacar(pokemon1);
                break;
            case 2:
                pokemon2->Sanar();
                break;
            }
            std::cout << "\nVida " << pokemon1->getNombre() << "= " << pokemon1->getSalud() << std::endl;
            std::cout << "Vida " << pokemon2->getNombre() << "= " << pokemon2->getSalud() << std::endl << std::endl;
        }
    }
    if (pokemon1->getSalud() > 0)
    {
        std::cout << pokemon1->getNombre() << " ha ganado" << std::endl;
        pokemon1->~Pokemon();
    }
    else
    {
        std::cout << pokemon2->getNombre() << " ha ganado\n\n" << std::endl;
        pokemon2->~Pokemon();
    }

}

int main()
{
    
    Pokemon Charmander("Charmander", "Fuego", "Naranja", 30, 100);
    Charmander.mostrarAtributos();
    Charmander.evolucionarPokemon("Charmeleon", "Fuego", "Rojo");
    Charmander.mostrarAtributos();
    PokemonElectrico Pikachu("Pikachu", "Electrico", "Amarillo", 101, 150, 500, 101, 101);
    combatePokemon(&Charmander, &Pikachu);
}
