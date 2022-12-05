#include <iostream>
#include <cmath>

using namespace std;
class division_by_zero:exception{};
class magnitude_less_than_zero:exception{};

template<typename T>
class ComplexNum{
public:
    ComplexNum();
    ComplexNum(T real, T imag);
    ComplexNum(const ComplexNum& other);
    ~ComplexNum();

    void print_Cartesian();
    void print_Polar();

    void set_real_imag(const T& new_real, const T& new_imag);
    void set_real(const T& new_real);
    void set_imag(const T& new_imag);
    void set_magnitude_arg_d(const T& new_magnitude, const T& new_arg_degree);
    void set_magnitude_arg_r(const T& new_magnitude, const T& new_arg_radian);
    void set_magnitude(const T& new_magnitude);
    void set_arg_d(const T& new_arg_degree);
    void set_arg_r(const T& new_arg_radian);

    T get_real();
    T get_imag();
    double get_magnitude() const;
    double get_arg_d() const;
    double get_arg_r() const;
    ComplexNum conjugate() const;
    ComplexNum rotate_clockwise_d(double degree) const;
    ComplexNum rotate_counterclockwise_d(double degree) const;
    ComplexNum rotate_clockwise_r(double radian) const;
    ComplexNum rotate_counterclockwise_r(double radian) const;
    ComplexNum add_magnitude(double length) const;

    ComplexNum& operator=(const ComplexNum& other);
    ComplexNum operator+(const ComplexNum& other) const;
    ComplexNum operator+(const ComplexNum&& other) const;
    ComplexNum operator-(const ComplexNum& other) const;
    ComplexNum operator-(const ComplexNum&& other) const;
    ComplexNum operator*(const ComplexNum& other) const;
    ComplexNum operator*(const ComplexNum&& other) const;
    ComplexNum operator/(const ComplexNum& other) const;
    ComplexNum operator/(const ComplexNum&& other) const;
    bool operator==(ComplexNum& other) const;
    bool operator==(ComplexNum&& other) const;
    bool operator!=(ComplexNum& other) const;
    bool operator!=(ComplexNum&& other) const;

private:
    T _real;
    T _imag;
};


template<typename T>
ComplexNum<T>::ComplexNum():_real(0.0), _imag(0.0) { }

template<typename T>
ComplexNum<T>::ComplexNum(T real, T imag):_real(real), _imag(imag) { }

template<typename T>
ComplexNum<T>::ComplexNum(const ComplexNum &other): _real(other._real), _imag(other._imag){ }

template<typename T>
ComplexNum<T>::~ComplexNum() = default;

template<typename T>
void ComplexNum<T>::print_Cartesian() {
    cout << _real;
    if (_imag >= 0) {
        cout << "+";
    }
    if (_imag == 1){}
    else if (_imag == -1){cout << "-";}
    else
        cout << _imag;
    cout << "i ";
}

template<typename T>
void ComplexNum<T>::print_Polar() {
    cout << get_magnitude() << "exp(" << get_arg_r() << "i) ";
}

template<typename T>
void ComplexNum<T>::set_real_imag(const T& new_real, const T& new_imag) {
    _real = new_real;
    _imag = new_imag;
}

template<typename T>
void ComplexNum<T>::set_real(const T& new_real) {
    _real = new_real;
}
template<typename T>
void ComplexNum<T>::set_imag(const T& new_imag) {
    _imag = new_imag;
}

template<typename T>
void ComplexNum<T>::set_magnitude_arg_d(const T &new_magnitude, const T &new_arg_degree) {
    if (new_magnitude < 0) throw magnitude_less_than_zero();
    _real = new_magnitude * cos(new_arg_degree * M_PI /180);
    _imag = new_magnitude * sin(new_arg_degree * M_PI /180);
}

template<typename T>
void ComplexNum<T>::set_magnitude_arg_r(const T &new_magnitude, const T &new_arg_radian) {
    if (new_magnitude < 0) throw magnitude_less_than_zero();
    _real = new_magnitude * cos(new_arg_radian);
    _imag = new_magnitude * sin(new_arg_radian);
}

template<typename T>
void ComplexNum<T>::set_magnitude(const T &new_magnitude) {
    if (new_magnitude < 0) throw magnitude_less_than_zero();
    double _arg = get_arg_r();
    _real = new_magnitude * cos(_arg);
    _imag = new_magnitude * sin(_arg);
}

template<typename T>
void ComplexNum<T>::set_arg_d(const T &new_arg_degree) {
    double mag = get_magnitude();
    _real = mag * cos(new_arg_degree * M_PI /180);
    _imag = mag * sin(new_arg_degree * M_PI /180);
}

template<typename T>
void ComplexNum<T>::set_arg_r(const T &new_arg_radian) {
    double mag = get_magnitude();
    _real = mag * cos(new_arg_radian);
    _imag = mag * sin(new_arg_radian);

}

