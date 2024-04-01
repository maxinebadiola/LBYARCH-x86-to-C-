## Comparative Execution Time

The kernel was run 30 times over 3 different vector sizes (2^20, 2^24, and 2^30). The average execution times for each version are as follows:

1. **C (Debug Mode)**: 
    - Average Execution Time: 

| C Debug | Average Execution Time |
| --------- | --------- |
| n = 1048576 | 0.00310 seconds  |
| n = 16777216  | 0.04043 seconds  |
| n = 1073741824  | 2.59433 seconds  |
| total | 0.879289 seconds |

2. **C (Release Mode)**: 
    - Average Execution Time:

| C Release | Average Execution Time |
| --------- | --------- |
| n = 1048576 | 0.00147 seconds  |
| n = 16777216  | 0.01813 seconds  |
| n = 1073741824  | 1.06573 seconds  |
| total | 0.361778 seconds |

3. **x86-64 Assembly**: 
    - Average Execution Time:
  
| x64 Release | Average Execution Time |
| --------- | --------- |
| n = 1048576 | 0.00147 seconds  |
| n = 16777216  | 0.01813 seconds  |
| n = 1073741824  | 1.06573 seconds  |
| total | 0.369600 seconds |

### Comparison

- **Comparison with C (Debug Mode)**: 
    - The x86-64 version was faster/slower by X% compared to the C version in debug mode.

- **Comparison with C (Release Mode)**: 
    - The x86-64 version was faster/slower by Y% compared to the C version in release mode.

### Analysis
