#include <cmath>
#include <iostream>

namespace ghmoon
{
    using std::printf;
    using std::cerr;
    using std::string;
    using std::endl;
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
            this->elm[ (row-1) * this->ncol + (col-1) ] = val ;
            
        }

        double get(int row, int col) const
        {
            return this->elm[ (row-1)*this->ncol + (col-1) ];

        }  

        double get(int kk) const
        {
            return this->elm[kk];
        }
        
        void set(double val, int kk)
        {
            this->elm[kk] = val;
        }


        int getnrow() const
        {
            return this->nrow;
        }

        int getncol() const
        {
            return this->ncol;
        }
        void setnrow(int nrow)
        {
            this->nrow = nrow;
        }

        void setncol(int ncol)
        {
            this->ncol = ncol;
        }
        void zeros(int size)
        {
            this->elm = new double [size];
            for(int k = 0 ; k<size; k++)
            {
                this->elm[k] = 0;
            }
        }
        

        void zeros(int nrow, int ncol)
        {
            this -> nrow = nrow;
            this -> ncol = ncol;
            int size = nrow * ncol;
            this->elm = new double [size];
            for(int k = 0 ; k<size; k++)
            {
                this->elm[k] = 0;
            }
        }

        int nsize() const
        {
            return this->nrow * this->ncol;
        }

        void clear() 
        {
            this->nrow =0;
            this->ncol = 0;
            delete this->elm;

        }

        void const_product(double val)
        {
            for( int k = 0 ; k < this->nrow * this->ncol ; k++)
            {
                this->elm[k] = val * this->elm[k] ;
            }
        }


        const matrix& operator=(const matrix &in)
        {

            if(this->elm != NULL)
            {
                this->clear();
            }
            
            this->ncol = in.ncol;
            this->nrow = in.nrow;
            this->elm = new double [this->ncol * this->nrow]; 
            
            for( int k = 0 ; k < this->nrow * this->ncol ; k++)
            {
                this->elm[k] = in.elm[k] ;
            }
            
            return *this;

        }        
        


        const matrix operator*(double val)
        {
            matrix out;
            out = *this;
                    
            for( int k = 0 ; k < out.nrow * out.ncol ; k++)
            {
                out.elm[k] = val * out.elm[k] ;
            }
            //temp.print_mat();
            return out;
        }

        const matrix operator+(double val)
        {
            matrix out;
            out = *this;

            for( int k = 0 ; k < out.nrow * out.ncol ; k++)
            {
                out.elm[k] = val + out.elm[k] ;
            }


            return out;                    

        }

        friend matrix operator+(double val , const matrix matB )
        {
            matrix out;
            out = matB;
            for( int k = 0 ; k < matB.nrow * matB.ncol ; k++)
            {
                out.elm[k] = val + matB.elm[k] ;
            }
            return out;
        }

        friend matrix operator-(double val , const matrix matB )
        {
            matrix out;
            out = matB;
            for( int k = 0 ; k < matB.nrow * matB.ncol ; k++)
            {
                out.elm[k] = val - matB.elm[k] ;
            }
            return out;
        }

        friend matrix operator*(double val , const matrix matB )
        {
            matrix out;
            out = matB;
            for( int k = 0 ; k < matB.nrow * matB.ncol ; k++)
            {
                out.elm[k] = val * matB.elm[k] ;
            }
            return out;
        }

        const matrix operator-(double val)
        {
            matrix out;
            out = *this;

            for( int k = 0 ; k < out.nrow * out.ncol ; k++)
            {
                out.elm[k] =  out.elm[k] -val;
            }
            return out;                    

        }

        const matrix operator/(double val)
        {
            matrix out;
            out = *this;

            for( int k = 0 ; k < out.nrow * out.ncol ; k++)
            {
                out.elm[k] =  out.elm[k] /val;
            }


            return out;                    

        }

        const matrix operator+(const matrix &in)
        {
            matrix out;
            out = *this;

            for( int k = 0 ; k < out.nrow * out.ncol ; k++)
            {
                out.elm[k] =  out.elm[k] + in.elm[k];
            }

            return out;                    

        }

        const matrix operator-(const matrix &in)
        {
            matrix out;
            out = *this;

            for( int k = 0 ; k < out.nrow * out.ncol ; k++)
            {
                out.elm[k] =  out.elm[k] - in.elm[k];
            }

            return out;                    

        }

        const bool operator==(const matrix &in)
        {
            matrix thismat;
            thismat = *this;

            for( int k = 0 ; k < thismat.nrow * thismat.ncol ; k++)
            {
                if(thismat.elm[k] != in.elm[k])
                {
                    return false;                    
                }
            }
            return true;

        }

        
        const bool operator!=(const matrix &in)
        {
            
            return ~((*this)==in);

        }

        /*********************************************************** 
        matrix product operation 
        proto type :  const matrix operator*(const matrix &in)
        *************************************************************/
        const matrix operator*(const matrix &in)
        {                   

            matrix dst;
            try    
            {   

                if((this->getncol() != in.nrow ) )
                {
                    throw string("column size of mat A should same as row size of mat B. \n");
                }
                int nrow = this->getnrow();
                int ncol = in.ncol;
                int npair = this->getncol();
                double buff = 0;

                dst.nrow = nrow;
                dst.ncol = ncol;
                dst.elm = new double [dst.nsize()];
                dst.zeros( dst.nsize() );

                for(int i = 0 ; i < nrow;i++ )
                {
                    for(int j = 0 ; j < ncol ; j++ )
                    {
                        buff = 0;
                        for(int k = 0 ; k<npair ; k++)
                        {
                            buff = buff + this->get( i+1 , k+1) * in.get( k+1, j+1 );
                        }
                        //printf("%f\n",buff);
                        dst.set( buff , i * ncol + j );
                    }
                }

                return dst;
            }
            catch( string & e  )       
            {            
                cerr << e << endl;
                return dst;
            }
            
        }

        /*
        int LUdecom(matrix & L , matrix & U)
        {
            matrix tempL, tempU;
            tempL.zeros( this->nsize() );
            tempU.zeros( this->nsize() );

            for(int ii = 0 ; ii < this->ncol ; ii ++ )
            {
                tempL.set(1.0,ii,ii);
            }

                        for(int ii = 0 ; ii < this->ncol ; ii ++ )
            {
                tempL.set(1.0,ii,ii);
            }
            
            
            L = tempL;
            U = tempU;

            return 1;

        }*/
       

    };

    /*********************************************************** 
    matrix add
    proto type :  int add(matrix &dst, matrix &matA, matrix &matB)
    *************************************************************/
    int add(matrix &dst, matrix &matA, matrix &matB)
    {
        try
        {   
            if((matA.getncol() != matB.getncol() ) || (matA.getnrow() != matB.getnrow() ) )
            {
                throw string("mat A and mat B are different size. \n");
            }
            int nrow = matA.getnrow();
            int ncol = matA.getncol();



            dst.clear();
            dst.setnrow(nrow);
            dst.setncol(ncol);
            dst.zeros(nrow * ncol);

            for(int k = 0 ; k < nrow*ncol;k++ )
            {
                dst.set(matA.get(k) + matB.get(k) , k);
            }

            return 1;
        }
        catch( string & e  )       
        {            
            cerr << e<< endl;
            return 0;
        }
        
        
    }
    /*********************************************************** 
    matrix substract
    proto type : int substract(matrix &dst, matrix &matA, matrix &matB)
    *************************************************************/
    int substract(matrix &dst, matrix &matA, matrix &matB)
    {
        try
        {   
            if((matA.getncol() != matB.getncol() ) || (matA.getnrow() != matB.getnrow() ) )
            {
                throw string("mat A and mat B are different size. \n");
            }
            int nrow = matA.getnrow();
            int ncol = matA.getncol();



            dst.clear();
            dst.setnrow(nrow);
            dst.setncol(ncol);
            dst.zeros(nrow * ncol);

            for(int k = 0 ; k < nrow*ncol;k++ )
            {
                dst.set(matA.get(k) - matB.get(k) , k);
            }

            return 1;
        }
        catch( string& e  )       
        {            
            cerr << e<<endl;
            return 0;
        }
        
        
    }

    /*********************************************************** 
    vector dot product 
    proto type : double vdot(matrix &matA, matrix &matB)
    *************************************************************/
    double vdot(matrix &matA, matrix &matB)
    {
        try
        {   
            if((matA.getncol() * matA.getnrow() != matB.getncol() *  matB.getnrow()) )
            {
                throw string("mat A and mat B are different size. \n");
            }else if(( matA.getncol() != 1 ) && ( matA.getnrow() != 1 ) && ( matB.getncol() != 1 ) &&( matB.getnrow() != 1 )   )
            {
                throw string("input should be 1 x m vector or m x 1 vector.");
            }
            int nrow = matA.getnrow();
            int ncol = matA.getncol();
            double dot_value = 0;

            for(int k = 0 ; k < nrow*ncol;k++ )
            {
                dot_value = dot_value + matA.get(k) * matB.get(k);
            }

            return dot_value;
        }
        catch( string& e  )       
        {            
            cerr << e<<endl;
            return 0;
        }
        
    }


    /*********************************************************** 
    vector cross product 
    proto type : int vcrossprod(matrix &dst, matrix &matA, matrix &matB)
    *************************************************************/

    int vcrossprod(matrix &dst, matrix &matA, matrix &matB)
    {
        try
        {   
            if((matA.getncol() != matB.getncol() ) || (matA.getnrow() != matB.getncol() ) )
            {
                throw string("mat A and mat B are different size. \n");
            }
            int nrow = matA.getnrow();
            int ncol = matA.getncol();



            dst.clear();
            dst.setnrow(nrow);
            dst.setncol(ncol);
            dst.zeros(nrow * ncol);

            for(int k = 0 ; k < nrow*ncol;k++ )
            {
                dst.set(matA.get(k) - matB.get(k) , k);
            }

            return 1;
        }
        catch( string& e  )       
        {            
            cerr << e<<endl;
            return 0;
        }
    }

    /*********************************************************** 
    matrix product 
    proto type : int matprod(matrix &dst, matrix &matA, matrix &matB)
    *************************************************************/

    int matprod(matrix &dst, matrix &matA, matrix &matB)
    {
        try
        {   
            if((matA.getncol() != matB.getnrow() ) )
            {
                throw string("column size of mat A should same as row size of mat B. \n");
            }
            int nrow = matA.getnrow();
            int ncol = matB.getncol();
            int npair = matA.getncol();
            double buff = 0;


            dst.clear();
            dst.setnrow(nrow);
            dst.setncol(ncol);
            dst.zeros(nrow * ncol);

            for(int i = 0 ; i < nrow;i++ )
            {
                for(int j = 0 ; j < ncol ; j++ )
                {
                    buff = 0;
                    for(int k = 0 ; k<npair ; k++)
                    {
                        //printf("%f\t %f\n",matA.get( i , k ) ,  matB.get( k , j ) );
                        //buff = buff + matA.get( i * npair + k) * matB.get( j + k *npair );
                        buff = buff + matA.get( i+1 , k+1) * matB.get( k+1, j+1 );
                    }
                    //printf("%f\n",buff);
                    dst.set( buff , i * ncol + j );
                }
            }

            return 1;
        }
        catch( string& e  )       
        {            
            cerr << e<<endl;
            return 0;
        }
        
    }

    /*
        Det ; matrix determinant function 
        ex) 
            d = Det(matA)
    */
    double Det(const matrix & in)
    {
        double D = 0;
        int ncol = in.getncol();
        int nrow = in.getnrow();

        try{
            if (nrow != ncol)
            {  
                throw string("error : determiniant is only defined for square matrix");
                return 0;
            }
            if( nrow == 2 )
            {
                return in.get(1,1)* in.get(2,2) - in.get(1,2) *in.get(2,1);
            }
            else {
                
                matrix submat;
                int n  = in.nsize();
                int subj = 0;
                int subi = 0;
                double temp=0;
                submat.zeros( (nrow - 1) , (ncol-1));

                for (int x = 0; x < nrow; x++) {
                    subi = 0;
                    for (int i = 1; i < nrow; i++) {
                        subj = 0;
                        for (int j = 0; j < ncol; j++) {
                            if (j == x)
                            {
                                continue;
                            }                             
                                temp = in.get(i+1,j+1);
                                submat.set(temp, subi+1,subj+1 );
                                //submat.print_mat();
                                //printf("\n");
                                subj++;
                            }
                        subi++;
                    }
                    D = D + (pow(-1, x) * in.get(1,x+1) * Det( submat ) );

                    //printf("%f",D);
                }
            }
            
        }
        catch(string &e)
        {
            cerr<< e<< endl;
            return 0;
        }


        return D;
    }

    /*
        eigen : eigen value return
        ex) 
            d = Det(matA)
    */
    int eigen(double & dst_lambda, const matrix &dst_nu, const matrix & in )
    {
        matrix temp = in;

        try{
            if( in.nrow( ) ~= in.ncol()){
                 throw string(" eigen valu is only defined for square matrix.; you maybe try singular value.");
            }


        }

        return 1;

    }

}

int main()
{
    ghmoon::matrix A, B, C;
    double arr[6] = {1, 2, 4, 5, 6, 4};
    double arr2[4] = {2, 4,2,5};
    double arr3[9] = {10,2,4, 5,6,1, 2,4,2};
    A.set(arr, 3,2 );
    B.set(arr2,2,2); 
    C.set(arr3,3,3);       
    printf("A matrix \n");
    A.print_mat();
    
    printf("B matrix \n");
    B.print_mat();
    
    printf("C matrix \n");
    C.print_mat();

    printf("Determinant A : %f \n",Det(A));

    printf("Determinant B : %f \n",Det(B));

    printf("Determinant C : %f \n",Det(C));


}

//g++ numcpp.cpp -o aa.exe
//./aa.exe