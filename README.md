## Comparative Execution Time

The kernel was run 30 times over 3 different vector sizes (2^20, 2^24, and 2^30). The average execution times for each version are as follows:

1. **C (Debug Mode)**:

| C Debug | Average Execution Time |
| --------- | --------- |
| total | 0.769444 seconds |

2. **C (Release Mode)**:

| C Release | Average Execution Time |
| --------- | --------- |
| total | 0.344733seconds |

3. **x86-64 Assembly**:
  
| x64 Release | Average Execution Time |
| --------- | --------- |
| total | 0.351978 seconds |

### Comparison

- **Comparison with C (Debug Mode)**: 
    - The x86-64 version was faster by 218% compared to the C version in debug mode.

- **Comparison with C (Release Mode)**: 
    - The x86-64 version was slower by around 3.1% compared to the C version in release mode.
 
## Screenshots of the Program
**1. Debug Version**
![Debug](/images/debug.png)
**2. Release Version**
![Release](/images/release.png)

- At the end of each iteration a validity checker is ran, which compares sdot computed by the C and x84-64 function. Variables `sdotC` and `sdot64` respectively. 
- If a mismatch is detected, boolean variable `noErrors` will be changed from it's default value of 1 to 0
  
![Checker func](/images/image.png)

- After all functions are executed, will print if test run is valid based on value of `noErrors`
  
![Validation func](/images/validation.png)
### Analysis
The assmebly time between the release version of the C kernel and x86-64 kernel is extremely minimal, compared to the debug version of the C Kernel where the assembly kernel runs over 2 times faster than the debug version. The reason for the release version running much faster than the debug version, even being a little bit faster than the assembly kernel, is because the release version optimizes the way the program is ran. In debug mode the compilation will not have optimization enabled, and when the program is running, it will step through each line; unlike in the release mode where the compiler will make optimizations to the way the code is ran, from reordering the execution of lines, different execution methods, and more.

The time of the assembly code does not get optimized further in either compilation configuration due to the fact that it is already equivalent to machine code, unlike the C programs which get translated into its machine code equivalent during compilation.
