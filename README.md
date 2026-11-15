# One-bit ALU

A C++ simulation of a one-bit arithmetic logic unit. It builds logic gates from NAND and combines two half adders into a full adder.

## Build and run

Use a C++17 compiler and CMake 3.16 or later.

## Operation modes

| M1 | M0 | Output |
| --- | --- | --- |
| 0 | 0 | `A AND B` |
| 0 | 1 | `A OR B` |
| 1 | 0 | Low bit of `A + B + CarryIn` |
| 1 | 1 | `NOT A` |

The table assumes both inputs are enabled. `ENA` and `ENB` can independently force their inputs to zero. The full adder computes `CarryOut` in every mode.

The demo prints the 16 combinations of `A`, `B`, and mode with both inputs enabled and `CarryIn = 0`. It also prints the NAND and OR truth tables. See [example output](examples/sample-output.txt).
