echo "Compiling compiler"
make
echo "Converting test file $1 to C++"
./a.out < $1
echo "Compiling C++ file to executable"
g++ a.cpp -lgmp
echo "Running executable"
./a.out
