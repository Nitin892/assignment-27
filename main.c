1. Define a class Complex with appropriate instance variables and member functions.
Define following operators in the class:
       a. +
       b. -
       c. *
       d. ==

#include <iostream>

using namespace std;

class Complex {
private:
   int real;
   int img;
public:
   Complex(int r, int i) {
       real = r, img = i;
   }

   Complex() {}

   Complex(Complex &p) {
       real = p.real;
       img = p.img;
   }

   Complex operator+(Complex c) {
       Complex t;
       t.real = real + c.real;
       t.img = img + c.img;
       return t;
   }

   Complex operator-(Complex c) {
       Complex t;
       t.real = real - c.real;
       t.img = img - c.img;
       return t;
   }


   Complex operator*(Complex c) {
       Complex t;
       t.real = real * c.real;
       t.img = img * c.img;
       return t;
   }

   bool operator==(Complex c) {
       if (real == c.real && img == c.img)
           return true;
       return false;
   }

   friend ostream &operator<<(ostream &output, Complex c);
};


ostream &operator<<(ostream &output, Complex c) {
   cout << c.real << " " << c.img;
   return output;
}

int main() {
   int a=9;
   int b=5;
   Complex c1(a, b);
   Complex c2(9, 5);
   Complex c4(90, 80);
   Complex c3;
   cout << c1 << 6;
   return 0;
}

2. Write a C++ program to overload unary operators that is increment and decrement.

#include <iostream>

using namespace std;

class Number {
private:
   int x;
public:
   Number(int a) { x = a; }

   Number() {}

   Number(Number &n) {
       x = n.x;
   }

   Number operator++() {
       Number t;
       t.x = ++x;
       return t;
   }

   Number operator++(int post_increment) {
       Number t;
       t.x = x++;
       return t;
   }

   friend ostream &operator<<(ostream &, Number);
};

ostream &operator<<(ostream &output, Number n1) {
   cout << n1.x;
   return output;
}

int main() {
   Number n = 8;
   Number m = n++;
   cout << m;
   return 0;
}

3. Write a C++ program to add two complex numbers using operator overloaded by a
friend function.

#include <iostream>

using namespace std;

class Complex {
private:
   int real;
   int img;
public:
   Complex() {}

   Complex(int r, int i) { real = r, img = i; }

   Complex(Complex &c) { real = c.real, img = c.img; }

   friend ostream &operator<<(ostream &, Complex);

   friend Complex operator+(Complex, Complex);

};

Complex operator+(Complex c1, Complex c2) {
   Complex t;
   t.real = c1.real + c2.real;
   t.img = c1.img + c2.img;
   return t;
}

ostream &operator<<(ostream &output, Complex c) {
   cout << c.real << " " << c.img;
   return output;
}

int main() {
   Complex c1(1, 2);
   Complex c2(-4 / 5, 3);
   Complex c3;
   c3 = c1 + c2;
   cout << c3;
   return 0;
}

4. Create a class Time which contains:
- Hours
- Minutes
- Seconds
 Write a C++ program using operator overloading for the following:
1. = = : To check whether two Times are the same or not.
2. >> : To accept the time.
3. << : To display the time.

#include <iostream>

using namespace std;

class Time {
private:
   int hour;
   int minute;
   int second;
public:
   Time() {}

   Time(int h, int m, int s) { hour = h, minute = m, second = s; }

   Time(Time &t) { hour = t.hour, minute = t.minute, second = t.second; }

   bool operator==(Time t) {
       if (hour == t.hour && minute == t.minute && second == t.second)
           return true;
       return false;
   }

   friend ostream &operator<<(ostream &, Time);

   friend istream &operator>>(istream &, Time &);
};

istream &operator>>(istream &input, Time &t) {
   cout << "Enter hour:" << endl;
   cin >> t.hour;
   cout << "Enter minute:" << endl;
   cin >> t.minute;
   cout << "Enter second" << endl;
   cin >> t.second;
   return input;

}

ostream &operator<<(ostream &output, Time t) {
   cout << t.hour << " " << t.minute << " " << t.second;
   return output;
}

int main() {
   Time t1(2, 34, 10);
   Time t2(2, 34, 1);
   Time t3;
   cin >> t3;
   cout << t3;
   return 0;
}


5. Consider following class Numbers
class Numbers
{
   int x,y,z;
public:
// methods
};
Overload the operator unary minus (-) to negate the numbers.

#include <iostream>

using namespace std;

class Number {
private:
   int x;
public:
   Number() {}

   Number(int a) { x = a; }

   Number(Number &n) { x = n.x; }

   Number operator-() {
       Number t;
       t.x = -x;
       return t;
   }

   friend ostream &operator<<(ostream &, Number);
};

ostream &operator<<(ostream &output, Number n) {
   cout << n.x;
   return output;

}

int main() {
   Number n1 = -4;
   Number n2 = -n1;
   cout << n2;
   return 0;
}

6. Create a class CString to represent a string.
a) Overload the + operator to concatenate two strings.
b) == to compare 2 strings.

#include<iostream>
#include <cstring>

using namespace std;

class CString {
private:
   char s1[25];

public:
   CString(char c1[25]) {
       strcpy(s1, c1);
   }

   CString() {}

   CString operator+(CString c) {
       CString t;
       strcpy(t.s1, strcat(s1, c.s1));
       return t;
   }

   friend ostream &operator<<(ostream &, CString);
};

ostream &operator<<(ostream &output, CString c) {
   cout << c.s1;
   return output;
}

