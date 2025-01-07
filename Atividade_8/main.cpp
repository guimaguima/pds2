#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <vector>
#include <iomanip> 


class Ponto {
    private:
        int x;
        int y;
    
    public:
        Ponto(int x, int y) : x(x), y(y){}

        int getX(){
            return this->x;
        }

        int getY(){
            return this->y;
        }

        void setX(int x){
            this->x = x;
        }

        void setY(int y){
            this->y = y;
        }
};


class FiguraGeometrica{
    protected:
        Ponto* centro;
    public:
        FiguraGeometrica(int x, int y) : centro(new Ponto(x,y)){}
        
        virtual ~FiguraGeometrica(){
            delete centro;
        }

        virtual void Desenha(){
            std::cout << this->centro->getX() << " " << this->centro->getY() << std::endl;
        };

        virtual float CalculaArea() = 0;
};


class Retangulo : public FiguraGeometrica{
    private:
        float lado1;
        float lado2;
    
    public:
        Retangulo(int x, int y, float lado1, float lado2) 
        : FiguraGeometrica(x,y), lado1(lado1), lado2(lado2) {}

        void Desenha() override final{
            std::cout << FiguraGeometrica::centro->getX() << " " 
            << FiguraGeometrica::centro->getY() 
            << " " << "RETANGULO" << std::endl; 
        }

        float CalculaArea() override final{
            return this->lado2*this->lado1;
        }

};

class Triangulo : public FiguraGeometrica{
    private:
        float base;
        float altura;
    
    public:
        Triangulo(int x, int y, float base, float altura) 
        : FiguraGeometrica(x,y), base(base), altura(altura) {}

        void Desenha() override final{
            std::cout << FiguraGeometrica::centro->getX() << " " 
            << FiguraGeometrica::centro->getY() 
            << " " << "TRIANGULO" << std::endl; 
        }

        float CalculaArea() override final{
            return (this->base*this->altura)/2;
        }

};



class Circulo : public FiguraGeometrica{
    private:
        float raio;
    
    public:
        Circulo(int x, int y, int raio) 
        : FiguraGeometrica(x,y), raio(raio){}


        void Desenha() override final{
            std::cout << FiguraGeometrica::centro->getX() << " " 
            << FiguraGeometrica::centro->getY() 
            << " " << "CIRCULO" << std::endl; 
        }

        float CalculaArea() override final{
            return this->raio * this->raio * M_PI;
        }

};



int main() {
    std::vector<FiguraGeometrica*> figuras;


    char letra;

    std::cin >> letra; 

    while (letra!='E'){
        switch (letra){
            case 'R': {
                int x, y;
                float lado1, lado2;

                std::cin >> x >> y >> lado1 >> lado2;

                figuras.push_back(new Retangulo(x,y,lado1,lado2));

                break;
            }

            case 'C': {
                int x, y;
                float raio;

                std::cin >> x >> y >> raio;
                
                figuras.push_back(new Circulo(x,y,raio));

                break;
            }

            case 'T': {
                int x, y;
                float base, altura;

                std::cin >> x >> y >> base >> altura;
                
                figuras.push_back(new Triangulo(x,y,base,altura));

                break;
            }

            case 'D': {

                for (auto & figura : figuras){
                    figura->Desenha();
                }
                
                break;
            }
            

            case 'A': {

                float total=0;

                for (auto & figura : figuras){
                    total+=figura->CalculaArea();
                }


                std::cout << std::fixed << std::setprecision(2) << total << std::endl;

                break;
            }

            default:
                break;
        }

        std::cin >> letra; 
    }
    

    for (auto figura : figuras) {
        delete figura;
    }


    return 0;
}
