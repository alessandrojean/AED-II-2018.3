# AED-II-2018.3
![Year][year] ![Id][id] ![T-P-I][tpi] ![Last class][last-class]
![Language][language] ![IDE][ide]

Algorithms written in the classes of Algorithms and Data
Structures II (Algoritmos e Estruturas de Dados II) at 
Federal University of ABC (UFABC).

[year]: https://img.shields.io/badge/year-2018.3-blue.svg?style=flat-square
[id]: https://img.shields.io/badge/id-MCTA002--13-yellowgreen.svg?style=flat-square
[tpi]: https://img.shields.io/badge/T--P--I-2--2--4-lightgrey.svg?style=flat-square
[last-class]: https://img.shields.io/badge/last_class-2018.11.30-green.svg?style=flat-square
[language]: https://img.shields.io/badge/language-C-yellow.svg?style=flat-square
[ide]: https://img.shields.io/badge/IDE-VSCode-orange.svg?style=flat-square

## Classes

- **19/09/2018** *(Theory)*: Hashing introduction.
- **21/09/2018** *(Laboratory)*: [Linear and Binary search].
- **26/09/2018** *(Theory)*: Hash table.
- **28/09/2018** *(Laboratory)*: [Hashing functions].
- **03/10/2018** *(Theory)*: Binary Search Tree.
- **05/10/2018** *(Laboratory)*: [Binary Search Tree].
- **10/10/2018** *(Theory)*: Adelson-Velsky and Landis Tree.
- **17/10/2018** *(Theory)*: Red-Black Tree.
- **19/10/2018** *(Laboratory)*: [Red-Black Tree].
- **24/10/2018** *(Theory)*: Red-Black Tree *(continuation)*.
- **26/10/2018** *(Laboratory)*: [Insertion in Red-Black Tree].
- **31/10/2018** *(Theory)*: **First test**.
- **07/11/2018** *(Theory)*: Trie.
- **09/11/2018** *(Laboratory)*: [Trie].
- **14/11/2018** *(Theory)*: B-tree.
- **21/11/2018** *(Theory)*: Union-Find.
- **23/11/2018** *(Laboratory)*: [B-tree].
- **28/11/2018** *(Theory)*: External Sorting.
- **30/11/2018** *(Laboratory)*: [External Sorting].

[Linear and Binary search]: classes/laboratory/2018.09.21/
[Hashing functions]: classes/laboratory/2018.09.28/
[Binary Search Tree]: classes/laboratory/2018.10.05/
[Red-Black Tree]: classes/laboratory/2018.10.19/
[Insertion in Red-Black Tree]: classes/laboratory/2018.10.26
[Trie]: classes/laboratory/2018.11.09/
[B-tree]: classes/laboratory/2018.11.23/
[External Sorting]: classes/laboratory/2018.11.30/

## Build instructions

Use the following commands to compile any `.c` file in this repository.

```bash
# Assuming you have the GNU C Compiler in
# your PATH, but can be MinGW or the Visual
# Studio compiler too if you are under an 
# Windows environment.

# Compiles the file in the bin folder.
$ gcc file.c -o bin/file
# If the compiler complain about the folder,
# create it using the command below, and
# run the command above again.
$ mkdir bin
# Run the program.
$ ./bin/file
```

If you use [Visual Studio Code](https://code.visualstudio.com), 
you can setup your envinroment using 
[tasks](https://code.visualstudio.com/docs/editor/tasks) 
and the Microsoft official 
[C/C++ extension](https://code.visualstudio.com/docs/languages/cpp), 
that allows you to debug and lint your code.

## License

    The MIT License (MIT)

    Copyright (c) 2018 Alessandro Jean

    Permission is hereby granted, free of charge, to any person obtaining a copy of
    this software and associated documentation files (the "Software"), to deal in
    the Software without restriction, including without limitation the rights to
    use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
    the Software, and to permit persons to whom the Software is furnished to do so,
    subject to the following conditions:
    
    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
    FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
    COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
    IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
    CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.