fn main(): i32 {
    let s: str = "abcdefgh";
    let c: char = s[3];
    s = s[4..6];
    print(s);
    print_c(c);
}
