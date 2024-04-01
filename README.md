## Comparative Execution Time

The kernel was run 30 times over 3 different vector sizes (2^20, 2^24, and 2^30). The average execution times for each version are as follows:

1. **C (Debug Mode)**: 
    - Average Execution Time: 

| C Debug | Average Execution Time |
| --------- | --------- |
| total | 0.769444 seconds |

2. **C (Release Mode)**: 
    - Average Execution Time:

| C Release | Average Execution Time |
| --------- | --------- |
| total | 0.344733seconds |

3. **x86-64 Assembly**: 
    - Average Execution Time:
  
| x64 Release | Average Execution Time |
| --------- | --------- |
| total | 0.351978 seconds |

### Comparison

- **Comparison with C (Debug Mode)**: 
    - The x86-64 version was faster/slower by X% compared to the C version in debug mode.

- **Comparison with C (Release Mode)**: 
    - The x86-64 version was faster/slower by Y% compared to the C version in release mode.

### Analysis