int main() {
   char x[25] = "hi ";
   char y[25] = "nitin";
   char z[25] = "how are you";
   CString a = x;
   CString b = y;
   CString c = z;
   CString d = a + b + c;
   cout << d;
   return 0;
}

7. Define a C++ class fraction
class fraction
{
   long numerator;
   long denominator;
   Public:
   fraction (long n=0, long d=0);
}
  Overload the following operators as member or friend:
a) Unary ++ (pre and post both)
b) Overload as friend functions: operators << and >>.

#include <iostream>

using namespace std;

class Fraction {
private:
   long numerator;
   long denominator;
public:
   Fraction(long n, long d) { numerator = n, denominator = d; };

   Fraction() {}

   Fraction(Fraction &f) { numerator = f.numerator, denominator = f.denominator; }

   Fraction operator++() {
       Fraction t;
       t.numerator = ++numerator;
       t.denominator = ++denominator;
       return t;
   }

   Fraction operator++(int) {
       Fraction t;
       t.numerator = numerator++;
       t.denominator = denominator++;
       return t;
   }

   friend ostream &operator<<(ostream &, Fraction);

   friend istream &operator>>(istream &, Fraction &);
};

ostream &operator<<(ostream &output, Fraction f) {
   cout << f.numerator << " " << f.denominator;
   return output;
}

istream &operator>>(istream &input, Fraction &f) {
   cout << "Enter numerator:";
   cout << endl;
   cin >> f.numerator;
   cout << "Enter denominator:";
   cin >> f.denominator;
   cout << endl;
   return input;
}

int main() {
   Fraction f1(3, 7), f2;
   f2 = f1++;
   cin >> f2;
   cout << f2;
   return 0;
}


8. Consider a class Matrix
       Class Matrix
{
int a[3][3];
Public:
//methods;
};
Overload the - (Unary) should negate the numbers stored in the object.

#include <iostream>

using namespace std;

class Matrix {
private:
   int z[3][3];
public:
   Matrix operator-() {
       Matrix t;
       for (int i = 0; i < 3; ++i) {
           for (int j = 0; j < 3; ++j) {
               t.z[i][j] = -z[i][j];
           }
       }
       return t;
   }

   void setValues(int row, int column, int value) {
       z[row][column] = value;
   }

   void showdata() {
       for (int i = 0; i < 3; ++i) {
           for (int j = 0; j < 3; ++j) {
               cout << z[i][j] << " ";
           }
           cout << endl;
       }
   }

};


int main() {
   Matrix m1, m2;
   cout << "Enter nine values:" << endl;
   int values = 0;

   for (int i = 0; i < 3; ++i) {
       for (int j = 0; j < 3; ++j) {
           cin >> values;
           m1.setValues(i, j, values);
       }
   }
   m2 = -m1;
   m2.showdata();
   return 0;
}


9.Consider the following class mystring
Class mystring
{
char str [100];
Public:
methods
};
Overload operator “!” to reverse the case of each alphabet in the string
(Uppercase to Lowercase and vice versa).

#include <iostream>
#include <cstring>

using namespace std;

class Mystring {
private:
   char *strarr;
public:


   Mystring() {};

   Mystring(char *str) {
       int size = strlen(str);
       strarr = (char *) malloc(size);
       strcpy(strarr,str);
   }
   void show(){
       cout<<strarr;
   }
   void operator!() {
       int size = strlen(strarr);
       for (int i = 0; i<size; ++i) {
           if (strarr[i] >= 65 && strarr[i] <= 90) {
               strarr[i] = strarr[i] + 32;
           } else if (strarr[i] >= 'a' && strarr[i] <= 'z') {
               strarr[i] = strarr[i] - 32;
           }
       }

   }

   friend ostream &operator<<(ostream &, Mystring);
};

ostream &operator<<(ostream &output, Mystring m) {
   cout << m.strarr;
   return output;
}

int main() {
   char c[14] = "This Is Nitin";
   Mystring m1 = c;
   !m1;
   cout << m1;
   return 0;

}

10.Class Matrix
{
int a[3][3];
Public:
methods;
};
Let m1 and m2 are two matrices. Find out m3=m1+m2 (use operator
overloading).

#include <iostream>

using namespace std;

class Matrix {
private:
   int a[3][3];
public:
   void setValues(int row, int column, int value) {
       a[row][column] = value;
   }

   Matrix operator+(Matrix m) {
       Matrix t;
       for (int i = 0; i < 3; ++i) {
           for (int j = 0; j < 3; ++j) {
               t.a[i][j] = a[i][j] + m.a[i][j];
           }
       }
       return t;
   }

   friend ostream &operator<<(ostream &, Matrix &);

};

ostream &operator<<(ostream &output, Matrix &m) {
   cout << *(m.a);
   return output;
}

int main() {
   Matrix m1, m2, m3;
   int value = 0;
   cout << "Enter nine values:";
   for (int i = 0; i < 3; ++i) {
       for (int j = 0; j < 3; ++j) {
           cin >> value;
           m1.setValues(i, j, value);
       }
   }

   cout << "Enter nine values:";
   for (int i = 0; i < 3; ++i) {
       for (int j = 0; j < 3; ++j) {
           cin >> value;
           m2.setValues(i, j, value);
       }
   }
   m3 = m2 + m1;
   for (int i = 0; i < 3; ++i) {
       for (int j = 0; j < 3; ++j) {
           cout << m3;
       }
       cout<<endl;
   }

   return 0;
}

