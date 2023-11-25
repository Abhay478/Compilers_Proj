set -e

echo "Compiling compiler..."
make
echo "Converting test file $1 to C++..."
./a.out < $1
echo "Compiling C++ file to executable..."
g++ a.cpp -g -lgmp -o arc.out
echo "Running executable..."
./arc.out