template<typename T>
T ComplexNum<T>::get_real() {return _real;}

template<typename T>
T ComplexNum<T>::get_imag() {return _imag;}

template<typename T>
double ComplexNum<T>::get_magnitude() const{
    return sqrt(_real * _real +_imag * _imag);
}

template<typename T>
double ComplexNum<T>::get_arg_d() const{
    return (atan2(_imag, _real) * 180 /M_PI);
}

template<typename T>
double ComplexNum<T>::get_arg_r() const{
    return atan2(_imag, _real);
}

template<typename T>
ComplexNum<T> ComplexNum<T>::conjugate() const {
    ComplexNum<T> temp;
    temp._real = _real;
    temp._imag = -_imag;
    return temp;
}

template<typename T>
ComplexNum<T> ComplexNum<T>::rotate_clockwise_d(double degree) const {
    ComplexNum<T> temp;
    double newarg_r;
    newarg_r = get_arg_r() + degree * M_PI / 180;
    temp._real = get_magnitude() * cos(newarg_r);
    temp._imag = get_magnitude() * sin(newarg_r);
    return temp;
}

template<typename T>
ComplexNum<T> ComplexNum<T>::rotate_counterclockwise_d(double degree) const {
    ComplexNum<T> temp;
    double newarg_r;
    newarg_r = get_arg_r() - degree * M_PI / 180;
    temp._real = get_magnitude() * cos(newarg_r);
    temp._imag = get_magnitude() * sin(newarg_r);
    return temp;
}

template<typename T>
ComplexNum<T> ComplexNum<T>::rotate_clockwise_r(double radian) const {
    ComplexNum<T> temp;
    double newarg_r;
    newarg_r = get_arg_r() + radian;
    temp._real = get_magnitude() * cos(newarg_r);
    temp._imag = get_magnitude() * sin(newarg_r);
    return temp;
}

template<typename T>
ComplexNum<T> ComplexNum<T>::rotate_counterclockwise_r(double radian) const {
    ComplexNum<T> temp;
    double newarg_r;
    newarg_r = get_arg_r() - radian;
    temp._real = get_magnitude() * cos(newarg_r);
    temp._imag = get_magnitude() * sin(newarg_r);
    return temp;
}

template<typename T>
ComplexNum<T> ComplexNum<T>::add_magnitude(double length) const {
    ComplexNum<T> temp;
    double newmagnitude;
    newmagnitude = get_magnitude() + length;
    if (newmagnitude < 0) throw magnitude_less_than_zero();
    temp._real = newmagnitude * cos(get_arg_r());
    temp._imag = newmagnitude * sin(get_arg_r());
    return temp;
}

template<typename T>
ComplexNum<T>& ComplexNum<T>::operator=(const ComplexNum &other) {
    if (this != &other){
        _real = other._real;
        _imag = other._imag;
    }
    return *this;
}

template<typename T>
ComplexNum<T> ComplexNum<T>::operator+(const ComplexNum &other) const {
    ComplexNum<T> temp;
    temp._real = _real + other._real;
    temp._imag = _imag + other._imag;
    return temp;
}
template<typename T>
ComplexNum<T> ComplexNum<T>::operator+(const ComplexNum &&other) const {
    ComplexNum<T> temp;
    temp._real = _real + other._real;
    temp._imag = _imag + other._imag;
    return temp;
}

template<typename T>
ComplexNum<T> ComplexNum<T>::operator-(const ComplexNum &other) const {
    ComplexNum<T> temp;
    temp._real = _real - other._real;
    temp._imag = _imag - other._imag;
    return temp;
}
template<typename T>
ComplexNum<T> ComplexNum<T>::operator-(const ComplexNum &&other) const {
    ComplexNum<T> temp;
    temp._real = _real - other._real;
    temp._imag = _imag - other._imag;
    return temp;
}

template<typename T>
ComplexNum<T> ComplexNum<T>::operator*(const ComplexNum &other) const {
    ComplexNum<T> temp;
    temp._real = _real * other._real - _imag * other._imag;
    temp._imag = _real * other._imag + _imag * other._real;
    return temp;
}
template<typename T>
ComplexNum<T> ComplexNum<T>::operator*(const ComplexNum &&other) const {
    ComplexNum<T> temp;
    temp._real = _real * other._real - _imag * other._imag;
    temp._imag = _real * other._imag + _imag * other._real;
    return temp;
}

