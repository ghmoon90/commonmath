# commonmath 

developing common algebra for c++ langugae 


# 1. Introduction 
    
The numcpp is legacy code for developing c++ class for linear algebra library. 


# 2. Relaese Note

- 2023.2.1. inital version 
- 2023.2.10. get, set function 
- 2023.2.12. clear function 
- 2023.2.13. add, substract, product, vec_dot, vec_cross function 



# 3. Contribution
[GunHee Moon](mailto:ghmoon90@naver.com)

Graduated Inha Univ in 2012 <br>
Get M.S. degree at KAIST in 2014 <br>
Get Ph.D. degree at KAIST in 2019 <br>
Working at Hyundai Motor Company from 2019 as a GNC engineer <br>

# 4. Purpose
to practice basic algebra function 
to develope basis math function set for matrix calculation 


# 5. Dev. Env. Setting
#tool chain 
If you are using windows OS, any following option is available, 
cygwin, mingW, or any gcc compiler ([minGW](https://sourceforge.net/projects/mingw/), [Cygwin](https://cygwin.com/)), msys
or MS visual studio compiler ([VS comunity](https://visualstudio.microsoft.com/ko/vs/community/))

If you are using linux, (Ubuntu or CentOS) just use gcc compiler of the latest version. 


# 6. User Manual 

## 6.1. matrix declearing 

``` c++ 
    cmf::matrix a;
    double arr[9] = {1, 2, 3, 4, 5,6,7,8,9};
    a.set(arr, 3,3 );
    a.print_mat();

    // swap element
    a.set(3.9, 2,2);
    a.print_mat();
```

## 6.2. matrix add, substract
``` c++ 
    cmf::matrix a,b,c;
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

## 6.3 matrix product
``` c++ 
    cmf::matrix a,b,c;
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
## 6.3 vector dot
``` c++ 
    cmf::matrix a,b;
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

    
## 6.6 Determinant 
``` c++
    cmf::matrix A, B, C;
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

## 6.4 matrix LU decomposition
    ``` c++ 
        matrix a,b,c;
        
    ```

## 6.5 matrix Chrolsky decomposition
    ``` c++ 
        matrix a,b,c;
        
    ```

    
## 6.6 inverse 
    ``` c++ 
        
    ```

## 6.6 matrix operator * 
``` c++

    // matrix product
    cmf::matrix a,b,c;
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

## 6.6 matrix operator + 
``` c++
    cmf::matrix a,b,c;
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


## 6.6 matrix operator + 
``` c++
    cmf::matrix a,b,c;
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


## 6.6 matrix operator == and != 
``` c++
    cmf::matrix a,b,c;
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
### run excutible
 use following excutible for simple calcuation. and Test.

### major function 
 1. [setting matrix](#a1_set)
 2. empty matrix and one matrix
 3. [matrix add](#a3_set)
 4. matrix substract 
 5. [matrix multiply](#a5_set)
 6. [cross product](#a6_set)
 7. dot product
 8. LU decomposition 
 8. matrix inversion 
 
	


### <a name="a1_set"> how to set a matrix  </a> 

dd

###  <a name="a3_set"> how to add two matrix </a> 


let's say matrix A in mxn and B in mxn are given as follows, respectively <br>
A= [a_ij] i in m, j in n <br>
B= [b_ij] i in m, j in n<br>
A+B = [a_ij + b_ij]<br>

```c
mat A, B , C;
A = B + C ;
```

###  <a name="a5_set"> how to do product of two matrices </a> 

let's say matrix A in lxm and B in mxn are given as follows, respectively <br>
A= [a_ij] i in l, j in m <br>
B= [b_jk] i in m, j in n<br> 

then 

A*B  = [ Sum (a_ij * b_jk) from j=1 to m ], i in l, k in n

Thus

```


```

###  <a name="a6_set"> how to do cross product of two 3x1 vector </a> 


let's say matrix A and B are 3x1 with three components as follows, respectively 

A = [a1, a2, a3]
B = [b1, b2, b3]

Then the output should be 

C = AxB = [a2b3 - a3b2 , -a1b3+a3b1, a1b2-a2b1] 

```c
mat A, B , C;
A = B + C ;
```

	
## Function Call

### cmf::matrix() constructor 

### cmf::~matrix() destructor

### cmf::matrix::matrix(double *elm, int nrow, int ncol)

| no |  type   | variable name | description |
|----|---------|---------------|------------|
| 1 | double * | elm |  matrix element data array |
| 2 | int | nrow |  number of rows|
| 3 | int | ncol | number of columns |

### cmf::add(matrix &dst_mat, matrix &A, matrix &B)
| no |  type   | variable name | description |
|----|---------|---------------|------------|
| 1 | matrix & | dst_mat |  output reference |
| 2 | matrix & | A | A matrix |
| 3 | matrix & | B | B matrix |

    dst_mat = A+ B

    
### cmf::substract(matrix &dst_mat, matrix &A, matrix &B)
| no |  type   | variable name | description |
|----|---------|---------------|------------|
| 1 | matrix & | dst_mat |  output reference |
| 2 | matrix & | A | A matrix |
| 3 | matrix & | B | B matrix |

    dst_mat = A- B

    
### double cmf::vdot(matrix &A, matrix &B)

| no |  type   | variable name | description |
|----|---------|---------------|------------|
| 0 | double | vector_dot |  output  |
| 1 | matrix & | A | 1 x m vector A |
| 2 | matrix & | B | 1 x m vector B |

    o = A dot B


### int cmf::vprod(matrix &dst_mat, matrix &A, matrix &B)

| no |  type   | variable name | description |
|----|---------|---------------|------------|
| 1 | matrix & | dst_mat |  output reference |
| 2 | matrix & | A | A matrix |
| 3 | matrix & | B | B matrix |

mathmatical representative \
    dst_mat = A x B