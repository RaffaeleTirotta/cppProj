#include <iostream>

float func(float x){
    float y = x+2;

    return y;
}

int main(){
    
    // initialize target variable
    float err = 100;
    float niter;
    float c;
    //std::string func;

    //std::cout << "Enter the function you would like to find zeros for (enter in respect to x): y = \n";
    //std::cin >> func;


    //choose the method to solve for
    std::string method;

    std::cout << "Choose the method you want(Plese enter bisection, Newton or fixed point): ";

    do{
        std::cin >> method;
        if (method != "bisection" && method != "Newton" && method != "fixed point"){
            std::cout <<"Please enter a method among bisection, Newton or fixed point\n";
        }
    }
    while (method != "bisection" && method != "Newton" && method != "fixed point");

    //default values for iteration number and tollerance
    float toll = 1e-5;
    float iter = 100;
    //change default values if you want
    char tollChoice;

    std::cout << "Do you want to edit default values for tollearance (" << toll << ") and iterations (" << iter << ") ? (y/n)\n";
    do{
        std::cin >> tollChoice;
    }
    while (tollChoice != 'y' && tollChoice != 'n');

    if (tollChoice == 'y'){
        std::cout << "Please enter the desired number of iterations(default = " << iter <<"): \n";
        std::cin >> iter;
        std::cout << "Please enter the desired tollerance(default = " << toll <<"): \n";
        std::cin >> toll;
    }





    if (method=="bisection"){
        std::cout << "You chose the bisection method.\n";

    float a;
    float b;
    float f1;
    float f2;
    float f3;
    do{
        std::cout << "Please enter the first point of the interval, a = \n";
        std::cin >> a;

        std::cout << "Please enter the second point of the interval, b = \n";
        std::cin >> b;
        f1 = func(a);
        f2 = func(b);
        if (f1*f2 > 0){
            std::cout << "The evaluated function does not change sign in the desired interval\nPlease choose a better initial guess!\n";
        }
    }
    while (f1*f2 > 0);



        do{
            
            f1 = func(a);
            f2 = func(b);

            c = (a+b)/2;
            f3 = func(c);
            if (f1*f3 < 0){
                b = c;
            }
            else{
                a = c;
            };
            //absolute error
            if (f3>=0){
                err = f3;
            }
            else{
                err = -f3;
            }
            
            niter = niter + 1;
        }
        while (niter < iter && err > toll);
    }
    else if (method=="Newton"){
        std::cout << "Method not available yet\n";
    }
    else if (method=="fixed point"){
        std::cout << "Method not available yet\n";
    }

    



    // print output
    std::cout << "Iteration performed: " << niter << "\n";
    std::cout << "Error: " << err << "\n";
    std::cout << "The solution is x = "<< c << "\n";

    return 0;
}
