#include <iostream>
#include <iomanip>
#include "mpir.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <fstream>

using namespace std;

const int MAX_ITERATIONS = 6;
const int PLACES         = 1000;        // desired decimal places
const int PRECISION      = PLACES + 1;  // +1 for the digit 3 before the decimal

const int BASE       = 10;  // base 10 numbers
const int BIT_COUNT  = 8;   // bits per machine word

const int BLOCK_SIZE = 10;                // print digits in blocks
const int LINE_SIZE  = 100;               // digits to print per line
const int LINE_COUNT = PLACES/LINE_SIZE;  // lines to print
const int GROUP_SIZE = 5;                 // line grouping size

/***** Function declarations here. *****/
void print(const mpf_t& pi);

/**
 * The main.
 * Set constants, initialize variables, and iterate
 * to compute pi to the desired number of decimal places.
 */
int main()
{
    mpf_set_default_prec(BIT_COUNT*PRECISION);  // precision in bits
    
    mpf_t ai,yi,a,b,y,ya,pi,c,g,j,d;
    mpf_inits(ai,yi,a,b,y,ya,pi,c,g,j,d);
    
    /***** Complete this program. *****/
    
    ///set the initial a0 and y0
    mpf_init_set_ui (a, 6);  ///a=6
    mpf_sqrt_ui(ai,2); ///ai=sqrt(2)
    mpf_mul_ui(ai,ai,4);//ai=4*sqrt(2)
    mpf_sub(ai,a,ai);//ai=6-4*sqrt(2)
    mpf_sqrt_ui(yi,2);//yi=sqrt(2)
    mpf_sub_ui(yi,yi,1);//yi=sqrt(2)-1
    
    // Loop MAX_ITERATIONS times
    for (int i = 1; i <= MAX_ITERATIONS; i++)
    {
        
        mpf_pow_ui(y,yi,4);//y=yi^4
        mpf_ui_sub(y,1,y);//y=1-yi^4
        
        mpf_sqrt(y,y);
        mpf_sqrt(y,y);//y=(1-yi^4)^0.25
        
        mpf_ui_sub(ya,1,y);//ya=1-y
        mpf_add_ui(y,y,1);//y=1+y
        mpf_div(yi,ya,y);//yi=ya/y
        
        mpf_pow_ui(b,yi,2);//b=yi^2
        mpf_add_ui(c,yi,1);//c=yi+1
        mpf_add(b,b,c);//b=yi^2+yi+1
        mpf_mul(b,yi,b);//b=yi(yi^2+yi+1)
        mpf_set_ui(g,2*i+1);//g=2*i+1
        
        mpf_set_ui(j,2);
        mpf_pow_ui(j,j,mpf_get_ui(g));
        ///int s=pow(2,2*i+1);//s=2^(2i+1)
        ///cout<<s<<endl;
        mpf_mul(b,b,j);//b=(2^(2i+1))*yi(yi^2+yi+1)
        
        mpf_pow_ui(a,c,4);//a=(yi+1)^4
        mpf_mul(a,a,ai);///a=ai*(yi+1)^4
        mpf_sub(ai,a,b);
        
        
    }
    //compute pi and print 
    
    mpf_ui_div(pi,1,ai);///pi=1/ai
    print(pi);
    
    
    
    return 0;
}

/***** Function definitions. *****/
void print(const mpf_t& pi)
{
    ofstream output("out.txt",ofstream::out);
    if(!output.is_open())
    {
        cout<<"no";
     }
    mp_exp_t exp;
    char * pis =mpf_get_str(NULL,&exp,BASE,PRECISION,pi);
    int n=1;
    //print the "3."
    output<<pis[0]<<".";
    for(int f=0; f<2; f++)
    {
        if(f==1)
        {
            output<<"  ";
        }
        for (int v=0; v< GROUP_SIZE; v++)
        {
            for (int z=0;z<BLOCK_SIZE;z++)
            {
                for (int e=0;e<10; e++)
                {
                    output<<pis[n];
                n++;
                }
                output<<" ";
            }
            output<<endl;
            output<<"  ";
        }
        output<<endl;
    }
    
    
    ///cout<<pis;
    output.close();
}
