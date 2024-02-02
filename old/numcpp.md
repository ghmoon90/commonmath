<doc>
<title>numcpp document</title>

1. Introduction 
    
    The numcpp is legacy code for developing c++ class for linear algebra library. 


2. Relaese Note

    - 2023.2.1. inital version 
    - 2023.2.10. get, set function 
    - 2023.2.12. clear function 
    - 2023.2.13. add, substract, product, vec_dot, vec_cross function 


3. matrix Class

    3.1. Class member 변수

        - double *elm
        matrix element data array [1 by nrow * ncol].
        [0,0] to [0,ncolumn] and toward finaly [nrow, ncolumn]
        - int nrow
        the number of rows
        - int ncol
        the number of columns

    3.2. referencing cpp libraries

        - cmath


<table a> 

</table> 




4. Function Call

    4.1. ghmoon::matrix() constructor 

    4.2. ghmoon::~matrix() destructor

    4.3. ghmoon::matrix::matrix(double *elm, int nrow, int ncol)

    | no |  type   | variable name | description |
    |----|---------|---------------|------------|
    | 1 | double * | elm |  matrix element data array |
    | 2 | int | nrow |  number of rows|
    | 3 | int | ncol | number of columns |

    4.4 ghmoon::add(matrix &dst_mat, matrix &A, matrix &B)
    | no |  type   | variable name | description |
    |----|---------|---------------|------------|
    | 1 | matrix & | dst_mat |  output reference |
    | 2 | matrix & | A | A matrix |
    | 3 | matrix & | B | B matrix |

    dst_mat = A+ B

    
    4.4 ghmoon::substract(matrix &dst_mat, matrix &A, matrix &B)
    | no |  type   | variable name | description |
    |----|---------|---------------|------------|
    | 1 | matrix & | dst_mat |  output reference |
    | 2 | matrix & | A | A matrix |
    | 3 | matrix & | B | B matrix |

    dst_mat = A- B

    
    4.4 double ghmoon::vdot(matrix &A, matrix &B)
    | no |  type   | variable name | description |
    |----|---------|---------------|------------|
    | 0 | double | vector_dot |  output  |
    | 1 | matrix & | A | 1 x m vector A |
    | 2 | matrix & | B | 1 x m vector B |

    o = A dot B

    4.4 int ghmoon::vprod(matrix &dst_mat, matrix &A, matrix &B)
    | no |  type   | variable name | description |
    |----|---------|---------------|------------|
    | 1 | matrix & | dst_mat |  output reference |
    | 2 | matrix & | A | A matrix |
    | 3 | matrix & | B | B matrix |

    dst_mat = A x B





5. Operator Overloading


.


