#include <iostream>
#include <cmath>
#include <tuple>

std::tuple<double, double> solve_quadratic_equation(double a, double b, double c)
{
    double x1, x2;
    if (a == 0)
    {
        // Если коэффициент при x^2 равен нулю, то уравнение не является квадратным
        x1 = x2 = NAN;
    }
    else
    {
        double discriminant = b * b - 4 * a * c;

        if (discriminant > 0) {
            x1 = (-b + sqrt(discriminant)) / (2 * a);
            x2 = (-b - sqrt(discriminant)) / (2 * a);
        }
        else if (discriminant == 0)
        {
            x1 = x2 = -b / (2 * a);
        }
        else
        {
            // В случае, если дискриминант меньше нуля, уравнение не имеет решений
            x1 = x2 = NAN;
        }
    }

    return std::tuple<double, double>(x1, x2);
}

int main()
{
    double a, b, c;
    std::cout << "Inter a, b and c: ";
    std::cin >> a >> b >> c;

    auto solution = solve_quadratic_equation(a, b, c);

    if (std::isnan(std::get<0>(solution)) || std::isnan(std::get<1>(solution))) {
        std::cout << "No roots" << std::endl;
    }
    else {
        std::cout << "Roots: " << std::get<0>(solution) << " and " << std::get<1>(solution) << std::endl;
    }

    return 0;
}

