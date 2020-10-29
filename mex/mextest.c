#include <mex.h>
#include <omp.h>

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    int sum = 0;
#ifdef _OPENMP
#pragma omp parallel
#endif
    {
        //int num = omp_get_thread_num();
#ifdef _OPENMP
#pragma omp for
#endif
        for (int i=0; i<16; i++)
        {
#ifdef _OPENMP
#pragma omp critical
#endif
            sum += i;
        }
    }
    printf("The sum is %d\n", sum);
}
