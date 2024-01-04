/*Створити тип даних - клас вектор Vector3F, який має поля x, y та z типу float і 
змінну стану State . У класі визначити 
o конструктор без параметрів(інінціалізує поля в нуль);
o конструктор з одним параметром типу float (інінціалізує поля x, y та z
значенням параметру);
o конструктор з одним параметром вказівник на тип (інінціалізує поля x, y та z
значенням масиву за вказівником, якщо вказівник NULL (nulptr) то 
встановити код помилки);
o деструктор із виведенням інформації про стан вектора;
o перевантаження операцій (операції перевантажувати через функції класу або 
дружні функції, якщо не вказано яким чином це робити): 
     унарних префіксних та постфіксних ++ та --: одночасно збільшує 
    (зменшує) значення елементів масиву на 1.0; 
     унарної логічної ! (заперечення): повертає значення true, якщо 
    елементи якщо x, y та z не дорівнюють – нулю, інакше false;
     унарної побітової ~ (заперечення): повертає перпендикулярний вектор
    для заданого;
     унарний арифметичний - (мінус) : повертає всі елементи масиву 
    класу вектор з протилежним знаком; 
     присвоєння =: копіює вектор(перевантажити через функцію класу);
     присвоєння з 
        o += - додаванням векторів;
        o -= - відніманням векторів;
        o *= - множенням на число; 
        o /= - ділення на число;
        o &= - векторний добуток;
        o %= - остача від ділення для цілої части дійсного числа на число 
        типу int;
     арифметичних бінарні:
        o + - додавання векторів;
        o - - віднімання векторів;
        o * - множення вектора на число;
        o / - ділення вектора на число;
        o % - остача від ділення для цілої части дійсного числа на число 
        типу int;
     побітові операції зсувів, як дружні операції введення та виведення 
    вектора у потік (перевантажувати через дружні функції):
        o введення >> (побітовий зсув право) ;
        o введення << (побітовий зсув ліво);
     рівності == та нерівності!= , функція-операція виконує певні дії над 
    кожною парою елементів векторів за індексом;
     операцію індексації [] – функцію, яка звертається до елементу 
    масиву за індексом до x, y та z, якщо індекс невірний функція вказує 
    на z та встановлює код помилки у змінну State;
     розподілу пам’яті new та delete;
     виклику функції ();
     порівняння (функція-операція виконує певні дії над кожною парою 
    елементів векторів за індексом), які повертають true або false:
        o > (більше) для двох векторів; 
        o >= (більше рівне) для двох векторів;
        o < (менше) для двох векторів;
        o <=(менше рівне) для двох векторів.
У змінну стани встановлювати код помилки, діленні на 0, при передачі NULL (nulptr) в 
конструкторі із вказівником. Передбачити можливість підрахунку числа об'єктів даного типу. 
Перевірити роботу цього класу.
*/

#include <iostream>
#include <cmath>

using namespace std;

class Vector3F{
private:
    float x, y, z;
    int state;

public:
    static int count;

    Vector3F() : x(0.0), y(0.0), z(0.0), state(0){
        count++;
    }

    Vector3F(float value) : x(value), y(value), z(value), state(0){
        count++;
    }

    Vector3F(float a, float b, float c) : x(a), y(b), z(c), state(0) {
        count++;
}

    Vector3F(float* ptr) : state(0){
        if (ptr == nullptr){
            state = -1;
        } else{
            x = ptr[0];
            y = ptr[1];
            z = ptr[2];
            count++;
        }
    }

    ~Vector3F(){
        cout << "Vector destroyed. State: " << state << endl;
        count--;
    }

    Vector3F operator++(){
        x += 1.0;
        y += 1.0;
        z += 1.0;
        return *this;
    }

    Vector3F operator++(int){
        Vector3F temp = *this;
        ++(*this);
        return temp;
    }

    Vector3F operator--(){
        x -= 1.0;
        y -= 1.0;
        z -= 1.0;
        return *this;
    }

    Vector3F operator--(int){
        Vector3F temp = *this;
        --(*this);
        return temp;
    }

