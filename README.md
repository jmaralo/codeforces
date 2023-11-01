# Codeforces problems

This repo holds the code for all the problems I have attempted to solve on [Codeforces](https://codeforces.com/). Some of them are accepted, others are not.

It also includes some utilities I made to streamline the problem solving process.

## Template

The file `template.cpp` holds my template for problems, feel free to copy and modify it as you like.

It is intended to work with problems where multiple test cases are presented in one run. The number of test cases are read from `stdin`. To disable this change the `TESTCASES` definition to `false`.

The actual solution to the problem goes into the `solution` function. The input parameter `tt` is the number of the test case currently running.

## Utilities

The `utils.sh` bash file holds two utilities to make the process faster and help me retain my sanity among all these folders.

It contains two functions: `new` and `check`. To load them just source the file as so:

```bash
source utils.sh
```

Usually these scripts require a `$PROBLEM_ID`. This is the number and letter of the problem in codeforces, for example for a problem with this URL: `https://codeforces.com/problemset/problem/1872/A`, the problem ID is `1872a`.

### new

Usage:

```bash
new $PROBLEM_ID
```

This prepares all the files for a standard problem. It creates a folder like this: `problem_number/problem_letter` and inside places the problem template with the name set to the problem name (`problem_letter.cpp`), a `in` file and an `out` file where the user is expected to place the example input and output. The structure looks something like this:

```text
/problem_number
    /problem_letter
        /problem_letter.cpp
        /in
        /out
```

### check

Usage:

```bash
check $PROBLEM_ID
```

This checks the problem against the example input and output provided in the `in` and `out` files respectively. To do this it first compiles the source file, then runs the output with the example input and dumps the result to a `tmp` file and in turn runs `diff` against the `out` and `tmp` file. If there are no differences the `tmp` file is deleted, otherwise it is keept so the user can check the actual output of the code.
