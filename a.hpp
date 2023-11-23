struct two_tup {
    uint64_t val;
    uint64_t aux;
    two_tup operator+(const two_tup & other) const;
    two_tup operator-() const;
};

