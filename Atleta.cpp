
#include <iostream>

class Atleta
{
protected:
    int Energia;
    int Fuerza;
    int Velocidad;
    std::string Nombre;
public:
    //Constructor Generico
    Atleta()
    {
        Energia = 100;
        Fuerza = 50;
        Velocidad = 25;
        Nombre = "Desconocido";
    }
    //Constructor especifico
    Atleta(int _energia, int _fuerza, int _velocidad, std::string _nombre)
    {
        Energia = _energia;
        Fuerza = _fuerza;
        Velocidad = _velocidad;
        Nombre = _nombre;
    }
    //Destructor
    ~Atleta()
    {
        std::cout << "Atleta: " << Nombre << " ha sido destruido\n" << std::endl;
    }
    //Setter
    void setEnergia(int e)
    {
        Energia = e;
    }
    void setFuerza(int f)
    {
        Fuerza = f;
    }
    void setVelocidad(int v)
    {
        Velocidad = v;
    }
    void setNombre(std::string n)
    {
        Nombre = n;
    }
    //Getter
    int getEnergia()
    {
        return Energia;
    }
    int getFuerza()
    {
        return Fuerza;
    }
    int getVelocidad()
    {
        return Velocidad;
    }
    std::string getNombre()
    {
        return Nombre;
    }
    virtual void incrementarVelocidad()
    {
        Velocidad++;
    }
    void mostrarAtributos()
    {
        std::cout << "Energia: " << Energia << std::endl;
        std::cout << "Fuerza: " << Fuerza << std::endl;
        std::cout << "Velocidad: " << Velocidad << std::endl;
        std::cout << "Nombre: " << Nombre << "\n" << std::endl;
    }
};

class Boxeador : public Atleta
{
protected:
    int golpesPorCombo;
    int fuerzaGolpe;
    int peleas;
    int ganadas;
    int perdidas;
    int KO;
public:
    //Constructor Generico
    Boxeador() : Atleta()
    {
        golpesPorCombo = 4;
        fuerzaGolpe = 10;
        peleas = 0;
        ganadas = 0;
        perdidas = 0;
        KO = 0;
    }
    //Constructor Especifico
    Boxeador(int _energia, int _fuerza, int _velocidad, std::string _nombre, int _combo, int _fuerzaGolpe, int _peleas, int _ganadas, int _perdidas, int _ko)
    {
        Energia = _energia;
        Fuerza = _fuerza;
        Velocidad = _velocidad;
        Nombre = _nombre;
        golpesPorCombo = _combo;
        fuerzaGolpe = _fuerzaGolpe;
        peleas = _peleas;
        ganadas = _ganadas;
        perdidas = _perdidas;
        KO = _ko;
    }
    //Destructor
    ~Boxeador()
    {
        std::cout << "Boxeador: " << Nombre << " ha sido destruido" << std::endl;
    }
    //setter
    void setGolpesPorCombo(int _golpes)
    {
        golpesPorCombo = _golpes;
    }
    void setFuerzaGolpe(int _fuerzaGolpe)
    {
        fuerzaGolpe = _fuerzaGolpe;
    }
    void setPeleas(int _peleas)
    {
        peleas = _peleas;
    }
    void setPeleasGanadas(int _ganadas)
    {
        ganadas = _ganadas;
    }
    void setPeleasPerdidas(int _perdidas)
    {
        perdidas = _perdidas;
    }
    void setKO(int _ko)
    {
        KO = _ko;
    }
    //getter
    int getGolpesPorCombo()
    {
        return golpesPorCombo;
    }
    int getFuerzaGolpe()
    {
        return fuerzaGolpe;
    }
    int getPeleas()
    {
        return peleas;
    }
    int getPeleasGanadas()
    {
        return ganadas;
    }
    int getPeleasPerdidas()
    {
        return perdidas;
    }
    int getKnockOut()
    {
        return KO;
    }
    //Metodos
    void Golpear()
    {
        Energia -= 5;
        fuerzaGolpe = 10;
        golpesPorCombo = 1;
    }
    void Golpear(int cantidadGolpes)
    {
        Energia -= 5 * cantidadGolpes;
        fuerzaGolpe = 10 * cantidadGolpes;
        golpesPorCombo = 1 * cantidadGolpes;
    }
    void Golpear(int cantidadGolpes, int Fuerza)
    {
        Energia -= 5 * cantidadGolpes;
        fuerzaGolpe = fuerzaGolpe * cantidadGolpes;
        golpesPorCombo = cantidadGolpes;
    }
    void Golpear(int cantidadGolpes, int Fuerza, int _Energia)
    {
        Energia -= _Energia * cantidadGolpes;
        fuerzaGolpe = fuerzaGolpe * cantidadGolpes;
        golpesPorCombo = cantidadGolpes;
    }
    void Pelea(bool _ganar, bool _knockout)
    {
        peleas++;
        if ((_ganar = 1) && (_knockout = 1))
        {
            ganadas++;
            KO++;

        }
        else if (_ganar = 1)
        {
            ganadas++;
        }
        else
        {
            perdidas--;
        }
    }
    void mostrarEstadisticas()
    {
        std::cout << "Golpes por combo: " << golpesPorCombo << std::endl;
        std::cout << "Fuerza golpe: " << fuerzaGolpe << std::endl;
        std::cout << "Numero de peleas: " << peleas << std::endl;
        std::cout << "Peleas perdidas: " << perdidas << std::endl;
        std::cout << "Peleas ganadas: " << ganadas << std::endl;
        std::cout << "Por KnockOut: " << KO << "\n" << std::endl;
    }
    void incrementarVelocidad() override
    {
        Velocidad+=5;
    }
};
class Ciclista : public Atleta
{


    void Transicion()
    {

    }
};
class Corredor : public Atleta
{
    void Correr()
    {

    }
};
void carrera(Atleta* atleta1, Atleta* atleta2)
{
    atleta1->incrementarVelocidad();
    atleta2->incrementarVelocidad();
    
    if (atleta1->getVelocidad() > atleta2->getVelocidad())
    {
        std::cout << atleta1->getNombre() << " gano la carrera\n\n" << std::endl;
    }
    else
    {
        std::cout << atleta2->getNombre() << " gano la carrera\n\n" << std::endl;
    }
    
}

int main()
{
    Atleta Messi(100, 50, 200, "Messi");
    Messi.mostrarAtributos();
    Boxeador Canelo(100, 100, 100, "Canelo", 30, 1000, 30, 30, 0, 30);
    Canelo.mostrarAtributos();
    carrera(&Canelo, &Messi);

}
