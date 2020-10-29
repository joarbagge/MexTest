#include <mex.h>
#include <omp.h>

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
#ifdef _OPENMP
#pragma omp parallel
#endif
    {
        int num = omp_get_thread_num();
#ifdef _OPENMP
#pragma omp for
#endif
        for (int i=0; i<16; i++)
        {
            printf("Thread %d, iter %d\n", num, i);
        }
    }
}
