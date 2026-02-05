# Big Integer

The file **BigInteger.cpp** has implementation of the **BigInteger** Data Structure with help of **List** ADT.

## Files In The Repository

1. List.cpp
2. List.h
3. ListTest.cpp
4. BigInteger.cpp
5. BigInteger.h
6. BigIntegerTest.cpp
7. Arithmetic.cpp
8. README.md
9. Makefile

# Make commands
```
$ make clean
```
This command will make the repository clean by deleting the object file and executable file of **ListTest.cpp**, **Arthimetic.cpp**,**BigInteger.cpp**, **BigIntegerTest.cpp** and **List.cpp**.


```
$ make
```

This command will just compile other C files and make the executable and object file for **ListTest.cpp**, **BitIntegerTest.cpp** and **Arithmetic.cpp**.

# Running the program

```
$ make
```

1. This command will just compile other C files and make the executable and object file for **ListTest.cpp**, **BitIntegerTest.cpp** and **Arithmetic.cpp**.

```
$ ./ListTest
```

2. This command will run the ListTest file and show the output of List ADT functions.

```
$ ./BigIntegerTest
```

3. This command will run the BigIntegerTest file and show the output of BigInteger ADT functions.

```
$ ./Arithmetic in out
```

4. This command will run Arithmetic.cpp and it takes **2** arguments i.e. input file (default:in) and output file (out).


# Memory Leak Check

1. Run the make command

```
$ make
```

2. Run the following command to check the memory leaks in ListTest file.

```
$ make checkList
```

3. Run the following command to check the memory leaks in BigIntegerTest File.

```
$ make checkInteger
```

4. Run the following command to check memory leaks in Arithmetic File.

```
$ make checkMath
```

# Other Commands

1. To clean the **.txt** files.

```
$ make cleanText
```

2. To clean the **backup** directory.

```
$ make cleandir
```