    bool operator!(){
        return (x != 0.0 || y != 0.0 || z != 0.0);
    }

    Vector3F operator~() {
        return Vector3F(-x, -y, -z);
    }

    Vector3F operator-() {
        return Vector3F(-x, -y, -z);
    }

    Vector3F& operator=(const Vector3F& other){
        if (this != &other) {
            x = other.x;
            y = other.y;
            z = other.z;
            state = other.state;
        }
        return *this;
    }

    Vector3F& operator+=(const Vector3F& other){
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }

    Vector3F& operator-=(const Vector3F& other){
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
    }

    Vector3F& operator*=(float num){
        x *= num;
        y *= num;
        z *= num;
        return *this;
    }

    Vector3F& operator/=(float num){
        if (num != 0.0){
            x /= num;
            y /= num;
            z /= num;
        } else{
            state = -1;
        }
        return *this;
    }

    Vector3F& operator%=(float num){
        if (num != 0){
            x = fmod(x, num);
            y = fmod(y, num);
            z = fmod(z, num);
        } else{
            state = -1;
        }
        return *this;
    }

    Vector3F operator+(const Vector3F& other){
    Vector3F tmp; 
    tmp.x = x + other.x;
    tmp.y = y + other.y;
    tmp.z = z + other.z;
    return tmp;
    }

    Vector3F operator-(const Vector3F& other){
    Vector3F tmp; 
    tmp.x = x - other.x;
    tmp.y = y - other.y;
    tmp.z = z - other.z;
    return tmp;
    }

    void Mult(float num) {
        x *= num;
        y *= num;
        z *= num; 
    }

    void Div(float num) {
        if (num != 0) {
            x /= num;
            y /= num;
            z /= num;
        } else state = 1; 
    }

    friend ostream& operator<<(ostream& out, const Vector3F& vec);
    friend istream& operator>>(istream& in, Vector3F& vec);

    bool operator==(const Vector3F& other) const{
        return (x == other.x && y == other.y && z == other.z);
    }

    bool operator!=(const Vector3F& other) const{
        return !(*this == other);
    }

    float& operator[](int index) {
        if (index == 0) {
            return x;
        } else if (index == 1) {
            return y;
        } else if (index == 2) {
            return z;
        } else {
            state = -1;
            return z;
        }
    }

    bool operator>(const Vector3F& other) const{
        return (x > other.x) && (y > other.y) && (z > other.z);
    }

    bool operator>=(const Vector3F& other) const{
        return (x >= other.x) && (y >= other.y) && (z >= other.z);
    }

    bool operator<(const Vector3F& other) const{
        return (x < other.x) && (y < other.y) && (z < other.z);
    }

    bool operator<=(const Vector3F& other) const{
        return (x <= other.x) && (y <= other.y) && (z <= other.z);
    }

};

int Vector3F::count = 0;

ostream& operator<<(ostream& out, const Vector3F& vec) {
    out << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
    return out;
}

istream& operator>>(istream& in, Vector3F& vec) {
    in >> vec.x >> vec.y >> vec.z;
    return in;
}

int main() {
    Vector3F v1(1.0);
    cout << "v1: " << v1 << endl;
    Vector3F v2(new float[3]{2.0, 3.0, 4.0});
    cout << "v2: " << v2 << endl;
    Vector3F v3;
    cin >> v3;
    cout << "v3: " << v3 << endl;

    if (v1 == v2){
        cout << "v1 = v2" << endl;
    }

    if (v1 != v3) {
        cout << "v1 != v3" << endl;
    }

    if (v1 < v3) {
        cout << "v1 < v3." << endl;
    }

    if (v3 >= v2) {
        cout << "v3 >= v2." << endl;
    }
    ++v1;
    cout << "After increment v1: " << v1 << endl;
    Vector3F v4 = v1 + v2;
    cout << "v1 + v2: " << v4 << endl;
    v3.Div(2.0);
    cout << "v3 /= 2: " << v3 << endl;
    v1.Mult(3.0);
    cout << "v1 *= 3: " << v1 << endl;

    return 0;
}
