# Commands

The project can be run using the `run.sh` script. The script takes one argument, the path to the file to be run. The file should be in the `.arc` format used by Archetype.

```bash
bash run.sh file.arc
```

This script uses our Makefile to compile the compiler, run the compiler on `file.arc`, compile the resulting C++ code using `g++`, and run the resulting executable. Naturally, this must be executed from within the `codes/` directory.
