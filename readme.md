# commonmath 

developing common algebra for c++ langugae 

## Contribution
[GunHee Moon](mailto:ghmoon90@naver.com)

Graduated Inha Univ in 2012 <br>
Get M.S. degree at KAIST in 2014 <br>
Get Ph.D. degree at KAIST in 2019 <br>
Working at Hyundai Motor Company from 2019 as a GNC engineer <br>

## Purpose
to practice basic algebra function 
to develope basis math function set for matrix calculation 


## Dev. Env. Setting
#tool chain 
If you are using windows OS, any following option is available, 
cygwin, mingW, or any gcc compiler ([minGW](https://sourceforge.net/projects/mingw/), [Cygwin](https://cygwin.com/)), msys
or MS visual studio compiler ([VS comunity](https://visualstudio.microsoft.com/ko/vs/community/))

If you are using linux, (Ubuntu or CentOS) just use gcc compiler of the latest version. 


## User Manual 

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

	
	