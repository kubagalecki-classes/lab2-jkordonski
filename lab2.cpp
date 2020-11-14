#include <iostream>
using namespace std;

class wektor
{

private:
    int     N;
    int     Length   = N;
    int     Capacity = Length;
    double* wp;

public:
    wektor() { wp = new double[0]; }

    wektor(int n, int C) : N{n}, Length{n}, Capacity{C}
    {
        cout << "parametric constructor: wsize = " << N << ", wlength  = " << Length
             << ", capacity = " << Capacity << endl;
        wp = new double[N];
        for (int i = 0; i < N; ++i) {
            *(wp + i) = 0.0;
        };
    }

    // konstruktor kopiujący
    wektor(const wektor& wek) : N{wek.N}, Length{wek.Length}, Capacity{wek.Capacity}
    {
        wp = new double[N];
        for (int i = 0; i < N; ++i) {
            *(wp + i) = wek.wp[i];
        };
    }

    ~wektor()
    {
        cout << "deleted" << endl;
        delete[] wp;
    };

    void printW()
    {
        cout << "wektor [";
        for (int i = 0; i < Length; ++i) {
            cout << wp[i] << ",";
        };
        cout << "]" << endl;
    };

    void setW()
    {
        for (int i = 0; i < Capacity; ++i) {
            *(wp + i) = Capacity - i;
        }
    };

    int getLength() { return Length; }
    int getCapacity() { return Capacity; }

    void ChangeLength(int newLength)
    {
        if (newLength <= Capacity) {
            for (int i = newLength; i < Length; ++i) {
                *(wp + i) = 0.0;
            }

            Length = newLength;
        }
        else {
            N           = newLength;
            double* wpn = (double*)realloc(wp, sizeof(double) * N);
            for (int i = 1; i < Length; ++i) {
                *(wpn + i) = *(wp + i);
            }

            for (int i = Length; i <= newLength; ++i) {
                *(wp + i) = 0;
            }
            Length   = N;
            Capacity = Length;
            wp       = wpn;
        };
    };

    double& operator[](int index);

    double& operator=(const wektor& other)
    {
        delete[] this->wp;
        this->wp       = new double[other.Capacity];
        this->N        = other.N;
        this->Length   = other.Length;
        this->Capacity = other.Capacity;
        for (int i = 0; i < Length; ++i) {
            this->wp[i] = other.wp[i];
        }
    }
};

double& wektor ::operator[](int index)
{
    if (index > Length) {
        ChangeLength(index);
    }
    return wp[index];
}

int main()
{
    wektor a{5, 5};

    a.printW();

    a.setW();

    a.printW();

    a.ChangeLength(3);

    a.printW();

    a.ChangeLength(8);

    a.setW();

    a.printW();

    a[20] = 900;

    a.printW();

    wektor b{5, 5};

    b.setW();

    b.printW();

    wektor copy{b};

    copy.printW();

    copy[2] = 100;
    copy.printW();
    b = copy;
    b.printW();
}