6. Usage 

    6.1. matrix declearing 

    ``` c++ 
        ghmoon::matrix a;
        double arr[9] = {1, 2, 3, 4, 5,6,7,8,9};
        a.set(arr, 3,3 );
        a.print_mat();

        // swap element
        a.set(3.9, 2,2);
        a.print_mat();
    ```

    6.2. matrix add, substract
    ``` c++ 
        ghmoon::matrix a,b,c;
        double arr[9] = {1, 2, 3, 4, 5,6,7,8,9};
        double arr2[9] = {2, 4,2, 5,3,6,3,2,5};
        a.set(arr, 3,3 );
        b.set(arr2,3,3);
        add(c,a,b); // c = a+b
        a.print_mat();
        b.print_mat();
        c.print_mat();

        substrct(c,a,b); // c = a-b
        c.print_mat();
    ```

    6.3 matrix product
    ``` c++ 
        ghmoon::matrix a,b,c;
        double arr[6] = {1, 2, 4, 5,6,9};
        double arr2[6] = {2, 4,6,3,2,5};
        a.set(arr, 2,3 );
        b.set(arr2,3,2);
        
        printf("a matrix \n");
        a.print_mat();
        printf("b matrix \n");
        b.print_mat();

        matprod(c,a,b); // c = ab

        printf("c = ab \n");
        c.print_mat();

        matprod(c,b,a); // c = ba
        printf("c = ba \n");
        c.print_mat();

        return 1;
    ```
    6.3 vector dot
    ``` c++ 
        ghmoon::matrix a,b;
        double arr[6] = {1, 2, 4, 5,6,9};
        double arr2[6] = {2, 4,6,3,2,5};
        a.set(arr, 6,1 );
        b.set(arr2,6,1);
        double c = 0.0;
        printf("%f\n",c);
        c = vdot(a,b); // c = ab
        printf("a dot b = %f\n",c);

        c = vdot(b,a); // c = ba
        printf("b dot a = %f\n",c);


    ```

    
    6.6 Determinant 
    ``` c++
        ghmoon::matrix A, B, C;
        double arr[6] = {1, 2, 4, 5, 6, 4};
        double arr2[4] = {2, 4,2,5};
        double arr3[9] = {1,2,4, 5,6,1, 2,4,2};
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
    ```

    6.4 matrix LU decomposition
    ``` c++ 
        matrix a,b,c;
        
    ```

    6.5 matrix Chrolsky decomposition
    ``` c++ 
        matrix a,b,c;
        
    ```

    
    6.6 inverse 
    ``` c++ 
        
    ```

    6.6 matrix operator * 
    ``` c++

        // matrix product
        ghmoon::matrix a,b,c;
        double arr[4] = {1, 2, 4, 5};
        double arr2[4] = {2, 4,2,5};
        a.set(arr, 2,2 );
        b.set(arr2,2,2);
        
        printf("a matrix \n");
        a.print_mat();
        printf("b matrix \n");
        b.print_mat();

        c = a*b;

        printf("c = ab \n");
        c.print_mat();

        c = b * a;       
        printf("c = ba \n");
        c.print_mat();


        // double * matrix 
        c = 3 * a ;
        print ("c = 3.0 * a \n");
        c.print_mat();

        // matrix * double 
        c = a * 3;
        print ("c = a * 3.0  \n");
        c.print_mat();

        

    ```

    6.6 matrix operator + 
    ``` c++
        ghmoon::matrix a,b,c;
        double arr[6] = {1, 2, 4, 5, 6, 4};
        double arr2[4] = {2, 4,2,5};
        a.set(arr, 3,2 );
        b.set(arr2,2,2);        
        printf("a matrix \n");
        a.print_mat();
        
        printf("b matrix \n");
        b.print_mat();
        
        printf("Determinant A : %f \n",Det(a));

        printf("Determinant B : %f \n",Det(b));
    ```


    6.6 matrix operator + 
    ``` c++
        ghmoon::matrix a,b,c;
        double arr[4] = {1, 2, 4, 5};
        double arr2[4] = {2, 4,2,5};
        a.set(arr, 2,2 );
        b.set(arr2,2,2);        
        printf("a matrix \n");
        a.print_mat();
        printf("b matrix \n");
        b.print_mat();
        c = a;
        printf("c = a");
        c.print_mat();

        c = a +1 ;
        printf("c = a+1");
        c.print_mat();
        
        c = 101 + a ;
        printf("c = 101+a");
        c.print_mat();
    ```


    6.6 matrix operator == and != 
    ``` c++
        ghmoon::matrix a,b,c;
        double arr[4] = {1, 2, 4, 5};
        double arr2[4] = {2, 4,2,5};
        a.set(arr, 2,2 );
        b.set(arr2,2,2);
        
        printf("a matrix \n");
        a.print_mat();
        printf("b matrix \n");
        b.print_mat();

        c = a ;
        printf("c =a \n"); 
        c.print_mat(); 


        printf("c == a\n");
        if(c==a)
        {
            printf("Same as\n");

        }else
        {
            printf("Not Same\n");
        }

        printf("c == b\n");
        if(c==b)
        {
            printf("Same as\n");

        }else
        {
            printf("Not Same\n");
        }

        printf("c != b\n");
        if(c!=b)
        {
            printf("Not same\n");

        }else
        {
            printf("Same as\n");
        }
    ```


7. reference 


</doc>