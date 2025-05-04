#include <iostream>

using namespace std;

int main()
{
    //Lambda general form:
    //[](){}
    //[capture List] (parameters list) ->return value type {function body }

    //1. Define Lambda, give it a name and call it by name:
    auto func1 = [](){cout << "Hello World!" << endl;};
    func1();

    //2.Define Lambda, and call it by adding () after the function definition:
    [](){cout << " Hello lambda" << endl;}();

    //3.Define Lambda with parameters. Call directly and by function name:
    [](int a, int b){cout << "  The sum of a and b is " << a + b << endl;}(5, 2);
    auto func2 = [](int a, int b){cout << "  The sum of a and b is " << a + b << endl;};
    func2(6, 3);

    //4.Define Lambda with parameters and return value (two options shown):
    int sum = [](int a, int b)->int{return a + b;}(1, 2);
    cout << "    sum = " << sum << endl;
    cout << "     sum = " << [](int a, int b)->int{return a + b;}(11, 12) << endl;

    //5.Capture List. lets you access variables defined outside the scope of the Lambda
    int a = 8;
    int b = 1;
    [a , b]()
    {
        cout << " a is " << a << endl;
        cout << " b is " << b << endl;
    }();

    //6.capture by Value: The variable captured by Lambda Capture is different then original variable
    cout << endl << " Lambda Capture demonstration:" << endl;
    int c = 10; //original variable
    auto func3 = [c](){
        cout << "The inner captured value of c is " << c << endl;
    };
    for(int i = 0; i < 5; i++) {
        cout << "The outer value of c is " << c << endl;
        func3();
        c++;
    }

    //7.Capture by Reference: The reference of variable captured by Lambda Capture remains identical to original:
    cout << endl << " Lambda Capture by refernce demonstration:" << endl;
    int d = 10; //original variable
    auto func4 = [&d](){
        cout << "The inner captured value of c is " << d << endl;
    };
    for(int i = 0; i < 5; i++) {
        cout << "The outer value of c is " << d << endl;
        func4();
        d++;
    }

    //8.Capture Everything by Value:
    cout << endl << " Lambda Capture by refernce demonstration:" << endl;
    int e = 20; //original variable1
    int f = 20; //original variable2
    auto func5 = [=](){ //Capture all variables using "="
        cout << "The inner captured value of e is " << e << endl;
        cout << "The inner captured value of f is " << f << endl;
    };
    for(int i = 0; i < 5; i++) {
        cout << "The outer value of e is " << e << endl;
        cout << "The outer value of f is " << f << endl;
        func5();
        e++;
        f++;
    }

    //9.Capture Everything by Reference:
    cout << endl << " Lambda Capture by refernce demonstration:" << endl;
    int g = 30; //original variable1
    int h = 30; //original variable2
    auto func6 = [&](){ //Capture all variables using "="
        cout << "The inner captured value of g is " << g << endl;
        cout << "The inner captured value of h is " << h << endl;
    };
    for(int i = 0; i < 5; i++) {
        cout << "The outer value of g is " << g << endl;
        cout << "The outer value of h is " << h << endl;
        func6();
        g++;
        h++;
    }

    return 0;
}
