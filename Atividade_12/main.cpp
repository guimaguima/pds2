#include <iostream>
#include <vector>
#include <stdexcept>

class NegativeResultException : std::exception
{
private:
    int _valor;

public:
    NegativeResultException(int valor) : _valor(valor) {}

    const char *what() const throw()
    {
        return "Erro: Resultado Negativo.";
    }

    int getValor() const
    {
        return this->_valor;
    }
};

int main()
{
    try
    {
        std::vector<int> valores = {-20, -10, 0, 10, 20};

        int input;
        std::cin >> input;

        if ((input >= 5) || (input < 0))
            throw std::out_of_range("Erro: Parametro invalido");

        else
        {
            int valor = valores.at(input);

            if (valor < 0)
                throw NegativeResultException(valor);

            if (valor == 0)
                throw std::logic_error("Erro: O resultado nao deve ser zero.");
            std::cout << valor << std::endl;
        }
    }
    catch (const NegativeResultException &e)
    {
        std::cerr << e.what() << std::endl;
        std::cout << e.getValor() << std::endl;
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (const std::logic_error &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
