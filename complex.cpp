#include <bits/stdc++.h>
using namespace std;

/***********************************************************************************************
*
* Author: Sumir Vats
* Date: 24 Nov, 2021 (Wed)
*
* This program implements complex numbers using OOP
* You can add, subtract, multiply, divide, see conjugate, see modulus of the complex number
* and many more
* Other than that I have added the following functions:
* 1. to show argument of the complex number
* 2. to find distance between two complex numbers in argand plane
* and we can add more functions to make this program more and more functional
*
* Overall, it was a very fun project and I got to learn a lot from it.
*
************************************************************************************************/


// MAIN CLASS
class Complex
{

private:

    float real;
    float img;

public:

    Complex(float r, float i)
    {
        this->real = r;
        this->img = i;
    }

    void showNumber()
    {
        cout << "The number is " << this->real << " + " << this->img << "i\n";
    }

    float realPart()
    {
        return this->real;
    }

    float imaginary()
    {
        return this->img;
    }

    void printConjugate()
    {
        if (this->img >= 0) {
            cout << "The conjugate of " << this->real << "+" << this->img << "i is ";
            cout << this->real << "-" << this->img << "i\n";
        }
        else{
            cout << "The conjugate of " << this->real << this->img << "i is ";
            cout << this->real << "+" << -(this->img) << "i\n";
        }
    }

    /*Complex conjugate()
    {
        Complex conjNum(this->real, -(this->img));
        return conjNum;
    }*/

    void add(Complex b)
    {
        float addReal = this->real + b.real;
        float addImg = this->img + b.img;
        if (addImg >= 0) {
            cout << "The sum is " << addReal << "+" << addImg <<"i\n";
        }
        else {
            cout << "The sum is " << addReal << addImg <<"i\n";
        }
    }

    void subtract(Complex b)
    {
        float subReal = this->real - b.real;
        float subImg= this->img - b.img;
        if (subImg >= 0) {
            cout << "The difference is " << subReal << "+" << subImg<<"i\n";
        }
        else {
            cout << "The difference is " << subReal << subImg << "i\n";
        }
    }

    void multiply(Complex b)
    {
        float mulReal = (this->real * b.real) - (this->img * b.img);
        float mulImg= (this->real * b.img) + (this->img * b.real);
        if (mulImg >= 0) {
            cout << "The product is " << mulReal << "+" << mulImg<<"i\n";
        }
        else {
            cout << "The product is " << mulReal << mulImg << "i\n";
        }
    }

    /*Complex mult(Complex b)
    {
        float mulReal = (this->real * b.real) - (this->img * b.img);
        float mulImg= (this->real * b.img) + (this->img * b.real);
        Complex c(mulReal, mulImg);
        return c;
    }*/

    void divide(Complex b)
    {
        float divisor = b.real*b.real + b.img*b.img;
        float mulReal = ((this->real * b.real) + (this->img * b.img))/divisor;
        float mulImg= (-(this->real * b.img) + (this->img * b.real))/divisor;
        if (mulImg >= 0) {
            cout << "The division gives " << mulReal << "+" << mulImg << "i\n";
        }
        else {
            cout << "The division gives " << mulReal << mulImg << "i\n";
        }
    }

    float mod()
    {
        return pow((this->real*this->real + this->img*this->img),0.5);
    }

    float dist(Complex b)
    {
        float sqDist = pow(((this->real)-(b.real)), 2)+pow(((this->img)-(b.img)), 2);
        return pow(sqDist, 0.5);
    }

    float argument()
    {
        return atan((this->img)/(this->real));
    }
};


// MAIN FUNCTION
int main()
{
    system("Color 1E");
    cout << "This is a complex number calculator\n";
    cout << "It can do the following functions for you:\n";
    cout << "1.Show Number\n";
    cout << "2.Show Real Part\n";
    cout << "3.Show Imaginary Part\n";
    cout << "4.Show Conjugate of the number\n";
    cout << "5.Add two complex numbers\n";
    cout << "6.Subtract two complex numbers\n";
    cout << "7.Multiply two complex numbers\n";
    cout << "8.Divide two complex numbers\n";
    cout << "9.Show modulus of the number\n";
    cout << "10.Show argument of the number\n";
    cout << "11.Find distance between two numbers\n";
    cout << "\n";
    cout << "Type index number to activate function\n";
    // cout << "Type any number other than these to quit\n\n";

    while(true) {
        int input;
        cout << "Enter function index: ";
        cin >> input;
        if (input==5 || input==6 || input==7 || input==8 || input == 11) {
            cout << "Enter real part of number 1: ";
            int re1;
            cin >> re1;
            cout << "Enter imaginary part of number 1: ";
            int im1;
            cin >> im1;
            cout << "Enter real part of number 2: ";
            int re2;
            cin >> re2;
            cout << "Enter imaginary part of number 2: ";
            int im2;
            cin >> im2;

            Complex complex1(re1, im1);
            Complex complex2(re2, im2);

            if (input == 5) {
                complex1.add(complex2);
            }
            else if (input == 6) {
                complex1.subtract(complex2);
            }
            else if (input == 7) {
                complex1.multiply(complex2);
            }
            else if (input == 8){
                complex1.divide(complex2);
            }
            else {
                // distance between two numbers
                cout << "The distance between the numbers is: " << complex1.dist(complex2);
                cout << "\n";
            }
        }
        else if (input == 1 || input == 2 || input == 3 || input == 4 || input == 9 || input == 10) {
            cout << "Enter real part of the number: ";
            int re1;
            cin >> re1;
            cout << "Enter imaginary part of the number: ";
            int im1;
            cin >> im1;

            Complex complex1(re1, im1);

            if (input == 1) {
                complex1.showNumber();
            }
            else if (input == 2) {
                cout << "The real part of the number is: " << complex1.realPart() << "\n";
            }
            else if (input == 3) {
                cout << "The imaginary part of the number is: " << complex1.imaginary() << "\n";
            }
            else if (input == 4) {
                complex1.printConjugate();
            }
            else if (input == 9){
                cout << "The modulus of the number is: " << complex1.mod() << "\n";
            }
            else {
                cout << "The argument of the number is: " << complex1.argument() << "radians\n";
                cout << "The argument of the number is: " << (complex1.argument())*(180/3.1459) << "degrees\n";
            }
        }
        else {
            break;
        }
        cout << "Do you want to implement more functions?(yes-1/no-2): ";
        int cont;
        cin >> cont;
        if (cont == 2) {
            break;
        }
    }

	return 0;
}

// end :)

