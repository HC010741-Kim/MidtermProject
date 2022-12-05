Template class for Complex Number

Create a template class ComplexNum, object with variable _real and _imag. //Mean the real part and imaginary part of a complex number.

Constructor:
ComplexNum a; //with no parameter, set _real = 0.0, _imag = 0.0.
ComplexNum a(real, imag) //with two parameters, set _real = real, _imag = imag.

Copy Constructor:
ComplexNum a(ComplexNum b) //set _real = b._real, _imag = b._imag.

Destructor:
Set it as default.

Function:
print_Cartesian() //Print the ComplexNum in cartesian form.
print_Polar() //Print the ComplexNum in polar form.

set_real_imag(new_real, new_imag); //Change real and imaginary part of complex number.
set_real(new_real); //Change real part of complex number.
set_imag(new_imag); //Change imaginary part of complex number.
set_magnitude_arg_d(new_magnitude, new_arg_degree); //Change magnitude and angle(in degree) of complex number. Throw "magnitude_less_than_zero" if magnitude less than zero.
set_magnitude_arg_r(new_magnitude, new_arg_radian); //Change magnitude and angle(in radian) of complex number. Throw "magnitude_less_than_zero" if magnitude less than zero.
set_magnitude(new_magnitude); //Change magnitude of complex number. Throw "magnitude_less_than_zero" if magnitude less than zero.
set_arg_d(new_arg_degree); //Change angle(in degree) of complex number.
set_arg_r(new_arg_radian); //Change angle(in radian) of complex number.

get_real(); //Return the real part.
get_imag(); //Return the imaginary part.
get_magnitude(); //Return the magnitude.
get_arg_d(); //Return the angle(in degree).
get_arg_r(); //Return the angle(in radian).

conjugate(); //Return ComplexNum, which is the conjugate of complex number.

rotate_clockwise_d(degree); //Return a ComplexNum which is rotated clockwise the complex number with a given angle(in degree)
rotate_counterclockwise_d(degree); //Return a ComplexNum which is rotated counterclockwise the complex number with a given angle(in degree)
rotate_clockwise_r(radian); //Return a ComplexNum which is rotated clockwise the complex number with a given angle(in radian)
rotate_counterclockwise_r(radian); //Return a ComplexNum which is rotated counterclockwise the complex number with a given angle(in radian)

add_magnitude(length); //Return a ComplexNum which is increased magnitude of complex number with a given length.

Overload the operator (=, +, -, *, /, ==, !=), reference lvalue and rvalue
Throw "division_by_zero" if the denominator is 0.
--------------------------------
In main, test above function.

--------------------------------
Win 10, C++ 14, Clion