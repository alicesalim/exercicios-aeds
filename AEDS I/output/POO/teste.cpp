#include <iostream>

using namespace std;

class Quadrado {

private:
    int lado;

public:
    Quadrado(int l): lado(l) {}//construtor;

    int getLado() {
        return lado;
    }

    int perimetro() {
        return 4*lado;
    }

    int area() {
    return lado * lado;
    }

    void print() {
        cout << "[Quadrado, lado=" << this->lado << "]" << endl;
    }
};

int main()
{

    Quadrado q(10);

    cout << "lado do quadrado = " << q.getLado() << endl;

    cout << "perimetro do quadrado = " << q.perimetro() << endl;

    cout << "area do quadrado = " << q.area() << endl;

    q.print();

    return 0;
}
