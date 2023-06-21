# Templates
Templates are one of the key features of C++ programming language that allow users to write **generic codes** (blueprints) for functions, classes and other entities independent of data types. It is an approach to generic programming in C++ that allows users to pass data types as parameters so that a particular algorithm can work on multiple data types with a single set of codes. The data types passed as **parameters** to a class template or function template are called template parameters. Template parameters can be **data types**, **non data-types**, and template themselves as well.
## Working
Templates are **expanded** in compile time, meaning the definition and call of functions and classes in the program are detected during compilation such that same operation can be performed over diverse set of data through the same code.

At the very core, they work like macros except for a single significant difference. Unlike macros, the type checking in C++ templates is done before template expansion. This allows the compiled code to have multiple copies of the same class.
## Types of templates
There are three main types of templates in C++ namely:
* Function Templates: Useful to perform the same function for multiple data types. It is more efficient than function overloading where code needs to be re-written. 
* Class Templates: Class templates are used to generalize a class for multiple data types. The operation is similar to function templates.
## Syntax
Do define a function or class template, **template** keyword is used, followed by the **class** or **typename** keyword inside angular brackets. The class or typename are used to specify the data types on which the function or class performs operations.

Function Template example in C++:
```c++
template<typename T>
T greater(T a, T b){
    return (a > b)? a: b;
}

greater(2,5); //int data type, returns 5
greater(22.6,25.0); //float data type, returns 25.0
greater('q','p'); //char data type, returns q
```
Class Template example in C++
```c++
template <class Temp>
class Calculator
{
private:
        Temp n1, n2;
        
public:
        Calculator(Temp num1, Temp num2)
        {
                n1 = num1;
                n2 = num2;
        }
        Temp addition() { return (n1 + n2); }
        
        Temp subtraction() { return n1 - n2; }
        
        Temp multiplication() { return n1 * n2; }
        
        Temp division() { return n1 / n2; }
};
```
A template can have more than one parameter as well through comma separated typenames specified in the beginning.
```c++
template<class M1, class M2>
class A{
    private:
    M1 a;
    M2 b;
    public:
    A(M1 x, M2 y): a(x), b(y) {};
    void display();
};
void A<M1, M2>:: display(){
    std::cout<<"\n " a <<" "<< b; 
}

int main(){
    A<int, int> obj1(12,13);
    A<int, std::string> obj2(10, "Integer and string");
    A<char, char> obj3('c', 'd');
    obj1.display;
    obj2.display;
    obj3.display;
}
```
## Template Specialization
Once a template is defined, it can be re-defined for a particular data type as well. This enables specifying unique features while working with one particular data type.
```c++
template <typename Ttype>
void Example(Ttype t){
cout << "The standard example template: " << t << endl;
}
template<>
void Example<int>(int t){
cout << "Specialized example template for int: "<< t << endl;
}
```
During the compilation process, template definitions are processed by the compiler and used to generate code when the templates are **instantiated** with specific template arguments. When it encounters a template instantiation, it checks if there is a specialized implementation available for the given template arguments. If a specialization is found, the compiler uses the specialized code. Otherwise, it generates the code based on the generic template definition.
## Custom Matt Class
The current Matt class that is meant to replicate the functioning of cv::Mat class of OpenCV library can be implemented as a class template to ensure that various types of numbers (int, float, char, double) can be subjected to matrix operations like in the cv::Mat class.

