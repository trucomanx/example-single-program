/** \example example_matrix_dsp.cpp
 *  \brief Programa para el testeo de las funciones.
    
Para executar o programa:
\code{.sh}
    ./example_matrix_dsp
\endcode  
 *
 * Código example_matrix_dsp.cpp:
 */
    
#include <Pds/Ra>
#include "extras.hpp"
    
int main(void)
{
    Pds::Matrix Ans;
    
    Pds::Matrix A( "-2 -1  2\n"
                   "-1  2 -1\n"
                   " 1  0  1");
    A.Print("A:\n");
    
    Pds::Matrix B(3,3);
    B.Fill(suma(1,2));
    B.Print("B:\n");
    
    (A+B).Print("A+B:\n");
    
    return 0;
}
