#include <cmath>
#include <iostream>
namespace ghmoon
{
    using std::printf;
    class matrix
    {
        // matrix
        private:
        double * elm; // element pointer
        int ncol; // number of dimension
        int nrow; // number of total element = muliple of size

        public:
        // method
        matrix()
        {
            elm = NULL;
            ncol = 0;
            nrow = 0;
        }

        ~matrix()
        {
            delete elm;
            ncol = 0;
            nrow = 0;
        }

        matrix(double *elm, int nrow, int ncol)
        {
            this->ncol = ncol;
            this->nrow = nrow;
            this->elm = new double [this->nrow * this->ncol];
            for( int k = 0 ; k < this->nrow * this->ncol ; k++ )
            {
                this->elm[k] = elm[k];
            }
        }


        void print_mat(void )
        {
            for( int i = 0 ; i < this->nrow ; i++ )
            {
                for( int j = 0 ; j < this->ncol ; j++ )
                {
                    printf("%f",this->elm[i*this->ncol + j]);
                    printf("\t");
                }
                printf("\n");
            }
        }

        void set(double *val, int nrow, int ncol)
        {
            delete elm;
            this->ncol = ncol;
            this->nrow = nrow;            
            this->elm = new double [this->nrow * this->ncol];
            for( int k = 0 ; k < this->nrow * this->ncol ; k++)
            {
                this->elm[k] = val[k];
            }
           
        }

        void set(double val,int row, int col)
        {
            this->elm[ row * this->ncol + col ] = val ;
            
        }

        double get(int row, int col)
        {
            return this->elm[ (row-1)*this->ncol + (col-1) ];

        }  

    };
}

int main()
{
    ghmoon::matrix a, b;
    double arr[4] = {2 , 3 , 4 , 5};
    a.set(arr,4,1);
    b.set(arr,2,2);
    return 1;
}