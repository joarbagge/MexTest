# Building

To compile the code, open a terminal in the directory containing
this file and do

```
cd build
cmake .. -DMatlab_ROOT_DIR="/path/to/MATLAB/R2020b"
make
```

replacing `/path/to/MATLAB/R2020b` by the path to your Matlab
installation. (Sometimes `cmake` can find Matlab itself and then
`cmake ..` is enough.)

# Running

Start Matlab in this directory, run `init` and then `mextest`.