template<typename T>
ComplexNum<T> ComplexNum<T>::operator/(const ComplexNum &other) const {
    double deno;
    deno = other._real * other._real + other._imag * other._imag;
    if (deno == 0)
        throw division_by_zero();
    ComplexNum<T> temp;
    temp._real = (_real * other._real + _imag * other._imag) / deno;
    temp._imag = (_imag * other._real - _real * other._imag) / deno;
    return temp;
}
template<typename T>
ComplexNum<T> ComplexNum<T>::operator/(const ComplexNum &&other) const {
    double deno;
    deno = other._real * other._real + other._imag * other._imag;
    if (deno == 0)
        throw division_by_zero();
    ComplexNum<T> temp;
    temp._real = (_real * other._real + _imag * other._imag) / deno;
    temp._imag = (_imag * other._real - _real * other._imag) / deno;
    return temp;
}

template<typename T>
bool ComplexNum<T>::operator==(ComplexNum& other) const{
    return (_real == other._real && _imag == other._imag);
}
template<typename T>
bool ComplexNum<T>::operator==(ComplexNum&& other) const{
    return (_real == other._real && _imag == other._imag);
}

template<typename T>
bool ComplexNum<T>::operator!=(ComplexNum& other) const{
    return (_real != other._real || _imag != other._imag);
}
template<typename T>
bool ComplexNum<T>::operator!=(ComplexNum&& other) const{
    return (_real != other._real || _imag != other._imag);
}

int main() {
    ComplexNum<double> a, b(1,2), c(b);
    cout << "Cartesian Form:" << endl;
    cout << "a = "; a.print_Cartesian(); cout << ", b = "; b.print_Cartesian(); cout << ", c(b) = "; c.print_Cartesian(); cout << endl;
    cout << "Polar Form:" << endl;
    cout << "a = "; a.print_Polar(); cout << ", b = "; b.print_Polar(); cout << ", c(b) = "; c.print_Polar(); cout << endl;
    cout << endl;
    a.set_real_imag(-1,1);
    cout << "Set a by set_real_imag(-1, 1). a = "; a.print_Cartesian(); cout << endl;
    a.set_real(3);
    cout << "Set a by set_real(3). a = "; a.print_Cartesian(); cout << endl;
    a.set_imag(-4);
    cout << "Set a by set_real_imag(-4). a = "; a.print_Cartesian(); cout << endl;
    a.set_magnitude_arg_d(4,45);
    cout << "Set a by set_magnitude_arg_d(4, 45). a = "; a.print_Polar(); cout << endl;
    a.set_magnitude_arg_r(9,2);
    cout << "Set a by set_magnitude_arg_r(9, 2). a = "; a.print_Polar(); cout << endl;
    a.set_arg_d(45);
    cout << "Set a by set_arg_d(45). a = "; a.print_Polar(); cout << endl;
    a.set_arg_r(3);
    cout << "Set a by set_arg_r(3). a = "; a.print_Polar(); cout << endl;
    a.set_magnitude(4);
    cout << "Set a by set_magnitude(4). a = "; a.print_Polar(); cout << endl;
    cout << endl;
    cout << "a = "; a.print_Cartesian(); cout << "= "; a.print_Polar(); cout << endl;
    cout << "a: real part= " << a.get_real() << ", imaginary part= " << a.get_imag() << ", magnitude= " << a.get_magnitude() << ", angle(in degree)= " << a.get_arg_d() << ", angle(in radian)= " << a.get_arg_r() << endl;
    cout << "Conjugate of a = "; a.conjugate().print_Cartesian(); cout << "= "; a.conjugate().print_Polar(); cout << endl;
    cout << endl;
    cout << "b = "; b.print_Polar(); cout << endl;
    cout << "Rotate clockwise of 30 degree of b = "; b.rotate_clockwise_d(30).print_Polar(); cout << endl;
    cout << "Rotate counterclockwise of 330 degree of b) = "; b.rotate_counterclockwise_d(330).print_Polar(); cout << endl;
    cout << "Rotate clockwise of 2 radian of b = "; b.rotate_clockwise_r(2).print_Polar(); cout << endl;
    cout << "Rotate counterclockwise of 2 radian of b = "; b.rotate_counterclockwise_r(2).print_Polar(); cout << endl;
    cout << "Add 2 unit to magnitude of b = "; b.add_magnitude(2).print_Polar(); cout << endl;
    cout << endl;
    ComplexNum<double> x(1,2), y(3,4), z(1,2);
    cout << "x = "; x.print_Cartesian(); cout << ", y = "; y.print_Cartesian(); cout << ", z = "; z.print_Cartesian(); cout << endl;
    cout << "x+y = "; (x+y).print_Cartesian(); cout << endl;
    cout << "x-y = "; (x-y).print_Cartesian(); cout << endl;
    cout << "x*y = "; (x*y).print_Cartesian(); cout << endl;
    cout << "x/y = "; (x/y).print_Cartesian(); cout << endl;
    cout << "x == y : " << (x == y) << endl;
    cout << "x != y : " << (x != y) << endl;
    cout << "x == z : " << (x == z) << endl;
    cout << "x != z : " << (x != z) << endl;
    return 0;
}
