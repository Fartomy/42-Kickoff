#include "Bureaucrat.hpp"

int main( void )
{
    try
    {
        int i = 10;

        if (i > 11)
            cout << "xdxd" << endl;
        else
            throw(i);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}